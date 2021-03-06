#include <iostream>
#include "Graphs.h"
#include <chrono>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> end, start;
	std::chrono::duration<float> duration;
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		std::cout << "Timer: " << ms << "ms " << std::endl;
	}
};

int main()
{
	const int numOfVer = 9;
	const int numOfE = 12;
	int e[numOfE][2] = {
		{1,2},
		{1,3}, 
		{2,3},
		{3,4},
		{3,7},
		{4,7},
		{4,5},
		{4,6},
		{7,8},
		{7,9},
		{6,5},
		{8,9}
	};
	int weights[numOfE] = { 2,3,4,5,7,6,3,5,1,1,1,2 };

	Graph graph;
	graph.addVer(numOfVer);
	for (int i = 0; i < numOfE; i++)
		graph.addE(e[i][0], e[i][1], weights[i]);

	Graph tree;

	// graph
	matrix::outMatrix(matrix::adjMatrix(graph), graph.getNumOfVer(), graph.getNumOfVer());

	// MST Prim's
	{
		Timer t;
		mintreePrim(tree, graph);
	}
	std::cout << std::endl;
	matrix::outMatrix(matrix::adjMatrix(tree), tree.getNumOfVer(), tree.getNumOfVer());

	// MST Kruskal's
	{
		Timer t;
		mintreeKruskal(tree, graph);
	}
	std::cout << std::endl;
	matrix::outMatrix(matrix::adjMatrix(tree), tree.getNumOfVer(), tree.getNumOfVer());

	
	std::cin.get();
}

