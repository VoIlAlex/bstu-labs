#include "stdafx.h"
#include "CppUnitTest.h"
#include "../random-numbers/lfsr.h"
#include "../random-numbers/lfsr.cpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace mp = boost::multiprecision;

namespace primaritytest
{		
	TEST_CLASS(PrimarityTest)
	{
	public:
		
		TEST_METHOD(Boost)
		{
			
		}

	};
}