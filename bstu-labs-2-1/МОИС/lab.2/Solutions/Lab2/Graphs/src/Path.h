#pragma once

#include "List\List.h"
#include "graph.h"

class Path
{
	List<Edge> path;
public:
	Path();
	Path(const Edge& initEdge);
	GraphResponse add(const Edge& nEdge);
	GraphEdgeWeight length();
	void viewPath();
	void removeEdge(const int id);
	GraphResponse changeEdge(const int id, double nWeight);
	Edge& operator[](const int id);
	Path& operator=(const Path& obj);
	friend Path operator+(const Path& p, const Edge& e);
	GraphNumberOfEdges numOfE() const;
};