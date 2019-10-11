#include "classes.h"
#include <iostream>
void log(std::string author, std::string message)
{
	std::cout << author << ": " << message << std::endl;
}
App::App()
	:name("noname"), owner("noname"), relYear(0), price(0)
{}
App::App(std::string name)
	: name(name), owner("noname"), relYear(0), price(0)
{}
void App::setName(std::string name)
{
	this->name = name;
}
void App::setOwner(std::string owner)
{
	this->owner = owner;
}
void App::setRelYear(unsigned short relYear)
{
	this->relYear = relYear;
}
void App::setPrice(double price)
{
	this->price = price;
}
std::string App::getName()
{
	return this->name;
}
std::string App::getOwner()
{
	return this->owner;
}
unsigned short App::getRelYear()
{
	return this->relYear;
}
double App::getPrice()
{
	return this->price;
}
Game::Game()
	: engine("noname")
{}
Game::Game(std::string name)
	: engine("noname")
{
	this->name = name;
}
void Game::setEngine(std::string engine)
{
	this->engine = engine;
}
std::string Game::getEngine()
{
	return this->engine;
}
void showInfo(const Game& game)
{
	std::cout << "Name: " << game.name << std::endl;
	std::cout << "Owner: " << game.owner << std::endl;
	std::cout << "Engine: " << game.engine << std::endl;
	std::cout << "Release year: " << game.relYear << std::endl;
	std::cout << "Price: " << game.price << std::endl;
}
OnlineGame::OnlineGame()
	: isRunning(false), users(NULL), online(0)
{}
OnlineGame::OnlineGame(std::string name)
	: isRunning(false), users(NULL), online(0)
{
	this->name = name;
}
OnlineGame::OnlineGame(const OnlineGame& obj)
{
	this->name = obj.name;
	this->engine = obj.engine;
	this->isRunning = obj.isRunning;
	this->online = obj.online;
	this->owner = obj.owner;
	this->price = obj.price;
	this->relYear = obj.relYear;
	this->users = new User[this->online];
	for (unsigned short i = 0; i < this->online; i++)
		this->users[i] = obj.users[i];
}
OnlineGame::~OnlineGame()
{
	if (this->online!=0)
		delete[] this->users;
}
void OnlineGame::start()
{
	if (this->isRunning)
	{
		log(this->name, "Cannot start the server.");
		log(this->name, "Server is already started.");
		return;
	}
	this->isRunning = true;
	log(this->name, "Server has been started.");
}
void OnlineGame::shutDown()
{
	if (!this->isRunning)
	{
		log(this->name, "Cannot shut down the server.");
		log(this->name, "Server is already shutted down.");
		return;
	}
	this->isRunning = false;
	delete[] this->users;
	this->online = 0;
	log(this->name, "Server has been shutted down.");
}
int  OnlineGame::operator<<(User& user)
{
	if (!this->isRunning)
	{
		log(this->name, (user.getNickname() + " cannot join the server."));
		log(this->name, "Server is not running.");
		return 0;
	}
	User * users_copy = new User[this->online];
	for (unsigned short i = 0; i < this->online; i++)
		users_copy[i] = this->users[i];
	delete[] this->users;
	this->online++;
	this->users = new User[this->online];
	for (unsigned short i = 0; i < (this->online - 1); i++)
		this->users[i] = users_copy[i];
	this->users[this->online - 1] = user;
	log(this->name, (user.getNickname() + " has been connected."));
	return 1;
}
void OnlineGame::showOnlineList()
{
	if (!this->isRunning)
	{
		log(this->name, "Cannot access the online list.");
		log(this->name, "Server is not running.");
		return;
	}
	std::cout << "\tOnline list (" << this->name << "): "<< std::endl;
	for (int i = 0; i < this->online; i++)
		std::cout << i + 1 <<".\t" << this->users[i].getNickname() << std::endl;
}
Human::Human()
	: name("noname")
{}
Human::Human(std::string name)
	: name(name)
{}
void Human::setName(std::string name)
{
	this->name = name;
}
std::string Human::getName()
{
	return this->name;
}
User::User()
{
	this->name = "noname";
	this->nickname = "no_nickname";
}
User::User(Human& human, std::string nickname)
{
	this->name = human.getName();
	this->nickname = nickname;
}
User::User(std::string nickname)
{
	this->name = "noname";
	this->nickname = nickname;
}
void User::setNickname(std::string nickname)
{
	this->nickname = nickname;
}
std::string User::getNickname()
{
	return this->nickname;
}