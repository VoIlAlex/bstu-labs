#include "ShortestPath.h"
#include <iostream>
#include "common.h"



ShortestPathDijkstra::ShortestPathDijkstra(const Graph& wg)
	: m_Graph(wg){}
ShortestPathDijkstra::~ShortestPathDijkstra()
{}

Path ShortestPathDijkstra::getShortestPath(const GraphVertex fVertex, const GraphVertex secVertex) const
{
	try
	{
		if (fVertex < 1)
			throw 1;
		if (fVertex >= m_Graph.getNumOfVer())
			throw 2;
		if (fVertex == secVertex)
			throw 3;
		return findShortestPath(fVertex, secVertex);
	}
	catch (int e)
	{
		return Path();
	}
}

Path ShortestPathDijkstra::findShortestPath(const GraphVertex fVertex, const GraphVertex secVertex) const
{
	const GraphNumberOfVertices numOfVer = m_Graph.getNumOfVer();
	// paths from first vertex to other vertices
	Path * paths = new Path[numOfVer];
	// path from first vertex to another is initially equal to infinity (1000 000 by default)
	for (unsigned int i = 1; i <= numOfVer; i++)
	{
		if (i == fVertex)
			continue;
		paths[i-1] = Edge(i, fVertex, m_Graph.weight(i, fVertex));
	}
	double * weights =	new double[numOfVer];
	for (unsigned int otherVertex = 1; otherVertex <= numOfVer; otherVertex++)
		weights[otherVertex - 1] = m_Graph.weight(fVertex, otherVertex);
	// vertices, for which we've already found a shortest path, are marked 
	bool * marked = new bool[numOfVer];
	// initialy we have only first vertex marked 
	for (unsigned int i = 0; i < numOfVer; i++)
		marked[i] = false;
	marked[fVertex - 1] = true;

	
	while (1)
	{
		// searching for vertex which is nearest to first vertex
		GraphVertex cur = 0;
		for (unsigned int i = 1; i <= numOfVer; i++)
		{
			if (marked[i - 1] == false)
			{
				cur = i;
				break;
			}
		}
		if (!cur)
			return Path();
		for (unsigned int i = 1; i <= numOfVer; i++)
		{
			if (fVertex == i)
				continue;
			if (weights[i - 1] < weights[cur - 1] && marked[i - 1] == false)
			{
				cur = i;
			}
		}
		// if nearest vertex is that one we need then we return its path
		if (cur == secVertex)
			return paths[secVertex - 1];
		// else we mark it
		marked[cur - 1] = true;
		// then we figure out minimal paths to the vertices using "cur" vertex
		for (unsigned int consideredVertex = 1; consideredVertex <= numOfVer; consideredVertex++)
		{
			if (marked[consideredVertex - 1] == true)
				continue;
			// if path through "cur" vertex is shorter that considered one 
			// then we set new path 
			if ((m_Graph.weight(cur, consideredVertex) + weights[cur - 1]) < weights[consideredVertex - 1])
			{
				weights[consideredVertex - 1] = m_Graph.weight(cur, consideredVertex) + weights[cur - 1];
				paths[consideredVertex - 1] = paths[cur - 1] + Edge(cur, consideredVertex, m_Graph.weight(cur, consideredVertex));
			}
		}
	}
	return Path();
}

ShortestPathFloydWarshall::ShortestPathFloydWarshall(const Graph& wg)
	: m_Graph(wg) {}
ShortestPathFloydWarshall::~ShortestPathFloydWarshall()
{}

Path ShortestPathFloydWarshall::getShortestPath(const GraphVertex fVertex, const GraphVertex secVertex) const
{
	try
	{
		if (fVertex < 1)
			throw 1;
		if (fVertex >= m_Graph.getNumOfVer())
			throw 2;
		if (fVertex == secVertex)
			throw 3;
		return findShortestPath(fVertex, secVertex);
	}
	catch (int e)
	{
		return Path();
	}
}

Path ShortestPathFloydWarshall::findShortestPath(const GraphVertex fVertex, const GraphVertex secVertex) const
{
	Path ** paths = new Path*[m_Graph.getNumOfVer()];
	for (int i = 0; i < m_Graph.getNumOfVer(); i++)
	{
		paths[i] = new Path[m_Graph.getNumOfVer()];
		for (int j = 0; j < m_Graph.getNumOfVer(); j++)
		{
			paths[i][j].add(Edge(i + 1, j + 1, m_Graph.weight(i + 1, j + 1)));
		}
	}

	for (int k = 0; k < m_Graph.getNumOfVer(); k++)
	{
		for (int i = 0; i < m_Graph.getNumOfVer(); i++)
		{
			for (int j = 0; j < m_Graph.getNumOfVer(); j++)
			{
				paths[i][j] = (paths[i][j].length() > (paths[i][k].length() + paths[k][j].length())) ? paths[i][k] + paths[k][j] : paths[i][j];
			}
		}
	}
	Path res = paths[fVertex - 1][secVertex - 1];
	for (int i = 0; i < m_Graph.getNumOfVer(); i++)
		delete[] paths[i];
	delete[] paths;
	return res;
}