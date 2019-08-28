#include "entity.h"
#include <iostream>
void log(std::string author, std::string message)
{
	std::cout << author << ": " << message << std::endl;
}
void showInfo(const Entity& entity)
{
	std::cout << "Name: " << entity.name << std::endl;
	std::cout << "Health: " << entity.health << std::endl;
	std::cout << "Mana: " << entity.mana << std::endl;
	std::cout << "Attack power: " << entity.attackPower << std::endl;
}
Entity::Entity()
	: name("without_name"), health(0), mana(0), attackPower(0)
{}
Entity::Entity(std::string name, double health, double mana, double attackPower)
	: name(name), health(health), mana(mana), attackPower(attackPower)
{}
void Entity::operator>>(Entity& victim)
{
	if (this->health == 0) { return; }
	log(this->name, ("attack " + victim.name + "."));
	if (victim.health == 0)
	{
		log(this->name, ("Cannot attack " + victim.name + "."));
		log(this->name, (victim.name + " is already dead."));
		return;
	}
	if ((victim.health - this->attackPower) <= 0)
	{
		std::cout << victim.name << ": health -" << victim.health << std::endl;
		victim.health = 0;
		std::cout << victim.name << " has been killed by " << this->name << std::endl;
		return;
	}
	victim.health -= this->attackPower;
	std::cout << victim.name << ": health -" << this->attackPower << std::endl;
	std::cout << victim.name << ": current health: " << victim.health << std::endl;
}
