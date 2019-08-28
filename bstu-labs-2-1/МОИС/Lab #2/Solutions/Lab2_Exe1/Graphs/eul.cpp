#include "stdafx.h"
#include "eul.h"
#include <iostream>

Eul::Eul(const Graph& graph)
{
	this->graph = graph;
	// Path and circuit have the same number of edges as the graph
	// or have no edges at all
	this->numOfPathE = this->graph.getNumOfE();
	this->numOfCirE = this->graph.getNumOfE();
	this->pathE = new int*[this->numOfPathE];
	this->cirE = new int*[this->numOfCirE];
	for (int i = 0; i < this->graph.getNumOfE(); i++)
	{
		this->pathE[i] = new int[2];
		this->cirE[i] = new int[2];
	}
	BreadthFirst bf(this->graph);
	if (this->is(bf))
	{
		this->find(bf, Eulerian::mode::circuit);
		for (int i = 0; i < this->numOfPathE; i++)
			for (int j = 0; j < 2; j++)
				this->pathE[i][j] = this->cirE[i][j];
	}
	if (this->isSemi(bf))
		this->find(bf, Eulerian::mode::path);
}
Eul::Eul(int numOfVer, int** e, int numOfE)
{
	this->graph = *(new Graph(numOfVer, e, numOfE));
	BreadthFirst bf(this->graph);
	if (this->is(bf))
	{
		this->find(bf, Eulerian::mode::circuit);
		for (int i = 0; i < this->numOfPathE; i++)
			for (int j = 0; j < 2; j++)
				this->pathE[i][j] = this->cirE[i][j];
	}
	if (this->isSemi(bf))
		this->find(bf, Eulerian::mode::path);
}
Eul::Eul(const Eul& obj)
{
	this->numOfCirE = obj.numOfCirE;
	this->numOfPathE = obj.numOfPathE;
	this->cirE = new int*[this->numOfCirE];
	for (int i = 0; i < this->numOfCirE; i++)
		for (int j = 0; j < 2; j++)
			this->cirE[i][j] = obj.cirE[i][j];
	this->pathE = new int*[this->numOfPathE];
	for (int i = 0; i < this->numOfPathE; i++)
		for (int j = 0; j < 2; j++)
			this->pathE[i][j] = obj.pathE[i][j];
	this->graph = obj.graph;
}
Eul::~Eul() {}

// is semi-Eulerian
bool Eul::isSemi()
{
	return numOfPathE;
}
bool Eul::isSemi(GrTrav tr)
{
	// checking if there is a eulerian path
	int numOfEven = 0, numOfOdd = 0;
	// finding a number of odd and even degrees
	for (int i = 0; i < this->graph.getNumOfVer(); i++)
		if (this->graph.getDeg(i) % 2)
			numOfOdd++;
		else
			numOfEven++;
	// if there aren't odd degrees
	// then eulerian path is equal to eulerian circuit
	if (numOfOdd == 0)
	{
		this->pathE = new int*[this->numOfCirE];
		for (int i = 0; i < this->numOfCirE; i++)
		{
			this->pathE[i] = new int[2];
			this->pathE[i][0] = this->cirE[i][0];
			this->pathE[i][1] = this->cirE[i][1];
		}

		this->numOfPathE = this->numOfCirE;
		return true;
	}
	// if number of odd degrees don't equal 2 
	// then there is no eulerian path
	if (numOfOdd != 2)
	{
		this->pathE = NULL;
		this->numOfPathE = 0;
		return false;
	}
	if (tr.getConnComp() > 1)
	{
		this->cirE = NULL;
		this->numOfCirE = 0;
		return false;
	}
	return true;
}
bool Eul::is()
{
	return numOfCirE;
}
bool Eul::is(GrTrav tr)
{
	// checking if there is a eulerian circuit
	// if there is a odd degree of vertex then there is no eulerian circuit 
	for (int i = 0; i < this->graph.getNumOfVer(); i++)
	{
		if (this->graph.getDeg(i) % 2)
		{
			this->cirE = NULL;
			this->numOfCirE = 0;
			return false;
		}
	}
	if (tr.getConnComp() > 1)
	{
		this->cirE = NULL;
		this->numOfCirE = 0;
		return false;
	}
	return true;
}
void Eul::find(GrTrav bf, Eulerian::mode mode)
{
	int pathE_id = 0;
	int cirE_id = 0;
	// traversal graph
	Graph trGraph = bf.getGraph();
	bool * marked = new bool[trGraph.getNumOfE()];
	for (int i = 0; i < trGraph.getNumOfE(); i++)
		marked[i] = false;
	
	int initVer = 0;
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
		for (int i = 0; i < trGraph.getNumOfE(); i++)
		{
			if (marked[i] == true)
				continue;
			if (trGraph[i][0] == cur_ver || trGraph[i][1] == cur_ver)
			{
				// position in array of the edge
				int j;
				if (trGraph[i][0] == cur_ver)
					j = 1;
				else
					j = 0;
				int temp0 = trGraph[i][0];
				int temp1 = trGraph[i][1];
				int tempConnComp = bf.getConnComp();
				trGraph.remE(i);
				bf.trav();
				if (bf.getConnComp() > tempConnComp)
				{
					bedNext = trGraph[i][j];
					bedE_id = i;
				}
				else if (bf.getConnComp() == tempConnComp)
				{
					next = trGraph[i][j];
					e_id = i;
				}
				trGraph.addE(temp0, temp1);
				bf.trav();
			}
		}
		if (next == -1 && bedNext == -1)
			break;
		if (next != -1)
		{
			if (mode == Eulerian::mode::circuit)
			{
				this->cirE[cirE_id][0] = trGraph[e_id][0];
				this->cirE[cirE_id][1] = trGraph[e_id][1];
				cirE_id++;
			}
			else if (mode == Eulerian::mode::path)
			{
				this->pathE[cirE_id][0] = trGraph[e_id][0];
				this->pathE[cirE_id][1] = trGraph[e_id][1];
				pathE_id++;
			}
			marked[e_id] = true;
			cur_ver = next;
		}
		else if(bedNext != -1)
		{
			if (mode == Eulerian::mode::circuit)
			{
				this->cirE[cirE_id][0] = trGraph[bedE_id][0];
				this->cirE[cirE_id][1] = trGraph[bedE_id][1];
				cirE_id++;
			}
			else if (mode == Eulerian::mode::path)
			{
				this->pathE[cirE_id][0] = trGraph[bedE_id][0];
				this->pathE[cirE_id][1] = trGraph[bedE_id][1];
				pathE_id++;
			}
			marked[bedE_id] = true;
			cur_ver = bedNext;
		}
	}
}

void Eul::showCir()
{
	if (!this->is())
		return;
	std::cout << "Hamiltonian circuit: " << std::endl;
	for (int i = 0; i < this->numOfCirE; i++)
	{
		std::cout << this->cirE[i][0] << " -> ";
	}
	std::cout << this->cirE[this->numOfCirE - 1][1] << std::endl;
}
void Eul::showPath()
{
	if (!this->isSemi())
		return;
	std::cout << "Hamiltonian path: " << std::endl;
	for (int i = 0; i < this->numOfPathE; i++)
	{
		std::cout << this->pathE[i][0] << " -> ";
	}
	std::cout << this->pathE[this->numOfPathE - 1][1] << std::endl;
}