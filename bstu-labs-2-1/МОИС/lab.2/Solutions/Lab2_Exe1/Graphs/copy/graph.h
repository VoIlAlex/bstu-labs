// File:					graph.h
// Author:					Ilya Vouk
// Date of creation:		10/3/2018
// Date of modification:	10/11/2018
//
// Description: 
//

#pragma once

class Graph
{
	int numOfVer;
	int * deg;
	void findDeg();
	int ** e;
	int numOfE;
public:
	// constructors / destructor
	Graph();
	Graph(const Graph& obj);
	Graph(const int& numOfVer, int ** e, int numOfE);
	~Graph();
	
	// methods
	int getNumOfVer();
	int getNumOfE();
	void addE(int a, int b);
	int addVer();
	int addVer(int num);
	int remE(int a, int b);
	int remE(int id);

	int getDeg(const int id);

	// operator overloading
	// get access to edge by id
	int *& operator[](const int id);
	// numOfVer++
	// return: numOfVer
	int operator++();
	Graph operator=(const Graph& obj);
}; 