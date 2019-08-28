
#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <iomanip>

std::vector<__int64> TrialDivision(__int64 n)
{
	std::vector<__int64> vecRes;
	int f = 2;
	while (n > 1)
	{
		if (n % f == 0)
		{
			vecRes.push_back(f);
			n /= f;
		}
		else
			f++;
	}
	return vecRes;
}

std::vector<int> SieveOfEratosthenes(int n)
{
	std::vector<int> vecSieve(n);
	std::generate(vecSieve.begin(), vecSieve.end(), []() {
		static int i = 1;
		return i++;
	});

	int f = 2;
	std::vector<bool> vecMask(vecSieve.size());
	std::fill(vecMask.begin(), vecMask.end(), true);
	while (true)
	{

		for (int i = f; i < vecSieve.size(); i++)
		{
			if (vecSieve[i] % f == 0)
				vecMask[i] = false;
		}
		
		int i = f;
		for (; i < vecSieve.size(); i++)
		{
			if (vecMask[i] == true)
			{
				f = vecSieve[i];
				break;
			}
		}
		if (i == vecSieve.size())
			break;
	} 

	for (int i = 0; i < vecSieve.size();)
	{
		if (vecMask[i] == false)
		{
			vecSieve.erase(vecSieve.begin() + i);
			vecMask.erase(vecMask.begin() + i);
			continue;
		}
		i++;
	}
	return vecSieve;
}

bool FermatFactorization(int n, int n0)
{
	if (n % 2 == 0)
		return false;
	int a = ceil(sqrt(n));
	for (int i = 0; i < n0; i++)
	{
		int substr = (a + i)*(a + 1) - n;
		int sr = sqrt(substr);
		if (sr * sr == substr)
			return false;
	}
	return true;
}




int main(int argc, char *argv[])
{
	int n;
	std::cin >> n;
	for (int i = 0; i < sizeof(int) * 8; i++)
	{
		std::cout << std::setw(10) << n;
		if ((i+1) % 3 == 0) std::cout << std::endl;
		n >>= 1;

	}
	system("pause");
}

