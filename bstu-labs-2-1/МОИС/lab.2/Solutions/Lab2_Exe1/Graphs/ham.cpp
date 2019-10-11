#include "stdafx.h"
#include "ham.h"
#include "permut.h"
#include "common.h"



Ham::Ham(Graph graph)
{

	this->graph = graph;
	this->cirE = nullptr;
	this->pathE = nullptr;
	this->numOfCirE = 0;
	this->numOfPathE = 0;
	this->find();
}
Ham::Ham(int numOfVer, int** e, int numOfE)
{
	this->graph = *(new Graph(numOfVer, e, numOfE));
	this->cirE = nullptr;
	this->pathE = nullptr;
	this->numOfCirE = 0;
	this->numOfPathE = 0;
	this->find();
}
Ham::Ham(const Ham& obj)
{
	this->graph = obj.graph;
	this->numOfCirE = obj.numOfCirE;
	this->numOfPathE = obj.numOfPathE;
	for (int i = 0; i < this->numOfCirE; i++)
		for (int j = 0; j < 2; j++)
			this->cirE[i][j] = obj.cirE[i][j];
	for (int i = 0; i < this->numOfPathE; i++)
		for (int j = 0; j < 2; j++)
			this->pathE[i][j] = obj.pathE[i][j];
}
Ham::~Ham(){}

bool Ham::isSemi()
{
	return this->numOfPathE;
}
bool Ham::is()
{
	return this->numOfCirE;
}

void Ham::find()
{
	int size = this->graph.getNumOfVer();
	int * arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = i + 1;
	// potential path
	Permut<int> p(arr, size);
	
	for (int i = 0; i < p.number(size); i++)
	{
		delete[] arr;
		p.get(i, size, arr);

		if(this->cirE==nullptr)
			this->cir(arr);
		if(this->pathE==nullptr)
			this->path(arr);
	}
}

bool Ham::cir(int * ver)
{
	for (int v = 0; v < this->graph.getNumOfVer(); v++)
	{
		bool isEdge = false;
		for (int edge = 0; edge < this->graph.getNumOfE(); edge++)
		{
			if (graph[edge][0] == ver[v] && graph[edge][1] == ver[(v + 1) % this->graph.getNumOfVer()])
			{
				enlArr(this->cirE, this->numOfCirE, 2);
				this->cirE[this->numOfCirE - 1][0] = graph[edge][0];
				this->cirE[this->numOfCirE - 1][1] = graph[edge][1];
				/*enlArr(this->pathE, this->numOfPathE, 2);
				this->pathE[this->numOfPathE - 1][0] = graph[edge][0];
				this->pathE[this->numOfPathE - 1][1] = graph[edge][1];*/
				isEdge = true;
			}
			else if (graph[edge][1] == ver[v] && graph[edge][0] == ver[(v + 1) % this->graph.getNumOfVer()])
			{
				enlArr(this->cirE, this->numOfCirE, 2);
				this->cirE[this->numOfCirE - 1][0] = graph[edge][1];
				this->cirE[this->numOfCirE - 1][1] = graph[edge][0];
				/*enlArr(this->pathE, this->numOfPathE, 2);
				this->pathE[this->numOfPathE - 1][0] = graph[edge][1];
				this->pathE[this->numOfPathE - 1][1] = graph[edge][0];*/
				isEdge = true;
			}
		}
		if (!isEdge)
		{
			/*if (this->pathE != nullptr)
				delete[] this->pathE;
			this->pathE = nullptr;
			this->numOfPathE = 0;*/
			if (this->cirE != nullptr)
				delete[] this->cirE;
			this->cirE = nullptr;
			this->numOfCirE = 0;
			return false;
		}
	}
	return true;
}
bool Ham::path(int * ver)
{
	for (int v = 1; v < this->graph.getNumOfVer(); v++)
	{
		bool isEdge = false;
		for (int edge = 0; edge < this->graph.getNumOfE(); edge++)
		{
			if (graph[edge][0] == ver[v] && graph[edge][1] == ver[v - 1])
			{
				enlArr(this->pathE, this->numOfPathE, 2);
				this->pathE[this->numOfPathE - 1][0] = graph[edge][1];
				this->pathE[this->numOfPathE - 1][1] = graph[edge][0];
				isEdge = true;
			}
			else if (graph[edge][1] == ver[v] && graph[edge][0] == ver[v - 1])
			{
				enlArr(this->pathE, this->numOfPathE, 2);
				this->pathE[this->numOfPathE - 1][0] = graph[edge][0];
				this->pathE[this->numOfPathE - 1][1] = graph[edge][1];
				isEdge = true;
			}
		}
		if (!isEdge)
		{
			if (this->pathE != nullptr)
				delete[] this->pathE;
			this->pathE = nullptr;
			this->numOfPathE = 0;
			return false;
		}
	}
	return true;
}

void Ham::showCir()
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
void Ham::showPath()
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