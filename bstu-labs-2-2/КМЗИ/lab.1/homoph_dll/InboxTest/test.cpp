#include "pch.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

std::vector<int> fnParseLine(const std::string& sLine) throw(std::exception)
{
	std::vector<int> vecResult;

	std::string sCurrent;
	for (int i = 1; i < sLine.length(); i++)
	{
		if (sLine[i] == ' ')  // a,|     |5,3 
			continue;
		else if (sLine[i] == ',') // a|,|5|,|3
		{
			if (!sCurrent.length())
				continue;
			// trying to convert another element from .csv to int. If cannot then throw an exception
			try
			{
				vecResult.push_back(boost::lexical_cast<int>(sCurrent));
				sCurrent.clear();
			}
			catch (boost::bad_lexical_cast e)
			{
				throw std::exception("Wrong element in line");
			}
		}
		else
		{
			sCurrent += sLine[i];
			if (i == sLine.length() - 1)
			{
				try
				{
					vecResult.push_back(boost::lexical_cast<int>(sCurrent));
					sCurrent.clear();
				}
				catch (boost::bad_lexical_cast e)
				{
					throw std::exception("Wrong element in line");
				}
			}
		}
	}

	return vecResult;
}

TEST(TestCaseName, TestName) {

	std::vector<int> parsed = fnParseLine("a,  12, 123, 1 ");
	std::vector<int> expected{ 12, 123, 1 };
	EXPECT_EQ(parsed, expected);

}