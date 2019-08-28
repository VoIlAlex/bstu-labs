#include "stdafx.h"
#include "grtrav.h"
#include "common.h"
#include <queue>
#include <stack>

GrTrav::GrTrav()
{
	this->e = NULL;
	this->numOfConnComp = 0;
	this->numOfE = 0;
}
GrTrav::~GrTrav()
{
	delete this->e;
}

int ** GrTrav::getE(int& numOfE)
{
	numOfE = this->numOfE;
	return this->e;
}
int ** GrTrav::getE()
{
	return this->e;
}
int GrTrav::getNumOfE()
{
	return this->numOfE;
}
int GrTrav::getConnComp()
{
	return this->numOfConnComp;
}

/////////////////////
//// Depth-First ////
/////////////////////
DepthFirst::DepthFirst(const int &numOfVer, int **e, const int& numOfE)
{
	this->numOfConnComp = 0;
	bool * marked = new bool[numOfVer];
	for (int i = 0; i < numOfVer; i++) marked[i] = false;

	std::stack <int> v; // picked vertices
	while (true)
	{
		//// picking first vertex ////
		int cur = 0;
		for (int i = 0; i < numOfVer; i++)
			if (marked[i] == false)
			{
				cur = i + 1;
				break;
			}
		if (!cur) break; // if there is no available element then break
		this->numOfConnComp++;
		v.push(cur);
		////
		while (!v.empty())
		{
			int nextVer = 0; // next vertex to consider
			for (int i = 0; i < numOfE; i++)
			{
				if (e[i][0] == v.top() || e[i][1] == v.top())
				{
					int elId; // id of potential element in the "e" array
					if (e[i][0] == v.top()) elId = 1;
					else if (e[i][1] == v.top()) elId = 0;
					//// Chacking for potential next vertex in the stack and in the marked vertex array ////
					bool isSuitable = true; // is potential next vertex suit
											// is in the stack
					std::stack <int> v_copy = v;
					while (!v_copy.empty())
					{
						if (e[i][elId] == v_copy.top())
							isSuitable = false;
						v_copy.pop();
					}
					// is in the marked array
					if (marked[(e[i][elId] - 1)])
						isSuitable = false;
					////
					if (isSuitable)
					{
						nextVer = e[i][elId];
						break;
					}
				}
			}
			if (!nextVer) // if we don't have a vertex to consider
			{
				int lastEl = v.top();
				v.pop();
				marked[(lastEl - 1)] = true;
				if (v.empty())
					continue;
				enlArr(this->e, this->numOfE);
				this->e[this->numOfE - 1] = new int[2];
				this->e[this->numOfE - 1][0] = lastEl;
				this->e[this->numOfE - 1][1] = v.top();
			}
			else v.push(nextVer);
		}
	}
}
DepthFirst::~DepthFirst()
{
	for (int i = 0; i < this->numOfE; i++)
		delete[] e[i];
	delete[] e;
}

//////////////////////
//// Breath-First ////
//////////////////////
BreadthFirst::BreadthFirst(const int &numOfVer, int **e, const int& numOfE)
{
	this->numOfConnComp = 0;
	bool * marked = new bool[numOfVer];
	for (int i = 0; i < numOfVer; i++) marked[i] = false;

	while (true)
	{
		//// picking first vertex ////
		int cur = 0;
		for (int i = 0; i < numOfVer; i++)
		{
			if (marked[i] == false)
			{
				cur = i + 1;
				break;
			}
		}
		if (!cur) break;
		/////

		std::queue <int> v;
		v.push(cur);
		marked[cur - 1] = true;
		this->numOfConnComp++;

		while (!v.empty())
		{
			int fr = v.front();
			v.pop();
			for (int i = 0; i < numOfE; i++)
				if (fr == e[i][0] || fr == e[i][1])
				{
					int elId; // array id of an element under consideration 
					if (fr == e[i][0]) elId = 1;
					else if (fr == e[i][1]) elId = 0;
					if (marked[e[i][elId] - 1] == false)
					{
						// marking suitable vertex
						v.push(e[i][elId]);
						marked[e[i][elId] - 1] = true;
						// placing the edge into the array
						enlArr(this->e, this->numOfE);
						this->e[this->numOfE - 1] = new int[2];
						this->e[this->numOfE - 1][0] = fr;
						this->e[this->numOfE - 1][1] = e[i][elId];
					}
				}
		}
	}
}
BreadthFirst::~BreadthFirst()
{
	for (int i = 0; i < this->numOfE; i++)
		delete[] e[i];
	delete[] e;
}