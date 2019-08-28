#include "stdafx.h"
#include "graph.h"
#include <iostream>
#include "common.h"

Graph::Graph()
{
	this->deg = NULL;
	this->numOfVer = 0;
	this->numOfE = 0;
	this->e = NULL;
}
Graph::Graph(const Graph& obj)
{
	this->numOfVer = obj.numOfVer;
	this->numOfE = obj.numOfE;
	this->deg = new int[this->numOfVer];
	for (int i = 0; i < this->numOfVer; i++)
	{
		this->deg[i] = obj.deg[i];
	}
	this->e = new int*[this->numOfVer];
	for (int i = 0; i < this->numOfE; i++)
	{
		this->e[i] = new int[2];
		this->e[i][0] = obj.e[i][0];
		this->e[i][1] = obj.e[i][1];
	}
}
Graph::Graph(const int& numOfVer, int ** e, int numOfE)
{
	try
	{
		if (numOfVer < 0) 
			throw 1;
		this->numOfVer = numOfVer;
		if (numOfE < 0) 
			throw 2;
		this->numOfE = numOfE;
		this->e = new int*[this->numOfE];
		for (int i = 0; i < this->numOfE; i++)
		{
			this->e[i] = new int[2];
			this->e[i][0] = e[i][0];
			this->e[i][1] = e[i][1];
		}
		this->findDeg();
	} 
	catch (int e)
	{
		std::cout << "Graph::Graph()\t\tError - " << e << std::endl;
	}
}
Graph::~Graph()
{
	for (int i = 0; i < this->numOfE; i++)
	{
		delete[] this->e[i];
	}
	delete[] this->e;
}
int Graph::getNumOfVer()
{
	return this->numOfVer;
}
int Graph::getNumOfE()
{
	return this->numOfE;
}
// get access to edge by id
int *& Graph::operator[](const int id)
{
	try
	{
		if (id < 0) 
			throw 1;
		if (id >= this->numOfE)
			throw 2;
		return this->e[id];
	}
	catch (int e)
	{
		std::cout << "Graph::operator[]\t\tError - " << e << std::endl;
		if (e == 1)
			return this->e[0];
		else
			return this->e[this->numOfE - 1];
	}
}
// numOfVer++
// return: numOfVer
int Graph::operator++()
{
	this->numOfVer++;
	return numOfVer;
}
Graph Graph::operator=(const Graph& obj)
{
	this->numOfVer = obj.numOfVer;
	this->deg = new int[this->numOfVer];
	for (int i = 0; i < this->numOfVer; i++)
	{
		this->deg[i] = obj.deg[i];
	}
	if (this->numOfE != 0)
	{
		for (int i = 0; i < this->numOfE; i++)
			delete[] this->e[i];
		delete[] this->e;
	}
	this->numOfE = obj.numOfE;
	this->e = new int*[this->numOfVer];
	for (int i = 0; i < this->numOfE; i++)
	{
		this->e[i] = new int[2];
		this->e[i][0] = obj.e[i][0];
		this->e[i][1] = obj.e[i][1];
	}
	return *this;
}
void Graph::addE(int a, int b)
{
	try
	{
		if (a < 1 || a > this->numOfVer)
			throw 1;
		if (b < 1 || b > this->numOfVer)
			throw 2;
		enlArr(this->e, this->numOfE, 2);
		this->e[numOfE - 1][0] = a;
		this->deg[a - 1]++;
		this->e[numOfE - 1][1] = b;
		this->deg[b - 1]++;
	}
	catch (int e)
	{
		std::cout << "Graph::addE(int, int)\t\tError - " << e << std::endl;
	}
}
int Graph::addVer()
{
	this->numOfVer++;
	this->findDeg();
	return this->numOfVer;
}
int Graph::addVer(int num)
{
	if (num < 0)
	{
		std::cout << "Warning! Graph::addVer(int num): num < 0. Some edges will be deleted." << std::endl;
		if ((this->numOfVer + num) <= 0)
		{
			this->numOfVer = 0;
			this->numOfE = 0;
			this->deg = NULL;
			this->e = NULL;
			std::cout << "The graph is empty." << std::endl;
			return 0;
		}
		this->numOfVer += num;
		std::cout << "Deleted Edges: ";
		for (int i = 0; i < this->numOfE; i++)
			if (this->e[i][0] > this->numOfVer || this->e[i][1] > this->numOfVer)
			{
				std::cout << "(" << this->e[i][0] << ", " << this->e[i][1] << ") ";
				this->remE(i);
			}
		std::cout << std::endl;
		this->findDeg();
		return this->numOfVer;
	}
	this->numOfVer += num;
	this->findDeg();
	return this->numOfVer;
}
int Graph::remE(int a, int b)
{
	try
	{
		if (a < 1 || a > this->numOfVer)
			throw 1;
		if (b < 1 || b > this->numOfVer)
			throw 2;

		// id of element to remove
		int rem_id = -1;
		for (int i = 0; i < this->numOfE; i++)
			if ((this->e[i][0] == a && this->e[i][1] == b) ||
				(this->e[i][1] == a && this->e[i][0] == b))
				rem_id = i;
		// if there no such elements
		if (rem_id == -1)
			return 0;

		// if there is only that element
		if (this->numOfE == 1)
		{
			for (int i = 0; i < this->numOfE; i++)
				delete[] this->e[i];
			delete[] this->e;
			this->e = NULL;
			this->numOfE = 0;
		}

		int ** e_copy = new int*[this->numOfE - 1];
		for (int i = 0; i < rem_id; i++)
		{
			e_copy[i] = new int[2];
			e_copy[i][0] = this->e[i][0];
			e_copy[i][1] = this->e[i][1];
		}
		for (int i = rem_id + 1; i < this->numOfE; i++)
		{
			e_copy[i - 1] = new int[2];
			e_copy[i - 1][0] = this->e[i][0];
			e_copy[i - 1][1] = this->e[i][1];
		}
		
		for (int i = 0; i < numOfE; i++)
		{
			delete[] this->e[i];
		}
		delete[] this->e;
		this->numOfE--;
		this->e = new int*[this->numOfE];
		for (int i = 0; i < this->numOfE; i++)
		{
			this->e[i] = new int[2];
			this->e[i][0] = e_copy[i][0];
			this->e[i][1] = e_copy[i][1];
			delete[] e_copy[i];
		}
		delete[] e_copy;
		return 1;
	}
	catch (int e)
	{
		std::cout << "Graph::remE(int a, int b)\t\tError - " << e << std::endl;
		return -1;
	}
}
int Graph::remE(int id)
{
	try
	{
		if (id < 0 || id >= this->numOfE)
			throw 1;

		// if there is only that element
		if (this->numOfE == 1)
		{
			for (int i = 0; i < this->numOfE; i++)
				delete[] this->e[i];
			delete[] this->e;
			this->e = NULL;
			this->numOfE = 0;
		}

		int ** e_copy = new int*[this->numOfE - 1];
		for (int i = 0; i < id; i++)
		{
			e_copy[i] = new int[2];
			e_copy[i][0] = this->e[i][0];
			e_copy[i][1] = this->e[i][1];
		}
		for (int i = id + 1; i < this->numOfE; i++)
		{
			e_copy[i - 1] = new int[2];
			e_copy[i - 1][0] = this->e[i][0];
			e_copy[i - 1][1] = this->e[i][1];
		}

		for (int i = 0; i < numOfE; i++)
		{
			delete[] this->e[i];
		}
		delete[] this->e;
		this->numOfE--;
		this->e = new int*[this->numOfE];
		for (int i = 0; i < this->numOfE; i++)
		{
			this->e[i] = new int[2];
			this->e[i][0] = e_copy[i][0];
			this->e[i][1] = e_copy[i][1];
			delete[] e_copy[i];
		}
		delete[] e_copy;
		return 1;

	}
	catch (int e)
	{
		std::cout << "Graph::remE(int id)\t\tError - " << e << std::endl;
		return 0;
	}

}
void Graph::findDeg()
{
	this->deg = new int[this->numOfVer];
	for (int i = 0; i < this->numOfVer; i++)
	{
		this->deg[i] = 0;
	}
	for (int i = 0; i < this->numOfE; i++)
	{
		this->deg[this->e[i][0] - 1]++;
		this->deg[this->e[i][1] - 1]++;
	}
}
int Graph::getDeg(const int id)
{
	try
	{
		if (id < 0)
			throw 1;
		if (id > this->numOfVer)
			throw 2;
		return this->deg[id];
	}
	catch (int e)
	{
		std::cout << "Graph::deg()\t\tError - " << e << std::endl;
		return -1;
	}
}