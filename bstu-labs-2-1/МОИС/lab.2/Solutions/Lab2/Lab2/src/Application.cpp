#include <iostream>
#include "Graphs.h"

int main()
{
	const GraphNumberOfVertices n1 = 6;
	const GraphNumberOfVertices n2 = 7;

	Graph G1;
	G1.addVer(n1);
	G1.addE(1, 2); G1.addE(1, 4);
	G1.addE(2, 3); G1.addE(2, 5); G1.addE(2, 6);
	G1.addE(3, 4); G1.addE(3, 5); G1.addE(3, 6);
	G1.addE(4, 5); G1.addE(4, 6);
	G1.addE(5, 6);
	Eul eulG1(G1);
	Ham hamG1(G1);
	std::cout << "G1: " << std::endl;
	eulG1.showCir();
	eulG1.showPath();
	hamG1.showCir();
	hamG1.showPath();


	Graph G2;
	G2.addVer(n2);
	G2.addE(1, 2); G2.addE(1, 3); G2.addE(1, 4);
	G2.addE(2, 3); G2.addE(2, 4); G2.addE(2, 5);
	G2.addE(3, 4); G2.addE(3, 7);
	G2.addE(4, 5); G2.addE(4, 6); G2.addE(4, 7);
	G2.addE(5, 6);
	G2.addE(6, 7);
	Eul eulG2(G2);
	Ham hamG2(G2);
	std::cout << "G2: " << std::endl;
	eulG2.showCir();
	eulG2.showPath();
	hamG2.showCir();
	hamG2.showPath();

	std::cin.get();
}