#include <iostream>
#include <Graphs.h>
#include "ShortestPath.h"
int main()
{
	const int numOfVer = 6;
	const int numOfE = 9;
	int e[numOfE][2] = {
		{1,2},
		{1,3},
		{1,4},
		{2,4},
		{2,6},
		{3,4},
		{3,5},
		{4,5},
		{4,6}
	};
	int weights[numOfE] = { 5,7,4,3,2,5,8,6,4 };
	Graph g;
	g.addVer(numOfVer);
	for (int i = 0; i < numOfE; i++)
		g.addE(e[i][0], e[i][1], weights[i]);
	ShortestPathDijkstra shPathD(g);
	ShortestPathFloydWarshall shPathFW(g);
	int fVer;
	std::cout << "First vertex: ";
	fVer = std::cin.get() - 48;
	std::cout << "Dijkstra: " << std::endl;
	for (int i = 1; i <= numOfVer; i++)
	{
		shPathD.getShortestPath(fVer, i).viewPath();
		std::cout << "Length: " << shPathD.getShortestPath(fVer, i).length() << std::endl;
	}
	std::cout << "Floyd-Warshall: " << std::endl;
	for (int i = 1; i <= numOfVer; i++)
	{
		shPathFW.getShortestPath(fVer, i).viewPath();
		std::cout << "Length: " << shPathFW.getShortestPath(fVer, i).length() << std::endl;
	}
	system("pause");
}