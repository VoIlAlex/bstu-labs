#pragma once
#include <string>
void log(std::string author, std::string message);
class Entity
{
	std::string name;
	double health;
	double mana;
	double attackPower;
public:
	Entity();
	Entity(std::string name, double health, double mana, double attackPower);
	void operator>>(Entity& victim);
	friend void showInfo(const Entity& entity);
};
void showInfo(const Entity& entity);