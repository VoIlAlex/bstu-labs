#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>

using namespace std;

void mergeSort(int*, int);

int main()
{
	int sizeOfA = 100;
	int *A = new int[sizeOfA];
	for (int i = 0; i < sizeOfA; i++)
		A[i] = rand() % 1000;

	mergeSort(A, sizeOfA);
	for (int i = 0; i < sizeOfA; i++)
	{	
		for (int j = 0;j < 10&&i < sizeOfA; j++, i++)
			cout << A[i] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}
void swap(int* a, int* b)
{
	int var = *a;
	*a = *b;
	*b = var;
}

void mergeSort(int* arr, int size)

{
	int firstSize = size / 2;
	if (firstSize == 1)
	{
		if (size == 3)
		{
			mergeSort(arr, 2);
			mergeSort(arr+1, 2);
			mergeSort(arr, 2);
		}
		if (arr[0] > arr[1])
			swap(&arr[0], &arr[1]);
		return;

	}
	mergeSort(arr, firstSize);
	mergeSort(arr + firstSize, firstSize);
	int *arrRes = new int[size];
	int i = 0, j = firstSize, z = 0;
	while (1)
	{
		if (i == firstSize && j == firstSize+firstSize)
			break;
		else if (i == firstSize)
		{
			arrRes[z] = arr[j];
			j++; z++;
			continue;
		}
		else if (j == firstSize+firstSize)
		{
			arrRes[z] = arr[i];
			i++; z++;
			continue;
		}
		else
		{
			if (arr[i] < arr[j])
			{
				arrRes[z] = arr[i];
				z++; i++;
				continue;
			}
			else
			{
				arrRes[z] = arr[j];
				z++; j++;
				continue;
			}
		}
	}
	for (int i = 0; i < firstSize+firstSize; i++)
		arr[i] = arrRes[i];
	int secondSize = size - firstSize;
	if (firstSize != secondSize)
	{
		mergeSort(arr + firstSize + 1, firstSize);
		mergeSort(arr + 1, firstSize);
		mergeSort(arr, firstSize);
	}
}