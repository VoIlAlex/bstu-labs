#include "pch.h"
#include <iostream>
#include <chrono>
#include <my_code/timer.hxx>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>

namespace mp = boost::multiprecision;

int main()
{
	
	system("pause");
}

void old_main()
{
	mp::cpp_int testNumber1, testNumber2;
	testNumber1 = static_cast<mp::cpp_int>("123124123124132131251323");
	testNumber2 = static_cast<mp::cpp_int>("12341548109324");

	boost::random::mt11213b base_gen(clock());
	boost::random::independent_bits_engine<boost::random::mt11213b, 256, mp::cpp_int> gen(base_gen);
	boost::random::mt19937 gen2(clock());

	for (unsigned i = 0; i < 100000; ++i)
	{
		mp::cpp_int n = gen();
		if (mp::miller_rabin_test(n, 25, gen2))
		{
			std::cout << "Probable prime number: " << n << std::endl;
			if (mp::miller_rabin_test((n - 1) / 2, 25, gen2))
			{
				std::cout << "Save prime number: " << n << std::endl;
			}
		}
	}

	system("pause");
}