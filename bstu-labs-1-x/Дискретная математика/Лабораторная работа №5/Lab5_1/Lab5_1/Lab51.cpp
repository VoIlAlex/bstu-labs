#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>

using namespace std;

int showPermutations(int*, int, int, bool);
template<typename T>
void swap(T*, T*);

int main()
{
	const int sizeOfArr = 4;
	int arr[sizeOfArr];
	for (int i = 0; i < sizeOfArr; i++)
		arr[i] = i + 1;
	int numOfPermutations = showPermutations(arr, sizeOfArr, 0, 0);
	cout << "Num of permutations: " << numOfPermutations << endl;

	system("pause");
    return 0;
}

int showPermutations(int* arr, int size, int level, bool std)
{
	int numOfPermutations = 0;
	for (int i = level, j = level; j < size; j++)
	{
		swap(&arr[i], &arr[j]);
		if (!std||i!=j)
		{
			for (int x = 0; x < size; x++)
				cout << arr[x] << " ";
			cout << endl;
			numOfPermutations++;
		}
		if(level!=size-2)
			numOfPermutations += showPermutations(arr, size, level + 1, true);
		swap(&arr[i], &arr[j]);
	}
	return numOfPermutations;
}

template<typename T>
void swap(T* a, T* b)
{
	T var = *a;
	*a = *b;
	*b = var;
}
