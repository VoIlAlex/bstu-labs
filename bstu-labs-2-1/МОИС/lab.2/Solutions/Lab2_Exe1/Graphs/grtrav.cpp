#include "stdafx.h"
#include "grtrav.h"
#include "common.h"
#include <queue>
#include <stack>

GrTrav::GrTrav(){}
GrTrav::~GrTrav(){}
GrTrav::GrTrav(const GrTrav& obj)
{
	this->graph = obj.graph;
	this->numOfConnComp = obj.numOfConnComp;
	this->tree = obj.tree;
}
Graph GrTrav::getTree()
{
	return this->tree;
}
Graph& GrTrav::getGraph()
{
	return this->graph;
}
int GrTrav::getConnComp()
{
	return this->numOfConnComp;
}
void GrTrav::trav() {}

/////////////////////
//// Depth-First ////
/////////////////////
DepthFirst::DepthFirst(const int &numOfVer, int **e, const int& numOfE)
{
	this->graph = *(new Graph(numOfVer, e, numOfE));
	this->trav();
}
DepthFirst::DepthFirst(const Graph& gr)
{
	this->graph = gr;
}
DepthFirst::~DepthFirst(){}
void DepthFirst::trav()
{
	this->numOfConnComp = 0;
	bool * marked = new bool[this->graph.getNumOfVer()];
	for (int i = 0; i < this->graph.getNumOfVer(); i++) marked[i] = false;

	std::stack <int> v; // picked vertices
	while (true)
	{
		//// picking first vertex ////
		int cur = 0;
		for (int i = 0; i < this->graph.getNumOfVer(); i++)
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
			for (int i = 0; i < this->graph.getNumOfE(); i++)
			{
				if (this->graph[i][0] == v.top() || this->graph[i][1] == v.top())
				{
					int elId; // id of potential element in the "e" array
					if (this->graph[i][0] == v.top()) elId = 1;
					else if (this->graph[i][1] == v.top()) elId = 0;
					//// Chacking for potential next vertex in the stack and in the marked vertex array ////
					bool isSuitable = true; // is potential next vertex suit
											// is in the stack
					std::stack <int> v_copy = v;
					while (!v_copy.empty())
					{
						if (this->graph[i][elId] == v_copy.top())
							isSuitable = false;
						v_copy.pop();
					}
					// is in the marked array
					if (marked[(this->graph[i][elId] - 1)])
						isSuitable = false;
					////
					if (isSuitable)
					{
						nextVer = this->graph[i][elId];
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

				this->tree.addE(lastEl, v.top());
			}
			else v.push(nextVer);
		}
	}
}

//////////////////////
//// Breath-First ////
//////////////////////
BreadthFirst::BreadthFirst(const int &numOfVer, int **e, const int& numOfE)
{
	this->graph = *(new Graph(numOfVer, e, numOfE));
	this->trav();
}
BreadthFirst::BreadthFirst(const Graph& gr)
{
	this->graph = gr;
	this->trav();
}
BreadthFirst::~BreadthFirst(){}
void BreadthFirst::trav()
{
	this->numOfConnComp = 0;
	bool * marked = new bool[this->graph.getNumOfVer()];
	for (int i = 0; i < this->graph.getNumOfVer(); i++) marked[i] = false;

	while (true)
	{
		//// picking first vertex ////
		int cur = 0;
		for (int i = 0; i < this->graph.getNumOfVer(); i++)
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
			for (int i = 0; i < this->tree.getNumOfE(); i++)
				if (fr == this->graph[i][0] || fr == this->graph[i][1])
				{
					int elId; // array id of an element under consideration 
					if (fr == this->graph[i][0]) elId = 1;
					else if (fr == this->graph[i][1]) elId = 0;
					if (marked[this->graph[i][elId] - 1] == false)
					{
						// marking suitable vertex
						v.push(this->graph[i][elId]);
						marked[this->graph[i][elId] - 1] = true;
						// placing the edge into the array

						this->tree.addE(fr, this->graph[i][elId]);
					}
				}
		}
	}
}