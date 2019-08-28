// File: unit.cpp
// Date of creation: 10/5/2018
// Date of modification: 
//
// Description: this file contains the class Unit for all units in our game
//

#include "pch.h"
#include "unit.h"


Unit::Unit(Unit& obj)
{
	this->name = obj.name;
	this->defaultHealth = obj.defaultHealth;
	this->health = obj.health;
	this->attackSpeed = obj.attackSpeed;
	this->attackPower = obj.attackPower;
	this->status = obj.status;
}
Unit::Unit()
{
	this->status = true;
}
void Unit::setName(std::string newName)
{
	this->name = newName;
}
void Unit::setDefaultHealth(double newDefaultHealth)
{
	this->defaultHealth = newDefaultHealth;
}
void Unit::setHealth(double newHealth)
{
	this->health = newHealth;
}
void Unit::setDefaultAttackPower(double newDefaultAttackPower)
{
	this->defaultAttackPower = newDefaultAttackPower;
}
void Unit::setAttackPower(double newAttackPower)
{
	this->attackPower = newAttackPower;
}
void Unit::setDefaultAttackSpeed(double newDefaultAttackSpeed)
{
	this->defaultAttackSpeed = newDefaultAttackSpeed;
}
void Unit::setAttackSpeed(double newAttackSpeed)
{
	this->attackSpeed = newAttackSpeed;
}
std::string Unit::getName()
{
	return this->name;
}
double Unit::getHealth()
{
	return this->health;
}
double Unit::getAttackSpeed()
{
	return this->attackSpeed;
}
double Unit::getAttackPower()
{
	return this->attackPower;
}
bool Unit::isAlive()
{
	return this->status;
}
void Unit::damage(Unit attacker, double damage)
{
	this->health -= damage;
	std::cout << this->name.c_str() << " has been attacked by " << attacker.getName().c_str() << std::endl;
	std::cout << "Damage - " << damage << std::endl;
	if (this->health <= 0)
	{
		this->death();
		std::cout << this->name.c_str() << " has been killed by " << attacker.getName().c_str() << std::endl;
	}
}
void Unit::death()
{
	this->health = 0;
	this->status = false;
}
void Unit::heal(Unit healer, double heal)
{
	this->health += heal;
	if (!this->status)
	{
		this->reborn();
	}
}
void Unit::reborn()
{
	this->status = true;
	this->health = this->defaultHealth;
}
void Unit::reborn(double initHealth)
{
	this->status = true;
	this->health = initHealth;
}