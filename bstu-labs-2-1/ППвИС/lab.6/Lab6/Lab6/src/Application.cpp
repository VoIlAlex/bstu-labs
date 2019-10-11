#include <iostream>
#include "Game.h"

int main()
{
	Game::Unit unit1("Bob", 100, 0, 10); // Bob
	Game::Unit unit2("Tom", 100, 0, 10); // Tom
	// Bob is killing Tom
	while(unit2.isAlive())
		unit1.attack(unit2);
	Game::Unit unit3; // noname
	std::cout << std::endl;
	unit2.attack(unit3); // dead Bob is trying to attack noname
	std::cout << std::endl;
	unit1.attack(unit3); // Tom is trying to attack noname

	std::cin.get();
	return 0;
}