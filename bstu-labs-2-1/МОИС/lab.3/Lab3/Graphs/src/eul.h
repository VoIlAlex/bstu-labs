#pragma once
#include "euhamgr.h"
#include "grtrav.h"
#include "graph.h"
namespace Eulerian
{
	enum mode
	{
		circuit = 0,
		path
	};
}
// Eulerian graph
class Eul : public EuHamGr
{
protected:
	void find(GrTrav& bf, Eulerian::mode mode);
	bool isSemi(GrTrav& tr);
	bool is(GrTrav& tr);
public:
	// Is semi-Eulerian
	bool isSemi();
	// Is Eulerian
	bool is();
	Eul(const Graph& graph);
	Eul(const GraphNumberOfVertices numOfVer, const List<Edge>& e, const GraphNumberOfEdges numOfE);
	Eul(const Eul& obj);
	~Eul();
	void showCir();
	void showPath();
};