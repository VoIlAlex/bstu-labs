#include "stdafx.h"
#include "euhamgr.h"

EuHamGr::EuHamGr() {}
EuHamGr::~EuHamGr()
{
	for (int i = 0; i < this->numOfPathE; i++)
	{
		delete[] this->pathE[i];
	}
	delete[] pathE;

	for (int i = 0; i < this->numOfCirE; i++)
	{
		delete[] this->cirE[i];
	}
	delete[] cirE;
}

EuHamGr::EuHamGr(const EuHamGr& obj)
	: graph(obj.graph), pathE(new int*[obj.numOfPathE]), numOfPathE(obj.numOfPathE)
	, cirE(new int*[obj.numOfCirE]), numOfCirE(obj.numOfCirE)
{
	for (int i = 0; i < numOfPathE; i++)
	{
		pathE[i] = new int[2];
		pathE[i][0] = obj.pathE[i][0];
		pathE[i][1] = obj.pathE[i][1];
	}
	for (int i = 0; i < numOfCirE; i++)
	{
		cirE[i] = new int[2];
		cirE[i][0] = obj.cirE[i][0];
		cirE[i][1] = obj.cirE[i][1];
	}
}
EuHamGr::EuHamGr(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE)
	: graph(numOfVer, e, numOfE), pathE(nullptr), numOfPathE(0)
	, cirE(nullptr), numOfCirE(0) {}
EuHamGr::EuHamGr(const Graph& graph)
	: graph(graph), pathE(nullptr), numOfPathE(0)
	, cirE(nullptr), numOfCirE(0) {}