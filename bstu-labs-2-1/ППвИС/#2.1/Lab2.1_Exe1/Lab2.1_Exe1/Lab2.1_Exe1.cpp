#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <cstring>

#include "unit.h"
#include "troll.h"

int main(int argc, char* argv[])
{
	std::string name1 = "bob", name2 = "tom";
	Troll unit1(name1), unit2(name2);
	std::cout << unit2.getHealth() << std::endl;
	for(int i = 0; i < 11; i++)
		unit1.attack(unit2);
	std::cout << unit2.getHealth() << std::endl;

	system("pause");
	return 0;
}
