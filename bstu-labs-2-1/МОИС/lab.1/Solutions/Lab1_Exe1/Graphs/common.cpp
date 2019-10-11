// File:					common.cpp
// Author:					Ilya Vouk
// Date of creation:		10/3/2018
// Date of modification:	10/3/2018

#include "stdafx.h"
#include "common.h"
#include <cstdlib>
#include <algorithm> 

int ** adjMatrix(const int &numOfVer, int **e, const int &numOfE, graphType gT)
{
	/////////////////////////////////////////////
	// adjacency matrix (numOfVer x numOfVer) ///
	// initialized by 0 in every posistion //////
	/////////////////////////////////////////////
	int ** adjMatrix = new int*[numOfVer];
	for (int i = 0; i < numOfVer; i++)
	{
		adjMatrix[i] = new int[numOfVer];
		for (int j = 0; j < numOfVer; j++)
			adjMatrix[i][j] = 0;
	}
	/////////////////////////////////////////////
	// filling //////////////////////////////////
	/////////////////////////////////////////////
	for (int i = 1; i <= numOfVer; i++)
		for (int j = 1; j <= numOfVer; j++)
			for (int k = 0; k < numOfE; k++)
			{
				if (e[k][0] == i && e[k][1] == j)
					adjMatrix[i - 1][j - 1]++;
				else if (e[k][0] == j && e[k][1] == i)
					if (gT == undirected)
						adjMatrix[i - 1][j - 1]++;
					else if (gT == directed)
						adjMatrix[i - 1][j - 1]--;
			}
	/////////////////////////////////////////////
	return adjMatrix;
}
int ** incMatrix(const int &numOfVer, int **e, const int &numOfE, graphType gT)
{
	/////////////////////////////////////////////
	// incidence matrix (numOfVer x numOfE) /////
	// initialized by 0 in every posistion //////
	/////////////////////////////////////////////
	int ** incMatrix = new int*[numOfVer];
	for (int i = 0; i < numOfVer; i++)
	{
		incMatrix[i] = new int[numOfE];
		for (int j = 0; j < numOfE; j++)
			incMatrix[i][j] = 0;
	}
	/////////////////////////////////////////////
	// filling //////////////////////////////////
	/////////////////////////////////////////////
	for (int i = 1; i <= numOfVer; i++)
		for (int j = 0; j < numOfE; j++)
			if (gT == undirected)
			{
				if (e[j][0] == i || e[j][1] == i)
					incMatrix[i - 1][j]++;
			}
			else if (gT == directed)
			{
				if (e[j][0] == i)
					incMatrix[i - 1][j]++;
				else if (e[j][1] == i)
					incMatrix[i - 1][j]--;
			}
	/////////////////////////////////////////////
	return incMatrix;
}
int * verDeg(int ** adjM, const int &numOfVer)
{
	int * degrees = new int[numOfVer];
	for (int i = 0; i < numOfVer; i++)
	{
		int deg = 0;
		for (int j = 0; j < numOfVer; j++)
			if (adjM[i][j]) deg++;
		degrees[i] = deg;
	}
	return degrees;
}
int * verDeg(const int &numOfVer, int**e, const int &numOfE)
{
	int * degrees = new int[numOfVer];
	for (int i = 0; i < numOfVer; i++)
		degrees[i] = 0;
	for (int i = 0; i < numOfE; i++)
	{
		degrees[e[i][0] - 1]++;
		degrees[e[i][1] - 1]++;
	}
	return degrees;
}
int ** toMakeDirGraph(int **e, const int &numOfE)
{
	int **newE = new int*[numOfE];
	for (int i = 0; i < numOfE; i++)
	{
		newE[i] = new int[2];
		newE[i][0] = e[i][0];
		newE[i][1] = e[i][1];
		if (rand() % 2 == 0)
			std::swap(newE[i][0], newE[i][1]);
	}
	return newE;
}
int ** toMakePsGraph(const int &numOfVer, int **e, const int &numOfE, int &numOfPsE)
{
	numOfPsE = numOfE; // number of edges of the pseudograph
	int **psE = new int*[numOfPsE];
	for (int i = 0; i < numOfPsE; i++)
	{
		psE[i] = new int[2];
		psE[i][0] = e[i][0];
		psE[i][1] = e[i][1];
	}
	for (int i = 0; i < numOfVer; i++)
	{
		for (int j = 0; j < numOfVer; j++)
		{
			if (!(rand() % 5))
			{
				enlArr(psE, numOfPsE);
				psE[numOfPsE - 1] = new int[2];
				psE[numOfPsE - 1][0] = i;
				psE[numOfPsE - 1][1] = j;
			}
		}
	}
	return psE;
}
template<typename T>
void enlArr(T *& arr, int & size)
{
	if (size == 0)
	{
		size = 1;
		arr = new T[size];
		return;
	}
	T* arrCopy = new T[size];
	for (int i = 0; i < size; i++)
		arrCopy[i] = arr[i];
	size++;
	arr = new T[size];
	for (int i = 0; i < (size - 1); i++)
		arr[i] = arrCopy[i];
}