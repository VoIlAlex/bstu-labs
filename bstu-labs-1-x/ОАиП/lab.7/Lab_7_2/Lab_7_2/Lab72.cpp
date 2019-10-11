#include "stdafx.h"
#include <Windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	int m, n;
	
	m = rand() % 8 + 2;
	n = rand() % 8 + 2;
/* создание массива */
	int ** matrix = new int*[m];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
/* заполнение и выведение массива */
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 10 + 1;
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	int count = 0; // необходимое количество

	int i = 0, j = 0;
/* нахождение количества */
	while (i < m, j < n)
	{
		int error_i = 0, error_j = 0;

		if (i < m - 1) {
			for (int k = 0; k < m; k++)
				if ((matrix[i][j] == matrix[k][j]) && k != i)
					error_i = 1;
			if (!error_i) count++;
			i++;
		}
		if (j < n - 1) {
			for (int k = 0; k < n; k++)
				if ((matrix[i][j] == matrix[i][k]) && k != j)
					error_j = 1;
			if (!error_j) count++;
			j++;
		}
		if (i == m - 1 && j == n - 1) { i++; j++; }
	}

	printf("\n Answer - %d\n", count);


	system("pause");

    return 0;
}

