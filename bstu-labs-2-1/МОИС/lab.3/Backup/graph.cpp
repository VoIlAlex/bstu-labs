#include "stdafx.h"
#include "graph.h"
#include <iostream>
#include "common.h"
#include <limits> // for std::numeric_limits<T>::max()

Graph::Graph()
	: numOfVer(0), numOfE(0) {}
Graph::Graph(const Graph& obj)
	: numOfVer(obj.numOfVer), numOfE(obj.numOfE), deg(obj.deg), e(obj.e) {}
Graph::Graph(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE)
	: numOfVer(numOfVer), numOfE(numOfE), e(e)
{
		findDeg();
}
Graph::~Graph() {}
GraphNumberOfVertices Graph::getNumOfVer() const
{
	return numOfVer;
}
GraphNumberOfEdges Graph::getNumOfE() const
{
	return this->numOfE;
}
// get access to edge by id
Edge & Graph::operator[](const int id)
{
	try
	{
		if (id < 0) 
			throw 1;
		if (id >= this->numOfE)
			throw 2;
		return e.getAccess(id);
	}
	catch (int err)
	{
		std::cout << "Graph::operator[]\t\tError - " << err << std::endl;
		if (numOfE == 0)
		{
			std::cout << "Graph is empty!" << std::endl;
			exit(0);
		}
		if (err == 1)
			return e.getAccess(0);
		else if (err == 2)
			return e.getAccess(numOfE - 1);
	}
}
// numOfVer++
// return: numOfVer
GraphNumberOfVertices Graph::operator++()
{
	numOfVer++;
	return numOfVer;
}
Graph& Graph::operator=(const Graph& obj)
{
	numOfVer = obj.numOfVer;
	numOfE = obj.numOfE;
	deg = obj.deg;
	e = obj.e;
	return (*this);
}
void Graph::addE(const Edge& newEdge)
{
	e.push_back(newEdge);
}
GraphNumberOfVertices Graph::addVer()
{
	numOfVer++;
	findDeg();
	return numOfVer;
}
GraphNumberOfVertices Graph::addVer(const int num)
{
	if (num < 0)
	{
		std::cout << "Warning! Graph::addVer(int num): num < 0. Some edges will be deleted." << std::endl;
		if ((numOfVer + num) <= 0)
		{
			numOfVer = 0;
			numOfE = 0;
			deg = List<GraphVertexDegree>();
			e = List<Edge>();
			std::cout << "The graph is empty." << std::endl;
			return 0;
		}
		numOfVer += num;
		std::cout << "Deleted Edges: ";
		for (int i = 0; i < numOfE; i++)
			if (e[i].fVertex > numOfVer || e[i].secVertex > numOfVer)
			{
				std::cout << "(" << e[i].fVertex << ", " << e[i].secVertex << ") ";
				remE(i);
			}
		std::cout << std::endl;
		findDeg();
		return numOfVer;
	}
	numOfVer += num;
	findDeg();
	return numOfVer;
}
int Graph::remE(const GraphVertex a, const GraphVertex b)
{
	try
	{
		if (a < 1 || a > numOfVer)
			throw 1;
		if (b < 1 || b > numOfVer)
			throw 2;

		for (int i = 0; i < this->numOfE; i++)
			if ((this->e[i].fVertex == a && this->e[i].secVertex == b) ||
				(this->e[i].secVertex == a && this->e[i].fVertex == b))
			{
				e.remove(i);
				deg.getAccess(a - 1)--;
				deg.getAccess(b - 1)--;
				return 1;
			}
		// if there no such elements
		return 0;
	}
	catch (int e)
	{
		std::cout << "Graph::remE(int a, int b)\t\tError - " << e << std::endl;
		return -1;
	}
}
int Graph::remE(const int id)
{
	try
	{
		if (id < 0 || id >= numOfE)
			throw 1;

		// if there is only that element
		deg.getAccess(e[id].fVertex - 1)--;
		deg.getAccess(e[id].secVertex - 1)--;
		e.remove(id);
		return 1;

	}
	catch (int e)
	{
		std::cout << "Graph::remE(int id)\t\tError - " << e << std::endl;
		return -1;
	}

}
void Graph::findDeg()
{
	deg = List<GraphVertexDegree>();
	for (int i = 0; i < numOfVer; i++)
	{
		deg.push_back(0);
	}
	for (int i = 0; i < numOfE; i++)
	{
		deg.getAccess(e[i].fVertex - 1)++;
		deg.getAccess(e[i].secVertex - 1)++;
	}
}
GraphVertexDegree Graph::getDeg(const int id) const
{
	try
	{
		if (id < 0)
			throw 1;
		if (id > numOfVer)
			throw 2;
		return deg[id];
	}
	catch (int e)
	{
		std::cout << "Graph::deg()\t\tError - " << e << std::endl;
		return -1;
	}
}
GraphEdgeWeight Graph::weight(const GraphVertex a, const GraphVertex b) const
{
	try
	{
		if (a < 1)
			throw 1.1f;
		if (b < 1)
			throw 1.2f;
		if (a > numOfVer)
			throw 2.1f;
		if (b > numOfVer)
			throw 2.2f;
		if (a == b)
			return 0;
		for (unsigned int i = 0; i < e.size(); i++)
		{
			if ((e[i].fVertex == a && e[i].secVertex == b)
				|| (e[i].secVertex == a && e[i].fVertex == b))
			{
				return e[i].weight;
			}
		}
		return /*std::numeric_limits<short>::max();*/ 1000000; // !
	}
	catch (float e)
	{
		std::cout << "GraphEdgeWeight Graph::weight(const GraphVertex a, const GraphVertex b)\n"
			<< "Error - " << e << std::endl;
		system("pause");
		exit(1);
	}
}
//

Edge::Edge()
	: weight(1), fVertex(0), secVertex(0) {}
Edge::Edge(const GraphVertex a, const GraphVertex b)
	: weight(1), fVertex(a), secVertex(b) {}
Edge::Edge(const GraphVertex a, const GraphVertex b, const GraphEdgeWeight weight)
	: weight(weight), fVertex(a), secVertex(b) {}
Edge::Edge(const Edge& other)
	: weight(other.weight), fVertex(other.fVertex), secVertex(other.secVertex) {}

GraphVertex& Edge::operator[](const int id)
{
	if (id == 0)
		return fVertex;
	else if (id == 1)
		return secVertex;
	else
	{
		std::cout << "GraphVertex& Edge::operator[](const int id)\n"
			<< "Incorrect id!" << std::endl;
		system("pause");
		exit(0);
	}
}