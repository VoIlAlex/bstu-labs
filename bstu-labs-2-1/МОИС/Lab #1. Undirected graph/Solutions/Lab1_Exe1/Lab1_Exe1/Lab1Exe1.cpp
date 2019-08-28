// Lab1Exe1.cpp

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "graph.h"
#include <iomanip>
using namespace std;


enum outMode { num_num = 0, num_alph, alph_num, alph_alph };
void outMatrix(int ** matrix, const int &numOfR, const int &numOfC, outMode m = num_num); // output matrix

// grapth traversal 
/*class GrTrav
{
protected:
	// number of connected component
	int numOfConnComp;
	// edges of the tree
	int **e;
	// number of edges of the tree
	int numOfE;
public:
	GrTrav();
	~GrTrav();
	int ** getE(int& numOfE);
	int ** getE();
	int getNumOfE();
	int getConnComp();
};

class DepthFirst : public GrTrav
{
public:
	DepthFirst(const int &numOfVer, int **e, const int& numOfE);
	~DepthFirst();
};
class BreadthFirst : public GrTrav
{
public:
	BreadthFirst(const int &numOfVer, int **e, const int& numOfE);
	~BreadthFirst();
};
*/
int main()
{
	const int numOfE = 7; // number of edges
	const int numOfVer = 8; // number of vertices

	int eTemp[numOfE][2] = { { 1, 4 },{ 2, 4 },{ 2, 6 },{ 3, 6 },{ 4, 5 },{ 5, 6 },{ 7, 8 } };
	int **e = new int*[numOfE]; // edges
	for (int i = 0; i < numOfE; i++)
	{

		e[i] = new int[2];
		e[i][0] = eTemp[i][0];
		e[i][1] = eTemp[i][1];
	}

	int ** adjM = adjMatrix(numOfVer, e, numOfE);
	int ** incM = incMatrix(numOfVer, e, numOfE);
	cout << "Adjacency matrix: " << endl;
	outMatrix(adjM, numOfVer, numOfVer); cout << endl;
	cout << "Incidence matrix: " << endl;
	outMatrix(incM, numOfVer, numOfE, num_alph);

	DepthFirst dFTE(numOfVer, e, numOfE);
	BreadthFirst brFTE(numOfVer, e, numOfE);

	cout << "Number of connected components: " << dFTE.getConnComp() << "; " << brFTE.getConnComp() << endl;
	int ** eD = toMakeDirGraph(e, numOfE);
	int ** adjMD = adjMatrix(numOfVer, eD, numOfE, directed);
	int ** incMD = incMatrix(numOfVer, eD, numOfE, directed);
	cout << "Directed graph: " << endl;
	outMatrix(adjMD, numOfVer, numOfVer); cout << endl;
	outMatrix(incMD, numOfVer, numOfE, num_alph); cout << endl;

	 // edges of depth-first search tree
	int ** dAdjM = adjMatrix(numOfVer, dFTE.getE(), dFTE.getNumOfE());
	cout << "Depth-first tree adjacency matrix: " << endl;
	outMatrix(dAdjM, numOfVer, numOfVer); cout << endl;

	int ** brAdjM = adjMatrix(numOfVer, brFTE.getE(), brFTE.getNumOfE());
	cout << "Breadth-first tree adjacency matrix: " << endl;
	outMatrix(brAdjM, numOfVer, numOfVer); cout << endl;

	int numOfPsE; // number of edges of the pseudograph
	int **psE = toMakePsGraph(numOfVer, e, numOfE, numOfPsE);
	int ** adjMPs = adjMatrix(numOfVer, psE, numOfPsE);
	cout << "Pseudograph adjacency matrix: " << endl;
	outMatrix(adjMPs, numOfVer, numOfVer); cout << endl;

	system("pause");
	return 0;
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
	if (m == num_num || m == alph_num)
		for (int i = 0; i < numOfC; i++)
			cout << setw(cw) << i + 1 << setw(cw) << ' ';
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