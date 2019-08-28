// File:					grtrav.h
// Author:					Ilya Vouk
// Date of creation:		10/4/2018 1:30 PM
// Date of modification:	10/4/2018
//
// This header provides tools for grapth traversal
// 

#pragma once

#include "graph.h"

// graph traversal
class GrTrav
{
protected:
	Graph graph;
	// number of connected component
	int numOfConnComp;
	Graph tree;
public:
	// Constructors / Destructor
	GrTrav();
	GrTrav(const GrTrav& obj);
	GrTrav(const Graph& gr);
	GrTrav(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE);
	~GrTrav();

	// Public methods
	Graph& getGraph();
	Graph getTree();
	int getConnComp();
	virtual void trav();
};
class DepthFirst : public GrTrav
{
public:
	DepthFirst(const Graph& gr);
	DepthFirst(const DepthFirst& obj);
	DepthFirst(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE);
	~DepthFirst();
	void trav() override;
};
class BreadthFirst : public GrTrav
{
public:
	BreadthFirst(const Graph& gr);
	BreadthFirst(const BreadthFirst& obj);
	BreadthFirst(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE);
	~BreadthFirst();
	void trav() override;
};

