bool IsPrime(int x)
{
	bool bIsPrime = true;
	for (int i = x / 2; i > 1; i--)
	{
		if (x % i == 0)
		{
			bIsPrime = false;
			break;
		}
	}
	return bIsPrime;
}
int Eul(int x)
{
	if (x <= 0)
		throw std::exception("X must be greater than 0");
	if (x == 1 || x == 2)
		return 1;
	int nCount = 0;
	for (int i = 1; i < x; i++)
	{
		bool bIsCompire = true;
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0) if (x % j == 0)
			{
				bIsCompire = false;
				break;
			}
		}
		bIsCompire && nCount++;
	}
	return nCount;
}

bool IsPrimitiveRoot(int x, int m)
{
	int nEul = Eul(m);
	bool bIsPrimitiveRoot = static_cast<int>(pow(x, nEul)) % m == 1;
	if (!bIsPrimitiveRoot)
		return false;
	for (int i = 1; i < nEul; i++)
		if (static_cast<int>(pow(x, i)) % m == 1)
		{
			bIsPrimitiveRoot = false;
			break;
		}
	return bIsPrimitiveRoot;
}

std::vector<int> FindPrimitiveRoots(int m)
{
	std::vector<int> vecResult;
	for (int i = 1; i < m; i++)
		if (IsPrimitiveRoot(i, m)) vecResult.push_back(i);
	return vecResult;
}