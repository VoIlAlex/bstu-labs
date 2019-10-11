// File: troll.cpp
// Date of creation: 10/5/2018
// Date of modification: 
//
// Description: 
//
#include "pch.h"
#include "troll.h"


Troll::Troll()
{
	this->status = true;
	this->defaultHealth = 100;
	this->health = this->defaultHealth;
	this->defaultAttackSpeed = 30;
	this->attackSpeed = this->defaultAttackSpeed;
	this->defaultAttackPower = 10;
	this->attackPower = this->defaultAttackPower;
}
Troll::Troll(std::string initName)
{
	this->status = true;
	this->name = initName;
	this->defaultHealth = 100;
	this->health = this->defaultHealth;
	this->defaultAttackSpeed = 30;
	this->attackSpeed = this->defaultAttackSpeed;
	this->defaultAttackPower = 10;
	this->attackPower = this->defaultAttackPower;
}
void Troll::attack(Unit& victim)
{
	if (victim.isAlive() == false)
	{
		std::cout << "Unit is dead!" << std::endl;
		return;
	}
	victim.damage(*this, this->attackPower);
}