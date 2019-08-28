#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(IteratorMarginEquation)
		{
			char hello[] = "hello";
			Assert::AreEqual((int)strlen(hello), 5);
		}

	};
}

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<> static std::wstring ToString<std::vector<int>>(const std::vector<int>& vec)
			{
				std::wstring wsRes;
				for (int i : vec)
					wsRes += std::to_wstring(i);
				return wsRes;
			}
			template<> static std::wstring ToString<std::vector<int>::iterator>(const std::vector<int>::iterator& it)
			{
				return std::to_wstring(*it);
			}
		}
	}
}