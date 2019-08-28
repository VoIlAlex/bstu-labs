//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;
const int notName = system("color f0");

void print(int *A, int n, int i)
{
	if (n)
	{
		if (n & 1)
			cout << A[i] << " ";
		print(A, n >> 1, i + 1);
	}
}

bool is_num_in_arr(int num, int num_arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (num_arr[i] == num) return true;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "russian");

	int U[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int A[] = { 1, 2, 6, 9 };
	int B[] = { 2, 3, 5, 6, 7 };
	int C[] = { 2, 3, 5, 6, 8 };

	/** Boolean **/
	cout << "Boolean: \n";
	int r, size_A;
	size_A = sizeof(A) / sizeof(*A);
	r = 1 << size_A;
	for (int i = 0; i < r; i++)
	{
		print(A, i, 0);
		cout << "\n";
	}
	/*************/
	/** Union **/
	int size_B = sizeof(B) / sizeof(*B);
	cout << "\nUnion A and B:\n";

	bool A_finish = false, B_finish = false;
	for (int i = 0, j = 0; !A_finish || !B_finish; )
	{
		if (A_finish && !B_finish)
		{
			cout << B[j] << " ";
			if (j == size_B - 1) { B_finish = true; continue; }
			j++;
		}
		else if (B_finish && !A_finish)
		{
			cout << A[i] << " ";
			if (i == size_A - 1) { A_finish = true; continue; }
			i++;
		}
		else
		{
			if (A[i] < B[j])
			{
				cout << A[i] << " ";
				if (i == size_A - 1) { A_finish = true; continue; }
				i++;
			}
			else if (B[j] < A[i])
			{
				cout << B[j] << " ";
				if (j == size_B - 1) { B_finish = true; continue; }
				j++;
			}
			else
			{
				cout << A[i] << " ";
				if (i == size_A - 1) { A_finish = true; }
				else
					i++;
				if (j == size_B - 1) { B_finish = true; }
				else
					j++;
			}
		}
	}

	/******************/
	/** Cartesian product and power **/
	int A_B_power = size_A*size_B;
	cout << "\nCartesian product A and B: \n{";
	for (int i = 0; i < size_A; i++)
	{
		for (int j = 0; j < size_B; j++)
		{
			if (A[i] < B[j]) 
			{
				cout << "(" << A[i] << ", ";
				cout << B[j];
				cout << "), ";
			}
			else
			{
				cout << "(" << B[j] << ", ";
				cout << A[i];
				if (i == size_A - 1 && j == size_B - 1) { cout << ")}"; break; }
				cout << "), ";
			}
		}
		cout << endl;
	}
	cout << "\nPower = " << A_B_power << endl;
	/*********************************/
	/**Expression**/
	int size_C = sizeof(C) / sizeof(*C);
	cout << "\n(A or B) \\ C: \n";
	A_finish = false, B_finish = false;
	for (int i = 0, j = 0; !A_finish || !B_finish; )
	{
		if (!A_finish&&is_num_in_arr(A[i], C, size_C)) 
		{
			if (i == size_A - 1) { A_finish = true; continue; }
			i++;
			continue;
		}
		if (!B_finish&&is_num_in_arr(B[j], C, size_C))
		{
			if (j == size_B - 1) { B_finish = true; continue; }
			j++;
			continue;
		}
		if (A_finish && !B_finish)
		{
			cout << B[j] << " ";
			if (j == size_B - 1) { B_finish = true; continue; }
			j++;
		}
		else if (B_finish && !A_finish)
		{
			cout << A[i] << " ";
			if (i == size_A - 1) { A_finish = true; continue; }
			i++;
		}
		else
		{
			if (A[i] < B[j])
			{
				cout << A[i] << " ";
				if (i == size_A - 1) { A_finish = true; continue; }
				i++;
			}
			else if (B[j] < A[i])
			{
				cout << B[j] << " ";
				if (j == size_B - 1) { B_finish = true; continue; }
				j++;
			}
			else
			{
				cout << A[i] << " ";
				if (i == size_A - 1) { A_finish = true; }
				else
					i++;
				if (j == size_B - 1) { B_finish = true; }
				else
					j++;
			}
		}
	}
	/**************/
	cout << endl;
	system("pause");
    return 0;
}

