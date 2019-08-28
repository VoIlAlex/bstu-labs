#include "stdafx.h"
#include "euhamgr.h"

EuHamGr::EuHamGr() {}
EuHamGr::~EuHamGr()
{
	for (int i = 0; i < this->numOfPathE; i++)
	{
		delete[] this->pathE[i];
	}
	delete[] pathE;

	for (int i = 0; i < this->numOfCirE; i++)
	{
		delete[] this->cirE[i];
	}
	delete[] cirE;
}