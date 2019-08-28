#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;
#define year unsigned short
#define price double

class PCGame
{
private:
	char name[1024]; // name of the game
	year relYear; // release year
	price curPr; // current price 
public:
	PCGame(char * initName, year releaseYear, price currentPrice);
	PCGame(PCGame& object);
	PCGame();
	void setName(char*newName);
	void setReleaseYear(year newReleaseYear);
	void setPrice(price newPrice);
	char * getName();
	year getReleaseYear();
	price getPrice();
	void showInfo();

	PCGame operator=(PCGame& object);
	PCGame operator+(PCGame& object);
	void operator++();
};
int main(int argc, char* argv[])
{
	PCGame g1("Dota 2", 2013, 0);
	g1.showInfo();
	PCGame g2("CS:GO", 2012, 10);
	g2.showInfo();
	++g2;
	g2.showInfo();
	PCGame g3 = g1 + g2;
	g3.showInfo();

	system("pause");
	return 0;
}
//Constructors
PCGame::PCGame(char * initName, year yearOfCreation, price currentPrice)
{
	this->setName(initName);
	this->setReleaseYear(yearOfCreation);
	this->setPrice(currentPrice);
}
PCGame::PCGame(PCGame& object)
{
	this->setName(object.getName());
	this->setReleaseYear(object.getReleaseYear());
	this->setPrice(object.getPrice());
}
PCGame::PCGame()
{
	this->setName("without_name");
	this->setReleaseYear(0);
	this->setPrice(0);
}
// SET
void PCGame::setName(char*newName)
{
	strcpy(this->name, newName);
}
void PCGame::setReleaseYear(year newYearOfCreation)
{
	this->relYear = newYearOfCreation;
}
void PCGame::setPrice(price newPrice)
{
	this->curPr = newPrice;
}
//GET
char * PCGame::getName()
{
	char nameCopy[1024];
	strcpy(nameCopy, this->name);
	return nameCopy;
}
year PCGame::getReleaseYear()
{
	return this->relYear;
}
price PCGame::getPrice()
{
	return this->curPr;
}
void PCGame::showInfo()
{
	cout << "Name: " << this->name << endl;
	cout << "Release year: " << this->relYear << endl;
	cout << "Current price: " << this->curPr << endl;
}
//Operators
PCGame PCGame::operator=(PCGame& object)
{
	this->setName(object.getName());
	this->setReleaseYear(object.getReleaseYear());
	this->setPrice(object.getPrice());
	return PCGame(object);
}
PCGame PCGame::operator+(PCGame& object)
{
	PCGame pack;
	char newName[1024] = "Pack: ";
	strcat(newName, this->getName());
	strcat(newName, " + ");
	strcat(newName, object.getName());
	pack.setName(newName);
	year newYOfCr;
	if (this->getReleaseYear()<object.getReleaseYear())
		newYOfCr = this->getReleaseYear();
	else
		newYOfCr = object.getReleaseYear();
	pack.setReleaseYear(newYOfCr);
	pack.setPrice(this->getPrice() + object.getPrice());
	return pack;
}

void PCGame::operator++()
{
	this->curPr++;
}