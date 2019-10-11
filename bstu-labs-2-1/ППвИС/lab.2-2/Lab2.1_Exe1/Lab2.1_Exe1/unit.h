// File: unit.h
// Date of creation: 10/5/2018
// Date of modification: 
//
// Description: 
//

#pragma once

#include <iostream>

class Unit
{
protected:
	std::string name;
	double defaultHealth;
	double health;
	double defaultAttackSpeed;
	double attackSpeed;
	double defaultAttackPower;
	double attackPower;
	bool status; // alive or not
public:
	Unit(Unit& obj);
	Unit();
	void setName(std::string newName);
	void setDefaultHealth(double newDefaultHealth);
	void setHealth(double newHealth);
	void setDefaultAttackPower(double newDefaultAttackPower);
	void setAttackPower(double newAttackPower);
	void setDefaultAttackSpeed(double newDefaultAttackSpeed);
	void setAttackSpeed(double newAttackSpeed);
	std::string getName();
	double getHealth();
	double getAttackSpeed();
	double getAttackPower();
	bool isAlive();
	void damage(Unit attacker, double damage);
	void death();
	void heal(Unit healer, double heal);
	void reborn();
	void reborn(double initHealth);
};