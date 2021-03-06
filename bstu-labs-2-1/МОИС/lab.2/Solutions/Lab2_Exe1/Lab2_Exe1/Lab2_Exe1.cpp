// Lab2_Exe1.cpp

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Graphs.h"

int main()
{
	
	Graph g;
	g.addVer(5);
	g.addE(1, 2);
	g.addE(2, 3);
	g.addE(3, 4);
	g.addE(2, 5);
	g.addE(5, 1);
	g.addE(4, 2);
	Ham h(g);
	matrix::outMatrix(matrix::adjMatrix(g), g.getNumOfVer(), g.getNumOfVer());
	std::cout << h.is() << std::endl;
	h.showCir();
	h.showPath();
	system("pause");
	return 0;
}