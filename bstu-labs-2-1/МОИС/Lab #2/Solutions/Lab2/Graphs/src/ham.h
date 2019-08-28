#pragma once
#include "euhamgr.h"

class Ham : public EuHamGr
{
protected:
	void find();
	bool cir(int * ver);
	bool path(int * ver);
public:
	Ham(const Graph& graph);
	Ham(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE);
	Ham(const Ham& obj);
	~Ham();
	bool isSemi();
	bool is();
	void showCir();
	void showPath();
};