// aLab1_Exe1.cpp 

#include "pch.h"
#include <iostream>

class pINT
{
public:
	pINT();
	pINT(int);
	pINT(const pINT&);
	~pINT();
	pINT operator=(int);
	int VAL_FIRST();
	friend int TO_ADD(pINT, pINT);
protected:
	int* pFIRST;
};

class pINT_INT : public pINT
{
private:
	int* pSECOND;
public:
	pINT_INT();
	pINT_INT(const pINT_INT&);
	~pINT_INT();
	pINT_INT operator=(int[2]);
	int& operator[](const int);
	void TO_SET_FIRST(int);
	void TO_SET_SECOND(int);
	int VAL_SECOND();
	friend int TO_ADD(pINT_INT);
};
int TO_ADD(pINT, pINT);
int TO_ADD(pINT_INT);

int main()
{
	int arr[2] = { 1, 2 };
	pINT_INT VAR;
	VAR = arr;
	std::cout << "First: " << VAR.VAL_FIRST() << std::endl;
	std::cout << "Second: " << VAR.VAL_SECOND() << std::endl;
	std::cout << "Sum: " << TO_ADD(VAR) << std::endl << std::endl;

	pINT VAR_1(1), VAR_2(2);
	std::cout << "First: " << VAR_1.VAL_FIRST() << std::endl;
	std::cout << "Second: " << VAR_2.VAL_FIRST() << std::endl;
	std::cout << "Sum: " << TO_ADD(VAR_1, VAR_2) << std::endl;

	VAR[0] = 4;
	std::cout << "New: " << VAR[0] << std::endl;

	system("pause");
	return 0;
}

pINT::pINT()
{
	this->pFIRST = new int;
}
pINT::pINT(int VAL)
{
	this->pFIRST = new int;
	*this->pFIRST = VAL;
}
pINT::pINT(const pINT& obj)
{
	this->pFIRST = new int;
	*this->pFIRST = *obj.pFIRST;
}
pINT::~pINT()
{
	delete this->pFIRST;
}
pINT pINT::operator=(int VAL)
{
	*this->pFIRST = VAL;
	return *this;
}
int pINT::VAL_FIRST()
{
	return *this->pFIRST;
}


pINT_INT::pINT_INT()
{
	this->pSECOND = new int;
}
pINT_INT::pINT_INT(const pINT_INT& obj)
{
	this->pSECOND = new int;
	this->TO_SET_FIRST(*obj.pFIRST);
	this->TO_SET_SECOND(*obj.pSECOND);
}
pINT_INT::~pINT_INT()
{
	delete this->pSECOND;
}
pINT_INT pINT_INT::operator=(int VAL[2])
{
	*this->pFIRST = VAL[0];
	*this->pSECOND = VAL[1];
	return *this;
}
int pINT_INT::VAL_SECOND()
{
	return *this->pSECOND;
}
void pINT_INT::TO_SET_FIRST(int VAL)
{
	*this->pFIRST = VAL;
}
void pINT_INT::TO_SET_SECOND(int VAL)
{
	*this->pSECOND = VAL;
}
int& pINT_INT::operator[](const int id)
{
	try
	{
		if (id < 0 || id>1)
			throw 1;
		if (id == 0)
			return *(this->pFIRST);
		else
			return *(this->pSECOND);
	}
	catch (int e)
	{
		exit(e);
	}
}

int TO_ADD(pINT VAR_1, pINT VAR_2)
{
	return VAR_1.VAL_FIRST() + VAR_2.VAL_FIRST();
}
int TO_ADD(pINT_INT VAR)
{
	return VAR.VAL_FIRST() + VAR.VAL_SECOND();
}