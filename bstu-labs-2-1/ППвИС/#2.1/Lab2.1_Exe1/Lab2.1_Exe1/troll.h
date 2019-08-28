// File: troll.h
// Date of creation: 10/5/2018
// Date of modification:
//
// Description:
//

#pragma once

#include <iostream>
#include "unit.h"

class Troll : public Unit
{
public:
	Troll();
	Troll(std::string initName);
	void attack(Unit& victim);
};