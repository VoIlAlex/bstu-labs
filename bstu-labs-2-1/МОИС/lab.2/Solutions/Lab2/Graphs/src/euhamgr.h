#pragma once

#include "grtrav.h"
#include "graph.h"
#include "Path.h"

class EuHamGr
{
protected:
	Graph graph;
	Path pathE;
	Path cirE;
public:
	// Constructors
	EuHamGr();
	EuHamGr(const EuHamGr& obj);
	EuHamGr(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE);
	EuHamGr(const Graph& graph);
	~EuHamGr();

	// Is semi-Eulerian/semi-Hamiltonian
	virtual bool isSemi() = 0;
	// Is Eulerian/Hamiltonian
	virtual bool is() = 0;

	virtual void showCir() = 0;
	virtual void showPath() = 0;
};