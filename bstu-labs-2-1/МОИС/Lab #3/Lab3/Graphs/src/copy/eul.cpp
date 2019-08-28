#include "stdafx.h"
#include "eul.h"
#include <iostream>

Eul::Eul(const Graph& graph)
	: EuHamGr(graph)
{
	BreadthFirst bf(this->graph);
	if (is(bf))
	{
		find(bf, Eulerian::mode::circuit);
		pathE = cirE;
		return;
	}
	if (isSemi(bf))
		find(bf, Eulerian::mode::path);
}
Eul::Eul(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE)
	: EuHamGr(numOfVer, e, numOfE)
{
	BreadthFirst bf(this->graph);
	if (is(bf))
	{
		find(bf, Eulerian::mode::circuit);
		pathE = cirE;
	}
	if (isSemi(bf))
		find(bf, Eulerian::mode::path);
}
Eul::Eul(const Eul& obj)
	:EuHamGr(obj) {}
Eul::~Eul() {}

// is semi-Eulerian
bool Eul::isSemi()
{
	return pathE.numOfE();
}
bool Eul::isSemi(GrTrav tr)
{
	// checking if there is a eulerian path
	int numOfEven = 0, numOfOdd = 0;
	// finding a number of odd and even degrees
	for (int i = 0; i < graph.getNumOfVer(); i++)
		if (graph.getDeg(i) % 2)
			numOfOdd++;
		else
			numOfEven++;
	// if there aren't odd degrees
	// then eulerian path is equal to eulerian circuit
	if (numOfOdd == 0)
	{
		pathE = cirE;
		return true;
	}
	// if number of odd degrees don't equal 2 
	// then there is no eulerian path
	if (numOfOdd != 2)
	{
		return false;
	}
	if (tr.getConnComp() > 1)
	{
		return false;
	}
	return true;
}
bool Eul::is()
{
	return cirE.numOfE();
}
bool Eul::is(GrTrav tr)
{
	// checking if there is a eulerian circuit
	// if there is a odd degree of vertex then there is no eulerian circuit 
	for (int i = 0; i < this->graph.getNumOfVer(); i++)
	{
		if (this->graph.getDeg(i) % 2)
		{
			return false;
		}
	}
	if (tr.getConnComp() > 1)
	{
		return false;
	}
	return true;
}
void Eul::find(GrTrav bf, Eulerian::mode mode)
{
	int pathE_id = 0;
	int cirE_id = 0;
	// traversal graph
	const Graph trGraph_const = bf.getGraph();
	Graph& trGraph = bf.getGraph();
	bool * marked = new bool[trGraph.getNumOfE()];
	for (int i = 0; i < trGraph.getNumOfE(); i++)
		marked[i] = false;
	
	int initVer = 1;
	if(mode == Eulerian::mode::path)
		for (int i = 0; i < trGraph.getNumOfVer(); i++)
			if (trGraph.getDeg(i) % 2)
			{
				initVer = i + 1;
				break;
			}
	// current vertex
	int cur_ver = initVer;

	while (true)
	{
		// id of next vertex when number of connected component has not been changed during deleting of edge
		int next = -1;
		int e_id = -1;
		// id of next vertex when number of connected component has been changed during deleting of edge
		int bedNext = -1;
		int bedE_id = -1;

		// position in array of the edge
		int j;
		for (int i = 0; i < trGraph.getNumOfE(); i++)
		{
			if (marked[i] == true)
				continue;
			if (trGraph[i][0] == cur_ver || trGraph[i][1] == cur_ver)
			{
				
				//int j;
				if (trGraph[i][0] == cur_ver)
					j = 1;
				else
					j = 0;
				int tempConnComp = bf.getConnComp();
				trGraph.remE(i);
				bf.trav();
				if (bf.getConnComp() > tempConnComp)
				{
					trGraph = trGraph_const;
					bedNext = trGraph[i][j];
					bedE_id = i;
					bf.trav();
				}
				else if (bf.getConnComp() == tempConnComp)
				{
					trGraph = trGraph_const;
					next = trGraph[i][j];
					e_id = i;
					bf.trav();
					break;
				}
				//trGraph.addE(temp0, temp1);
			}
		}
		if (next == -1 && bedNext == -1)
			break;
		if (next != -1)
		{
			if (mode == Eulerian::mode::circuit)
			{
				this->cirE.add(trGraph[e_id]);
				cirE_id++;
			}
			else if (mode == Eulerian::mode::path)
			{
				pathE.add(trGraph[e_id]);
				pathE_id++;
			}
			marked[e_id] = true;
			cur_ver = next;
		}
		else if(bedNext != -1)
		{
			if (mode == Eulerian::mode::circuit)
			{
				this->cirE.add(trGraph[bedE_id]);
				cirE_id++;
			}
			else if (mode == Eulerian::mode::path)
			{
				this->pathE.add(trGraph[bedE_id]);
				pathE_id++;
			}
			marked[bedE_id] = true;
			cur_ver = bedNext;
		}
	}
}

void Eul::showCir()
{
	if (!is())
		return;
	std::cout << "Eularian circuit: " << std::endl;
	for (int i = 0; i < cirE.numOfE(); i++)
	{
		std::cout << cirE[i][0] << " -> ";
	}
	std::cout << cirE[cirE.numOfE() - 1][1] << std::endl;
}
void Eul::showPath()
{
	if (!isSemi())
		return;
	std::cout << "Eularian path: " << std::endl;
	for (int i = 0; i < pathE.numOfE(); i++)
		std::cout << pathE[i][0] << " -> ";
	std::cout << pathE[pathE.numOfE() - 1][1] << std::endl;
}