#pragma once
#include <string>
class Game
{
	std::string name;
	unsigned short yearOfRelease;
	double price;
public:
	Game();
	Game(std::string name, unsigned short yearOfRelease, double price);
	std::string getName();
	unsigned short getYearOfRelease();
	double getPrice();
	void setName(std::string newName);
	void setYearOfRelease(unsigned short newYearOfRelease);
	void setPrice(double newPrice);
	void get(std::string& str);
	void get(unsigned short& u_sh);
	void get(double& d);
	void get(std::string& str, unsigned short& u_sh, double& d);
	void set(const std::string& str);
	void set(const unsigned short& u_sh);
	void set(const double& d);
	void set(const std::string& str, const unsigned short& u_sh, const double& d);
	void showInfo();
};