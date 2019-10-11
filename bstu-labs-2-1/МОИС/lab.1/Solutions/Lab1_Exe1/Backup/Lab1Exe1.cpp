// Lab1Exe1.cpp

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stack> 
#include <ctime>  
#include <cstdlib> 
#include <iomanip>

using namespace std;

enum outMode { num_num = 0, num_alph, alph_num, alph_alph };
enum graphType { directed = 0, undirected };

int ** adjMatrix(const int &numOfVer, int e[][2], const int &numOfE, graphType gT = undirected); // adjacency matrix
int ** incMatrix(const int &numOfVer, int e[][2], const int &numOfE, graphType gT = undirected); // incidence matrix
void outMatrix(int ** matrix, const int &numOfR, const int &numOfC, outMode m = num_num); // output matrix
int * verDeg(int ** adjM, const int &numOfVer); // vertices degree
int numOfConnComp(const int &numOfVer, int e[][2], const int &numOfE); // connected componen
int ** makeDGraph(int e[][2], const int &numOfE); // directed random graph out of given one

int main()
{
	const int numOfE = 7; // number of edges
	const int numOfVer = 8; // number of vertices

	int e[numOfE][2] = {{1, 4}, {2, 4}, {2, 6}, {3, 6}, {4, 5}, {5, 6}, {7, 8}}; // edges
	int ** adjM = adjMatrix(numOfVer, e, numOfE);
	int ** incM = incMatrix(numOfVer, e, numOfE);
	outMatrix(adjM, numOfVer, numOfVer); cout << endl;
	outMatrix(incM, numOfVer, numOfE, num_alph);

	cout << "Number of connected components: " << numOfConnComp(numOfVer, e, numOfE) << endl;
	int ** eD = makeDGraph(e, numOfE);
	int ** adjMD = adjMatrix(numOfVer, e, numOfE, directed);
	int ** incMD = incMatrix(numOfVer, e, numOfE, directed);
	outMatrix(adjMD, numOfVer, numOfVer); cout << endl;
	outMatrix(incMD, numOfVer, numOfE, num_alph);


	system("pause");
	return 0;
}



int ** adjMatrix(const int &numOfVer, int e[][2], const int &numOfE, graphType gT)
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
				if (e[k][0] == i&&e[k][1] == j)
					adjMatrix[i - 1][j - 1]++;
				else if (e[k][0] == j&&e[k][1] == i)
					if(gT == undirected)
					adjMatrix[i - 1][j - 1]++;
					else if(gT == directed)
					adjMatrix[i - 1][j - 1]--;
			}
	/////////////////////////////////////////////
	return adjMatrix;
}

int ** incMatrix(const int &numOfVer, int e[][2], const int &numOfE, graphType gT)
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

void outMatrix(int ** matrix, const int &numOfR, const int &numOfC, outMode m)
{
	const int cw = 2; // width of column
	/////////////////////////////////////////////
	// column numbering /////////////////////////
	/////////////////////////////////////////////
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int sizeOfAlph = sizeof(alphabet) / sizeof(*alphabet);
	cout << setw(cw) << '#' << setw(cw) << ' ';
	if(m == num_num || m == alph_num)
		for (int i = 0; i < numOfC; i++)
			cout << setw(cw) << i+1 << setw(cw) << ' ';
	else
		for (int i = 0; i < numOfC; i++)
			cout << setw(cw) << alphabet[i] << setw(cw) << ' ';
	cout << endl << endl;
	/////////////////////////////////////////////
	/////////////////////////////////////////////
	/////////////////////////////////////////////
	for (int i = 0; i < numOfR; i++)
	{
		if (m == num_num || m == num_alph)
			cout << setw(cw) << i + 1 << setw(cw) << ' ';
		else
			cout << setw(cw) << alphabet[i] << setw(cw) << ' ';
		for (int j = 0; j < numOfC; j++)
			cout << setw(cw) << matrix[i][j] << setw(cw) << ' ';
		cout << endl;
	}
}

int * verDeg(int ** adjM, const int &numOfVer)
{
	int * degM = new int[numOfVer];
	for (int i = 0; i < numOfVer; i++)
	{
		int deg = 0;
		for (int j = 0; j < numOfVer; j++)
			if (adjM[i][j]) deg++;
		degM[i] = deg;
	}
	return degM;
}

int numOfConnComp(const int &numOfVer, int e[][2], const int &numOfE)
{
	int numOfConnComp = 0; // number of connected components

	/* marked vertices */
	bool * marked = new bool[numOfVer];
	for (int i = 0; i < numOfVer; i++) marked[i] = false;
	/**/
	stack <int> v; // picked vertices
	while (true)
	{
		/* picking first vertex */
		int cur = 0;
		for (int i = 0; i < numOfVer; i++)
			if (marked[i] == false)
			{
				cur = i + 1;
				break;
			}
		if (cur == 0) break; // if there is no available element then break
		v.push(cur);
		/**/
		while (!v.empty())
		{
			int nextVer = 0; // next vertex to consider
			for (int i = 0; i < numOfE; i++)
			{
				if (e[i][0] == v.top() || e[i][1] == v.top())
				{
					int elId; // id of potential element in the "e" array
					if (e[i][0] == v.top()) elId = 1;
					else if (e[i][1] == v.top()) elId = 0;
					/* Chacking for potential next vertex in the stack and in the marked vertex array */
					bool isSuitable = true; // is potential next vertex suit
					// is in the stack
					stack <int> v_copy = v;
					while (!v_copy.empty())
					{
						if (e[i][elId] == v_copy.top())
							isSuitable = false;
						v_copy.pop();
					}
					// is in the marked array
					if (marked[(e[i][elId] - 1)])
						isSuitable = false;
					/**/
					if (isSuitable)
					{
						nextVer = e[i][elId];
						break;
					}
				}
			}
			if (!nextVer) // if we don't have a vertex to consider
			{
				marked[(v.top() - 1)] = true;
				v.pop();
			}
			else v.push(nextVer);
		}
		numOfConnComp++;
	}
	
	return numOfConnComp;
}

int ** makeDGraph(int e[][2], const int &numOfE)
{
	int **newE = new int*[numOfE];
	for (int i = 0; i < numOfE; i++)
	{
		newE[i] = new int[2];
		newE[i][0] = e[i][0];
		newE[i][1] = e[i][0];
		srand(time(0));
		if (rand() % 2)
			swap(newE[i][0], newE[i][1]);
	}
	return newE;
}