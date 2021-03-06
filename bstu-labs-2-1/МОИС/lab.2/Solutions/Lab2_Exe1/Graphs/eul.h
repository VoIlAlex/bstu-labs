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
	// Eulerian path
	// void findPath(GrTrav bf);
	// Eulerian circuit
	void find(GrTrav bf, Eulerian::mode mode);

	bool isSemi(GrTrav tr);
	bool is(GrTrav tr);
public:
	// Is semi-Eulerian
	bool isSemi();
	
	// Is Eulerian
	bool is();

	Eul(const Graph& graph);
	Eul(int numOfVer, int** e, int numOfE);
	Eul(const Eul& obj);
	~Eul();

	void showCir();
	void showPath();
};