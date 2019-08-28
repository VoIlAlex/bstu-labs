
#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

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
	if (argc != 2)
		return -1;

	int64_t n = atof(argv[1]);

	auto vecDiv = TrialDivision(n);
	std::cout << "Prime deviders: ";
	for (auto div : vecDiv)
		std::cout << div << " ";
	std::endl(std::cout);

	auto vecPrimes = SieveOfEratosthenes(n);
	std::cout << "Prime numbers until " << n << ": ";
	for (auto prime : vecPrimes)
		std::cout << prime << " ";
	std::cout << std::endl;

	std::cout << "Fermat factorization response: " << FermatFactorization(n, n*n) << std::endl;

	getchar();
}

