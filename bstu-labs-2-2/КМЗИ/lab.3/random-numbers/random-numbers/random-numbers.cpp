// random-numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "lfsr.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <conio.h>

namespace mp = boost::multiprecision;

namespace po = boost::program_options;

#define NOT_PRIME 0
#define PROBABLY_PRIME 1
#define SAVE_PRIME 2

int isPrime(mp::cpp_int& mpNumber)
{
	if (mpNumber % 2 == 0)
	{
		return NOT_PRIME;
	}

	else
	{
		boost::random::mt19937 gen(clock());
		if (mp::miller_rabin_test(mpNumber, 25, gen))
		{
			if (mp::miller_rabin_test((mpNumber - 1) / 2, 25, gen))
				return SAVE_PRIME;
			else
				return PROBABLY_PRIME;
		}
	}
	return NOT_PRIME;
}


int main(int argc, char *argv[])
{

	LFSR lfsr(6);
	lfsr.SetMin(0);
	lfsr.SetMax(1000);
	// mask
	lfsr.SetA({ 1, 0, 0, 1, 0, 0, 1 });
	// initial S vector
	lfsr.SetS([]() -> unsigned int {
		static boost::random::mt19937 gen(clock()); // yes, I use random generator to produce random generator
		return static_cast<unsigned int>(gen());
	});
	// forward n times
	// to get rid of initial values
	lfsr.Init();

	// !!!!!!!!!!!!!!!!!!!!! //
	constexpr int sequenceLength = 23;
	bool bFound = false;
	for(;;)
	{
		system("cls");
		std::stringstream ss;
		for (int i = 0; i < sequenceLength; i++)
			ss << std::to_string(lfsr.Front());
		
		mp::cpp_int mpNumber;
		try
		{
			mpNumber = static_cast<mp::cpp_int>(ss.str());
		}
		catch (...)
		{
			continue;
		}
		std::cout << mpNumber << std::endl;
		int ret;
		if ((ret = isPrime(mpNumber)) == SAVE_PRIME)
		{
			std::cout << "Save prime" << std::endl;
			bFound = true;
			break;
		}
		else if (ret == PROBABLY_PRIME)
		{
			std::cout << "Probably prime" << std::endl;
		}
		else
		{
			std::cout << "Not prime! " << std::endl;
		}
	}
	
	system("pause");

}

