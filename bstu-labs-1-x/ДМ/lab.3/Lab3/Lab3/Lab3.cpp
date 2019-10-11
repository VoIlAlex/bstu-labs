#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;
const int notName = system("color f0");

enum typeOfFunc {notFunction = 0, neither, injection, surjection, bijection};

typeOfFunc typeOfFunction(int[][2],int,int*,int,int*,int);
bool isFunc(int[][2], int, int*, int, int*, int);
bool isInjection(int[][2], int, int*, int, int*, int);
bool isSurjection(int[][2], int, int*, int, int*, int);

int main()
{
	int B[] = {1, 2, 3, 4};
	int C[] = {5, 6, 7, 8};
	int S[][2] = { {1,8},{2,6},{3,8},{4,6}};
	int sizeOfB = sizeof(B)/sizeof(*B);
	int sizeOfC = sizeof(C)/sizeof(*C);
	int sizeOfS = sizeof(S)/sizeof(*S);
	
	typeOfFunc type = typeOfFunction(S, sizeOfS, B, sizeOfB, C, sizeOfC);
	switch (type)
	{
	case notFunction:
		cout << "Not a function." << endl;
		break;
	case neither:
		cout << "Neither." << endl;
		break;
	case injection:
		cout << "Injection." << endl;
		break;
	case surjection:
		cout << "Surjection." << endl;
		break;
	case bijection:
		cout << "Bijection." << endl;
	default:
		break;
	}

	system("pause");
	return 0;
}

typeOfFunc typeOfFunction(int setOfRel[][2], int sizeOfSetOfRel, int* A, int sizeOfA, int* B, int sizeOfB)
{
	if (!isFunc(setOfRel, sizeOfSetOfRel, A, sizeOfA, B, sizeOfB))
		return notFunction;
	else if (isInjection(setOfRel, sizeOfSetOfRel, A, sizeOfA, B, sizeOfB) &&
		isSurjection(setOfRel, sizeOfSetOfRel, A, sizeOfA, B, sizeOfB))
		return bijection;
	else if (isInjection(setOfRel, sizeOfSetOfRel, A, sizeOfA, B, sizeOfB))
		return injection;
	else if (isSurjection(setOfRel, sizeOfSetOfRel, A, sizeOfA, B, sizeOfB))
		return surjection;
	else
		return neither;
}

bool isFunc(int setOfRel[][2], int sizeOfSetOfRel, int* A, int sizeOfA, int* B, int sizeOfB)
{
	for (int i = 0; i < sizeOfSetOfRel; i++)
		for (int j = 0; j < sizeOfSetOfRel; j++)
			if (i != j)
				if (setOfRel[i][0] == setOfRel[j][0])
					return false;
	for (int i = 0; i < sizeOfA; i++)
	{
		bool isInSetOfRel = false;
		for (int j = 0; j < sizeOfSetOfRel; j++)
			if (A[i] == setOfRel[j][0])
				isInSetOfRel = true;
		if (!isInSetOfRel)
			return false;
	}
	return true;
}

bool isInjection(int setOfRel[][2], int sizeOfSetOfRel, int* A, int sizeOfA, int* B, int sizeOfB)
{
	for (int i = 0; i < sizeOfB; i++)
	{
		int numOfRe = 0;
		for (int j = 0; j < sizeOfSetOfRel; j++)
			if (B[i] == setOfRel[j][1])
				numOfRe++;
		if (numOfRe > 1)
			return false;
	}
	return true;
}

bool isSurjection(int setOfRel[][2], int sizeOfSetOfRel, int* A, int sizeOfA, int* B, int sizeOfB)
{
	for (int i = 0; i < sizeOfB; i++)
	{
		int numOfRe = 0;
		for (int j = 0; j < sizeOfSetOfRel; j++)
			if (B[i] == setOfRel[j][1])
				numOfRe++;
		if (numOfRe == 0)
			return false;
	}
	return true;
}