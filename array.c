#include "function.h"

void print_array(int* a, unsigned int n)
{
	unsigned int i = 0;
	for (i; i < n; ++i)
	{
		printf(" a[%2u] = %-4d |", i, a[i]);
		if ((i + 1) % 5 == 0)
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
	unsigned int i = 0, size = 50;
	int M[size];

	for (i; i < size; ++i)
		M[i] = rand() % 101 - 50;

	printf("\nbefore:\n");
	print_array(M, size);

	quick_sort(M, size);

	printf("\nafter:\n");
	print_array(M, size);
}

