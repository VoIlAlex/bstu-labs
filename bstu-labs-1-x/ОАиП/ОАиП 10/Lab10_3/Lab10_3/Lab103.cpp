#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;
const int notName = system("color f0");

int Fib2(int, int[]);

int main()
{
	int * arr = new int[20];
	arr[0] = arr[1] = 1;

	int * res = new int[5];
	for (int i = 0; i < 5; i++)
	{
		int num;
		cout << "\n Number: "; cin >> num;
		res[i] = Fib2(num, arr);
		cout << " Fib2: " << res[i] << endl;
	}
	cout << endl;
	system("pause");
    return 0;
}

int Fib2(int N, int arr[])
{
	if (N > 2)
	{
		Fib2(N - 1, arr);
		arr[N - 1] = arr[N - 2] + arr[N - 3];
	}
	return arr[N-1];
}