#pragma once

#include <string>
#include "game.h"

class GameCompany
{
	std::string name;
	Game * games;
	int numOfGames;
	double equity;
public:
	GameCompany();
	GameCompany(std::string name);
	GameCompany(const GameCompany& obj);
	~GameCompany();
	void setName(std::string);
	void setEquity(double assets);
	std::string getName();
	double getEquity();
	Game& operator[](int id);
	bool addGame(Game game);
	bool deleteGame(std::string name);
	void showInfo();
};