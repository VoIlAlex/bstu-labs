#pragma once

#include "grtrav.h"
#include "graph.h"

class EuHamGr
{
protected:
	Graph graph;

	// Eulerian/Hamiltonian path
	int ** pathE;
	int numOfPathE;
	//virtual void findPath(GrTrav) = 0;

	// Eulerian/Hamiltonian circuit
	int ** cirE;
	int numOfCirE;
	//virtual void findCir(GrTrav) = 0;
public:
	// Constructors
	EuHamGr();
	~EuHamGr();

	// Is semi-Eulerian/semi-Hamiltonian
	virtual bool isSemi() = 0;
	// Is Eulerian/Hamiltonian
	virtual bool is() = 0;
};