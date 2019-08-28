// Lab1_Exe2.cpp

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

class rTriangle // right triangle
{
private:
	double fCath; // first cathetus
	double sCath; // second cathetus
	double hypot; // hypotenuse
public:
	rTriangle();
	rTriangle(rTriangle& obj);
	rTriangle(double fCath, double sCath);
	void setFCath(double val);
	void setSCath(double val);
	double getFCath();
	double getSCath();
	double getHypot();
	void getInfo();

	const rTriangle operator=(rTriangle& obj);
	const rTriangle operator*(rTriangle& obj);
	void operator~();
};

int main(int argc, char* argv[])
{
	rTriangle t1(3.0, -4.0);
	t1.getInfo();
	~t1;
	t1.getInfo();
	system("pause");
	return 0;
}

// Constructors
rTriangle::rTriangle()
{
	this->setFCath(3.0);
	this->setSCath(4.0);
	this->hypot = 5.0;
}
rTriangle::rTriangle(rTriangle& obj)
{
	this->setFCath(obj.getFCath());
	this->setSCath(obj.getSCath());
	this->hypot = obj.getHypot();
}
rTriangle::rTriangle(double fCath, double sCath)
{
	this->setFCath(fCath);
	this->setSCath(sCath);
	this->hypot = sqrt(pow(fCath, 2.0)+pow(sCath, 2.0));
}
// GET
void rTriangle::getInfo()
{
	cout << "First cathetus: " << this->fCath << endl;
	cout << "Second cathetus: " << this->sCath << endl;
	cout << "Hypotenuse: " << this->hypot << endl;
}
double rTriangle::getFCath()
{
	return this->fCath;
}
double rTriangle::getSCath()
{
	return this->sCath;
}
double rTriangle::getHypot()
{
	return this->hypot;
}
//SET
void rTriangle::setFCath(double val)
{
	if(val < 0) val = -val;
	this->fCath = val;
	this->hypot = sqrt(pow(this->fCath, 2.0)+pow(this->sCath, 2.0));
}
void rTriangle::setSCath(double val)
{
	if(val < 0) val = -val;
	this->sCath = val;
	this->hypot = sqrt(pow(this->fCath, 2.0)+pow(this->sCath, 2.0));
}
// Overloaded operators
const rTriangle rTriangle::operator=(rTriangle& obj)
{
	this->fCath = obj.getFCath();
	this->sCath = obj.getSCath();
	this->hypot = obj.getHypot();
	return rTriangle((*this));
}
const rTriangle rTriangle::operator*(rTriangle& obj)
{
	rTriangle res;
	res.fCath = this->fCath * obj.getFCath();
	res.sCath = this->sCath * obj.getSCath();
	res.hypot = sqrt(pow(res.fCath, 2.0)+pow(res.sCath, 2.0));
	return res;
}
void rTriangle::operator~()
{
	double fCath_copy = this->fCath;
	this->fCath = this->sCath;
	this->sCath = fCath_copy;
}
	