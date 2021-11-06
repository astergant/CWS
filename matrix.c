#include "function.h"

void print_matrix(int** a, unsigned int n, unsigned int m)
{
	unsigned int i, j;

	printf("|i \\ j|");
	for (j = 0; j < m; ++j)
		printf(" %3u |", j);
	printf("\n");
	printf("|_____|");
	for (j = 0; j < m; ++j)
		printf("_____|");
	printf("\n");

	for (i = 0; i < n; ++i)
	{
		printf("| %-3u |", i);
		for (j = 0; j < m; ++j)
			printf(" %3d |", a[i][j]);
		printf("\n");
	}
}

void quick_sort(int* a, unsigned int n)
{
	int mid = a[n / 2], temp;
	unsigned int first = 0, last = n - 1;

	do
	{
		while (a[first] > mid)
			first++;

		while (mid > a[last])
			last--;

		if (first <= last)
		{
			temp = a[first];
			a[first] = a[last];
			a[last] = temp;
			first++; last--;
		}
	}
	while (first < last);

	if (last > 0)
		quick_sort(a, last + 1);

	if (first < n - 1)
		quick_sort(a + first, n - first);
}

void function()
{
	unsigned int i, j, N = 6, M = 7;
	int** A = (int**)calloc(N, sizeof(int*));
	for (i = 0; i < N; ++i)
	{
		A[i] = (int*)calloc(M, sizeof(int));
		for (j = 0; j < M; ++j)
			A[i][j] = rand() % 101 - 50;
	}

	printf("\nbefore: \n");
	print_matrix(A, N, M);

	for (i = 0; i < N; ++i)
		quick_sort(A[i], M);

	printf("\nafter: \n");
	print_matrix(A, N, M);

	for (i = 0; i < N; ++i)
		free(A[i]);
	free(A);
}

