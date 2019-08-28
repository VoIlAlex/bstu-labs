#pragma once
#include "graph.h"
#include "List\List.h"
#include "Path.h"

class ShortestPathDijkstra
{
	Graph m_Graph;
	Path findShortestPath(const GraphVertex fVertex, const GraphVertex secVertex) const;
public:
	//ShortestPath(const wGraph&);
	ShortestPathDijkstra(const Graph&);
	~ShortestPathDijkstra();
	Path getShortestPath(const GraphVertex fVertex, const GraphVertex secVertex) const;
};
class ShortestPathFloydWarshall
{	
	Graph m_Graph;
	Path findShortestPath(const GraphVertex fVertex, const GraphVertex secVertex) const;
public:
	//ShortestPath(const wGraph&);
	ShortestPathFloydWarshall(const Graph&);
	~ShortestPathFloydWarshall();
	Path getShortestPath(const GraphVertex fVertex, const GraphVertex secVertex) const;
};