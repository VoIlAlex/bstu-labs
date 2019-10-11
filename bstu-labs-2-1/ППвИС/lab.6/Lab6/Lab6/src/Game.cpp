#include "Game.h"

Game::Unit::Unit()
	: name("noname"), health(0), mana(0), damage(0), state(UNIT_DEAD) {}
Game::Unit::Unit(UnitName n, UnitHealth h, UnitMana m, UnitDamage d)
	: name(n), health(h), mana(m), damage(d), state((h>0)?UNIT_ALIVE:UNIT_DEAD) {}
void Game::Unit::attack(Unit& victim) const 
{
	std::cout << name << " attack " << victim.name << "." << std::endl;
	try
	{
		if(health == 0)
			throw 0;
		if(victim.health == 0)
			throw 1;
		if((victim.health - damage) <= 0)
			throw 2;
		victim.health -= damage;
		std::cout << "Damage - " << damage << "." << std::endl;
	}
	catch(int e)
	{
		if(e == 0)
		{
			std::cout << name << " cannot attack " << victim.name << "." << std::endl;
			std::cout << name << " is dead." << std::endl;
		}
		else if(e == 1)
		{
			std::cout << "Damage - 0." << std::endl;
			std::cout << victim.name << " is already dead." << std::endl;
		}
		else if(e == 2)
		{
			std::cout << "Damage - " << victim.health << "." << std::endl;
			std::cout << victim.name << " has been killed by " << name << "." << std::endl;
			victim.health = 0;
			victim.state = UNIT_DEAD;
		}
	}
}
UnitState Game::Unit::isAlive() const 
{
	return state;
}