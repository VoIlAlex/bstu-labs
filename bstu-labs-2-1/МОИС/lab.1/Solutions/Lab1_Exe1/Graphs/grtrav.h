// File:					grtrav.h
// Author:					Ilya Vouk
// Date of creation:		10/4/2018 1:30 PM
// Date of modification:	10/4/2018
//
// This header provides tools for grapth traversal
// 

#pragma once

class GrTrav
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

