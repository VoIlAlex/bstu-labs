#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;
const int notName = system("color f0");

int RemoveForInc(double*, int); 
void out(char*, double*, int);

int main()
{
	setlocale(LC_ALL, "rus");
	
	double A[] = {1.0, 3.2, 2.0, 8.5, 1.2};
	int sizeA = sizeof(A) / sizeof(*A);
	out("A", A, sizeA);

	double B[] = { 4.3, 3.21, 2.58, 15.56, 56.5, 45.5 };
	int sizeB = sizeof(B) / sizeof(*B);
	out("B", B, sizeB);
	

	double C[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 };
	int sizeC = sizeof(C) / sizeof(*C);
	out("C", C, sizeC);

	system("pause");
    return 0;
}

int RemoveForInc(double * A, int N)
{
	int i = 1;
	while (i < N)
	{
		if (A[i]<A[i - 1])
		{
			for (int j = i; j < (N - 1); j++)
				A[j] = A[j + 1];
			N--;
			continue;
		}
		i++;
	}
	return N;
}

void out(char* name, double*A, int sizeA)
{
	cout << name << " before: ";
	for (int i = 0; i < sizeA; i++)
	{
		cout << A[i] << ((i == (sizeA - 1)) ? "." : ", ");
	}
	cout << endl << "Size of " << name << " after: " << sizeA << "." << endl;
	cout << name << " after : ";
	sizeA = RemoveForInc(A, sizeA);
	for (int i = 0; i < sizeA; i++)
	{

		cout << A[i] << ((i<(sizeA - 1)) ? ", " : ".");
	}
	cout << endl << "Size of "<< name <<": " << sizeA << "." << endl << endl;
}
