#include <iostream>
#include "pcgame.h"
int main()
{
	PCGame dota("Dota 2", 2013, 0);
	dota.showInfo();
	std::string name;
	unsigned short year;
	double price;
	dota.get(name);
	dota.get(year);
	dota.get(price);
	std::cout << name << std::endl;
	std::cout << year << std::endl;
	std::cout << price << std::endl;
	dota.set("CS:GO");
	dota.set((unsigned short)2012);
	dota.set(8.49);
	dota.get(name);
	dota.get(year);
	dota.get(price);
	std::cout << name << std::endl;
	std::cout << year << std::endl;
	std::cout << price << std::endl;
	std::cin.get();
}