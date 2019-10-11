#pragma once
#include "euhamgr.h"

class Ham : public EuHamGr
{
protected:
	void find();
	bool cir(int * ver);
	bool path(int * ver);
public:
	Ham(Graph graph);
	Ham(int numOfVer, int** e, int numOfE);
	Ham(const Ham& obj);
	~Ham();
	bool isSemi();
	bool is();
	void showCir();
	void showPath();
};