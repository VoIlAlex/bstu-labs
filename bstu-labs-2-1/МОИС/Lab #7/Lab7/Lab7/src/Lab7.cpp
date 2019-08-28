// Lab7 МОИС
#include <iostream>
#include <set>
#include <chrono>
#include "lab7_1.h"

#define out(a) {\
	int i = 0;\
	for (Point p : a)\
	{\
		std::cout << ((i) ? ", " : "") << "(" << p.first << ";" << p.second << ")";\
		i++;\
	}\
	std::cout << std::endl; }

int main()
{
	using namespace Lab7;
	PointSet points = {	{7.0, 1.0},
						{12.0, 2.0},
						{9.0, 3.0},
						{11.0, 4.0},
						{7.0, 5.0}, 
						{6.0, 5.0}, 
						{13.0, 5.0},
						{16.0, 7.0},
						{13.0, 8.0},
						{11.0, 7.0},
						{9.0, 6.0},
						{5.0, 7.0},
						{3.0, 7.0},
						{8.0, 9.0},
						{9.0, 11.0},
						{12.0, 10.0},
						{14.0, 11.0} };

	PointSet convexHull1 = JarvisMarch(points);
	out(convexHull1);

	
	PointSet convexHull2 = GrahamScan(points);
	out(convexHull2);

	PointSet convexHull3 = Chan(points, 3);
	out(convexHull3);

	std::cout << std::endl;
	std::cin.get();
}