#include "game.h"
#include <iostream>
Game::Game() 
{
	this->name = "without_name";
	this->yearOfRelease = 0;
	this->price = 0;
}
Game::Game(std::string name, unsigned short yearOfRelease, double price)
{
	this->name = name;
	this->yearOfRelease = yearOfRelease;
	this->price = price;
}
std::string Game::getName()
{
	return this->name;
}
unsigned short Game::getYearOfRelease()
{
	return this->yearOfRelease;
}
double Game::getPrice()
{
	return this->price;
}
void Game::setName(std::string newName)
{
	this->name = newName;
}
void Game::setYearOfRelease(unsigned short newYearOfRelease)
{
	this->yearOfRelease = newYearOfRelease;
}
void Game::setPrice(double newPrice)
{
	this->price = newPrice;
}
void Game::get(std::string& str)
{
	str = this->name;
}
void Game::get(unsigned short& u_sh)
{
	u_sh = this->yearOfRelease;
}
void Game::get(double& d)
{
	d = this->price;
}
void Game::get(std::string& str, unsigned short& u_sh, double& d)
{
	str = this->name;
	u_sh = this->yearOfRelease;
	d = this->price;
}
void Game::set(const std::string& str)
{
	this->name = str;
}
void Game::set(const unsigned short& u_sh)
{
	this->yearOfRelease = u_sh;
}
void Game::set(const double& d)
{
	this->price = d;
}
void Game::set(const std::string& str, const unsigned short& u_sh, const double& d)
{
	this->name = str;
	this->yearOfRelease = u_sh;
	this->price = d;
}
void Game::showInfo()
{
	std::cout << "Name: " << this->name.c_str() << std::endl;
	std::cout << "Year of release: " << this->yearOfRelease << std::endl;
	std::cout << "Price: " << this->price << std::endl;
}