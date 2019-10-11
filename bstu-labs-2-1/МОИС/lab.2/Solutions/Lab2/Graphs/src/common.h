// File:					common.h
// Author:					Ilya Vouk
// Date of creation:		10/3/2018 
// Date of modification:	10/3/2018
//
// Description: This header file provides common tools for working with graphs
//

#pragma once
#include "graph.h"

/*// following function create adjacency matrix
int ** adjMatrix(const int &numOfVer, int **e, const int &numOfE, graphType gT = undirected); 

// following function create incidence matrix
int ** incMatrix(const int &numOfVer, int **e, const int &numOfE, graphType gT = undirected);
*/

// following function find degrees of vertices of graph
int * verDeg(int ** adjM, const int &numOfVer); 
int * verDeg(const int &numOfVer, int**e, const int &numOfE);

// following function create random directed graph out of given one
int ** toMakeDirGraph(int **e, const int &numOfE); 

// following function create random pseudograph out of given one
int ** toMakePsGraph(const int &numOfVer, int **e, const int &numOfE, int &numOfPsE);  

// following function enlarge the array 
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
	delete[] arr;
	size++;
	arr = new T[size];
	for (int i = 0; i < (size - 1); i++)
		arr[i] = arrCopy[i];
}
void enlArr(int **& arr, int & sizeI, int sizeJ);

namespace matrix
{
	enum graphType { directed = 0, undirected };
	enum outMode { num_num = 0, num_alph, alph_num, alph_alph };
	void outMatrix(int ** matrix, const int &numOfR, const int &numOfC, matrix::outMode m = matrix::outMode::num_num);

	// following function create adjacency matrix
	int ** adjMatrix(const int &numOfVer, int **e, const int &numOfE, graphType gT = undirected);

	// following function create incidence matrix
	int ** incMatrix(const int &numOfVer, int **e, const int &numOfE, graphType gT = undirected);

	// following function create adjacency matrix
	int ** adjMatrix(Graph graph, graphType gT = undirected);

	// following function create incidence matrix
	int ** incMatrix(Graph graph, graphType gT = undirected);

}