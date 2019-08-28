#include "stdafx.h"
#include <Windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	int N;
	printf("Wwedite N: ");
	scanf_s("%d", &N);
	int * arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		int arr_i_fl;
		printf("%d - ", i + 1);
		scanf_s("%d", &arr_i_fl);
		arr[i] = arr_i_fl;
	}

	int * arr_1 = new int[N];
	int * arr_2 = new int[N];

	for (int i = 0; i < N; i++)
	{
		arr_1[i] = arr[i];
		printf("arr_1 %d-y element - %d\n", i + 1, arr_1[i]);
	}

	printf("\n");

	for (int i = 0; i < N; i++)
	{
		int i_1 = N - 1 - i;
		arr_2[i] = arr[i_1];
		printf("arr_2 %d-y element - %d\n", i + 1, arr_2[i]);
	}

	system("pause");
	return 0;
}

