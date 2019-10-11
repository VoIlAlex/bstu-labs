// File:					graph.h
// Author:					Ilya Vouk
// Description: 
//

#pragma once

#include "List\List.h" // for List

#define GraphVertex unsigned int
#define GraphEdgeWeight double
#define GraphVertexDegree unsigned int
#define GraphNumberOfVertices unsigned int
#define GraphNumberOfEdges unsigned int

enum GraphResponse
{
	GRAPH_NOT_OK = 0,
	GRAPH_OK = 1
};

struct Edge
{
	GraphEdgeWeight weight;
	GraphVertex fVertex;
	GraphVertex secVertex;
	Edge();
	Edge(const GraphVertex a, const GraphVertex b);
	Edge(const Edge& other);
	Edge(const GraphVertex a, const GraphVertex b, const GraphEdgeWeight weight);
	GraphVertex& operator[](const int id);
};
class Graph
{
protected:
	GraphNumberOfVertices numOfVer;
	GraphNumberOfEdges numOfE;
	List<GraphVertexDegree> deg;
	List<Edge> e;
	void findDeg();
public:
	Graph();
	Graph(const Graph& obj);
	Graph(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE);
	~Graph();
	GraphNumberOfVertices getNumOfVer() const;
	GraphNumberOfEdges getNumOfE() const;
	void addE(const Edge& newEdge);
	void addE(const GraphVertex fVertex, const GraphVertex secVertex);
	GraphNumberOfVertices addVer();
	GraphNumberOfVertices addVer(const int num);
	int remE(const GraphVertex a, const GraphVertex b);
	int remE(const int id);
	GraphEdgeWeight weight(const GraphVertex a, const GraphVertex b) const;
	GraphVertexDegree getDeg(const int id) const;
	Edge & operator[](const int id);
	GraphNumberOfVertices operator++();
	Graph& operator=(const Graph& obj);
}; 