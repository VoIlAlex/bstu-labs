#pragma once
#include <string>
void log(std::string author, std::string message);
class App
{
protected:
	std::string name;
	std::string owner;
	unsigned short relYear;
	double price;
public:
	App();
	App(std::string name);
	void setName(std::string name);
	void setOwner(std::string owner);
	void setRelYear(unsigned short relYear);
	void setPrice(double price);
	std::string getName();
	std::string getOwner();
	unsigned short getRelYear();
	double getPrice();
};
class Game : public App
{
protected:
	std::string engine;
public:
	Game();
	Game(std::string name);
	void setEngine(std::string engine);
	std::string getEngine();
	friend void showInfo(const Game& game);
};
void showInfo(const Game& game);
class Human
{
protected:
	std::string name;
public:
	Human();
	Human(std::string name);
	void setName(std::string name);
	std::string getName();
};
class User : Human
{
protected:
	std::string nickname;
public:
	User();
	User(std::string nickname);
	User(Human& human, std::string nickname);
	void setNickname(std::string);
	std::string getNickname();
};
class OnlineGame : public Game
{
	bool isRunning;
	User * users;
	unsigned int online;
public:
	OnlineGame();
	OnlineGame(std::string name);
	OnlineGame(const OnlineGame& obj);
	~OnlineGame();
	void start();
	void shutDown();
	int operator<<(User& user);
	void showOnlineList();
};

