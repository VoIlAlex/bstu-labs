#include "gamecompany.h"
#include <iostream>
GameCompany::GameCompany()
{
	this->name = "without_name";
	this->games = NULL;
	this->numOfGames = 0;
	this->equity = 0;
}
GameCompany::GameCompany(std::string name)
{
	this->name = name;
	this->numOfGames = 0;
	this->games = NULL;
	this->equity = 0;
}
GameCompany::GameCompany(const GameCompany& obj)
{
	this->name = obj.name;
	this->numOfGames = obj.numOfGames;
	this->games = new Game[this->numOfGames];
	for (int i = 0; i < this->numOfGames; i++)
	{
		this->games[i] = obj.games[i];
	}
	this->equity = obj.equity;
}
GameCompany::~GameCompany()
{
	std::cout << "GameCompany::~GameCompany()" << std::endl;
	delete[] this->games;
}

void GameCompany::setName(std::string name)
{
	this->name = name;
}
void GameCompany::setEquity(double assets)
{
	if (assets < 0)
	{
		this->equity = 0;
		return;
	}
	this->equity = assets;
}
std::string GameCompany::getName()
{
	return this->name;
}
double GameCompany::getEquity()
{
	return this->equity;
}
Game& GameCompany::operator[](int id)
{
	try
	{
		if (id < 0)
			throw 1;
		if (id >= this->numOfGames)
			throw 2;
		return this->games[id];
	}
	catch (int e)
	{
		std::cout << "GameCompany::operator[](int)\t\tError - " << e << std::endl;
		std::cin.get();
		exit(0);
	}
}
bool GameCompany::addGame(Game game)
{
	Game *games_copy = new Game[this->numOfGames];
	for (int i = 0; i < this->numOfGames; i++)
		games_copy[i] = this->games[i];
	delete[] games;
	this->numOfGames++;
	games = new Game[this->numOfGames];
	for (int i = 0; i < (this->numOfGames - 1); i++)
		games[i] = games_copy[i];
	games[this->numOfGames - 1] = game;
	return true;
}
bool GameCompany::deleteGame(std::string name)
{
	int id = -1;
	for (int i = 0; i < this->numOfGames; i++)
		if (this->games[i].getName() == name)
		{
			id = i;
			break;
		}
	if (id == -1)
		return false;

	Game *games_copy = new Game[this->numOfGames];
	for (int i = 0; i < this->numOfGames; i++)
		games_copy[i] = this->games[i];
	delete[] games;
	this->numOfGames--;
	games = new Game[this->numOfGames];
	for (int i = 0; i < id; i++)
		games[i] = games_copy[i];
	for (int i = id + 1; i < (this->numOfGames + 1); i++)
		games[i - 1] = games_copy[i];
	return true;
}
void GameCompany::showInfo()
{
	std::cout << "Name of company: " << this->name << std::endl;
	std::cout << "Equity: " << this->equity << std::endl;
	std::cout << "\tGames: " << std::endl;
	for (int i = 0; i < this->numOfGames; i++)
		std::cout << i + 1 << ". " << this->games[i].getName() << std::endl;
}