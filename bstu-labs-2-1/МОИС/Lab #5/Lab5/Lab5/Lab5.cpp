// Lab5.cpp
// МОИС
// 

#include "pch.h"
#include <iostream>
#include "Graphs.h"
#include "scc.h"
#include "lab5_2.h"

#define a 1
#define b 2
#define c 3
#define d 4
#define e 5
#define f 6

//(a, b), (a, d), (b, e), (c, a),
//(c, b), (c, d), (e, c)


int main()
{
	Graph gr(GraphType::DIRECTED);
	gr.addVer(5);
	gr.addE(a, b);
	gr.addE(a, d);
	gr.addE(b, e);
	gr.addE(c, a);
	gr.addE(c, b);
	gr.addE(c, d);
	gr.addE(e, c);

	SCC scc(gr);
	auto sccs = scc.getSCCs();

	for (int i = 0; i < sccs.size(); i++)
	{
		for (int j = 0; j < sccs[i].size(); j++)
			std::cout << (char)(sccs[i][j] + 96) << " ";
		std::cout << std::endl;
	}

	Graph gr2;
	gr2.addVer(6);
	gr2.addE(a, b);
	gr2.addE(a, c);
	gr2.addE(b, d);
	gr2.addE(c, d);
	gr2.addE(d, e);
	gr2.addE(d, f);
	gr2.addE(e, f);

	std::vector<Graph> biconnComp = Lab5::findBiconnComp(gr2);

	for (Graph& gr : biconnComp)
	{
		show(gr, ALPHA);
		std::cout << std::endl;
	}

	std::cin.get();
}
