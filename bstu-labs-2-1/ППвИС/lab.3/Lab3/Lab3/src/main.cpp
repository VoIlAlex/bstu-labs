#include <iostream>
#include "gamecompany.h"
int main()
{
	{
		GameCompany valve("valve");
		valve.setEquity(2500000000);
		Game dota2("Dota 2", 2013, 0);
		valve.addGame(dota2);
		std::string name;
		unsigned short yearOfRelease;
		double price;
		valve[0].get(name);
		valve[0].get(yearOfRelease);
		valve[0].get(price);
		std::cout << name.c_str() << std::endl;
		std::cout << yearOfRelease << std::endl;
		std::cout << price << std::endl;
		valve.showInfo();
		valve.deleteGame("Dota 2");
		valve.showInfo();
	}
	std::cin.get();
}