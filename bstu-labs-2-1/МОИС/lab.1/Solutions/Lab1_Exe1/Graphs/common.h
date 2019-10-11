// File:					common.h
// Author:					Ilya Vouk
// Date of creation:		10/3/2018 
// Date of modification:	10/3/2018
//
// Description: This header file provides common tools for working with graphs
//

#pragma once

enum graphType { directed = 0, undirected };

// following function create adjacency matrix
int ** adjMatrix(const int &numOfVer, int **e, const int &numOfE, graphType gT = undirected); 

// following function create incidence matrix
int ** incMatrix(const int &numOfVer, int **e, const int &numOfE, graphType gT = undirected);

// following function find degrees of vertices of graph
int * verDeg(int ** adjM, const int &numOfVer); 
int * verDeg(const int &numOfVer, int**e, const int &numOfE);

// following function create random directed graph out of given one
int ** toMakeDirGraph(int **e, const int &numOfE); 

// following function create random pseudograph out of given one
int ** toMakePsGraph(const int &numOfVer, int **e, const int &numOfE, int &numOfPsE);  

// following function enlarge the array 
template<typename T>
void enlArr(T *& arr, int & size);