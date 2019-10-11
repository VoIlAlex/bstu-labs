#include "stdafx.h"
#include "ham.h"
#include "permut.h"
#include "common.h"



Ham::Ham(const Graph& graph)
	: EuHamGr(graph)
{
	find();
}
Ham::Ham(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE)
	: EuHamGr(numOfVer, e, numOfE)
{
	find();
}
Ham::Ham(const Ham& obj)
	: EuHamGr(obj) {}
Ham::~Ham(){}

bool Ham::isSemi()
{
	return pathE.numOfE();
}
bool Ham::is()
{
	return cirE.numOfE();
}

void Ham::find()
{
	int size = graph.getNumOfVer();
	int * arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = i + 1;
	// potential path
	Permut<int> p(arr, size);
	
	for (int i = 0; i < p.number(size); i++)
	{
		delete[] arr;
		p.get(i, size, arr);

		if(cirE.numOfE() == 0)
			cir(arr);
		if(pathE.numOfE() == 0)
			path(arr);
	}
}

bool Ham::cir(int * ver)
{
	for (int v = 0; v < graph.getNumOfVer(); v++)
	{
		bool isEdge = false;
		for (int edge = 0; edge < this->graph.getNumOfE(); edge++)
		{
			if (graph[edge][0] == ver[v] && graph[edge][1] == ver[(v + 1) % this->graph.getNumOfVer()])
			{
				cirE.add(graph[edge]);
				isEdge = true;
			}
			else if (graph[edge][1] == ver[v] && graph[edge][0] == ver[(v + 1) % this->graph.getNumOfVer()])
			{
				cirE.add(graph[edge]);
				isEdge = true;
			}
		}
		if (!isEdge)
		{
			cirE = Path();
			return false;
		}
	}
	return true;
}
bool Ham::path(int * ver)
{
	for (int v = 1; v < graph.getNumOfVer(); v++)
	{
		bool isEdge = false;
		for (int edge = 0; edge < graph.getNumOfE(); edge++)
		{
			if (graph[edge][0] == ver[v] && graph[edge][1] == ver[v - 1])
			{
				pathE.add(graph[edge]);
				isEdge = true;
			}
			else if (graph[edge][1] == ver[v] && graph[edge][0] == ver[v - 1])
			{
				pathE.add(graph[edge]);
				isEdge = true;
			}
		}
		if (!isEdge)
		{
			pathE = Path();
			return false;
		}
	}
	return true;
}

void Ham::showCir()
{
	if (!is())
		return;
	std::cout << "Hamiltonian circuit: " << std::endl;
	for (int i = 0; i < cirE.numOfE(); i++)
	{
		std::cout << cirE[i][0] << " -> ";
	}
	std::cout << cirE[cirE.numOfE() - 1][1] << std::endl;
}
void Ham::showPath()
{
	if (!isSemi())
		return;
	std::cout << "Hamiltonian path: " << std::endl;
	for (int i = 0; i < pathE.numOfE(); i++)
	{
		std::cout << pathE[i][0] << " -> ";
	}
	std::cout << pathE[pathE.numOfE() - 1][1] << std::endl;
}