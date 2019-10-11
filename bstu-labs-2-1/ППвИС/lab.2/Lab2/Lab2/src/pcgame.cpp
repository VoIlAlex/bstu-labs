#include "pcgame.h"
#include <iostream>
PCGame::PCGame() 
{
	this->name = "without_name";
	this->yearOfRelease = 0;
	this->price = 0;
}
PCGame::PCGame(std::string name, unsigned short yearOfRelease, double price)
{
	this->name = name;
	this->yearOfRelease = yearOfRelease;
	this->price = price;
}
std::string PCGame::getName()
{
	return this->name;
}
unsigned short PCGame::getYearOfRelease()
{
	return this->yearOfRelease;
}
double PCGame::getPrice()
{
	return this->price;
}
void PCGame::setName(std::string newName)
{
	this->name = newName;
}
void PCGame::setYearOfRelease(unsigned short newYearOfRelease)
{
	this->yearOfRelease = newYearOfRelease;
}
void PCGame::setPrice(double newPrice)
{
	this->price = newPrice;
}
void PCGame::get(std::string& str)
{
	str = this->name;
}
void PCGame::get(unsigned short& u_sh)
{
	u_sh = this->yearOfRelease;
}
void PCGame::get(double& d)
{
	d = this->price;
}
void PCGame::get(std::string& str, unsigned short& u_sh, double& d)
{
	str = this->name;
	u_sh = this->yearOfRelease;
	d = this->price;
}
void PCGame::set(const std::string& str)
{
	this->name = str;
}
void PCGame::set(const unsigned short& u_sh)
{
	this->yearOfRelease = u_sh;
}
void PCGame::set(const double& d)
{
	this->price = d;
}
void PCGame::set(const std::string& str, const unsigned short& u_sh, const double& d)
{
	this->name = str;
	this->yearOfRelease = u_sh;
	this->price = d;
}
void PCGame::showInfo()
{
	std::cout << "Name: " << this->name.c_str() << std::endl;
	std::cout << "Year of release: " << this->yearOfRelease << std::endl;
	std::cout << "Price: " << this->price << std::endl;
}