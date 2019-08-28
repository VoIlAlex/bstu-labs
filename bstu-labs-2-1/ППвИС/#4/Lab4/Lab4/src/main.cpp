#include <iostream>
#include "entity.h"
int main()
{
	Entity	unit1("Bob", 100, 10, 20),
			unit2("Tom", 80, 80, 30);
	showInfo(unit1);
	std::cout << std::endl;
	showInfo(unit2);
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		unit1 >> unit2;
		unit2 >> unit1;
	}
	std::cin.get();
}