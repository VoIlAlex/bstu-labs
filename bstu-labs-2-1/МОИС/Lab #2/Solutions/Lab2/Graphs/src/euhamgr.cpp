#include "stdafx.h"
#include "euhamgr.h"

EuHamGr::EuHamGr() {}
EuHamGr::~EuHamGr() {}

EuHamGr::EuHamGr(const EuHamGr& obj)
	: graph(obj.graph), pathE(obj.pathE), cirE(obj.cirE) {}
EuHamGr::EuHamGr(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE)
	: graph(numOfVer, e, numOfE) {}
EuHamGr::EuHamGr(const Graph& graph)
	: graph(graph) {}