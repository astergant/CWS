#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "load.h"

int main(int argc, char *argv[])
{
	int choice = 0;
	srand(time(NULL));
	while (1)
	{
		printf("Choose library:\n1: Array\n2: Matrix\n3: Exit\n");
		do
		{
			printf("> ");
			fflush(stdin);
		}
		while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3);

		switch (choice)
		{
			case 1 : load_run("libArray.dll") ; break;
			case 2 : load_run("libMatrix.dll") ; break;
			case 3 : return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
