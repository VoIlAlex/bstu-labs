#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>

using namespace std;

void subsets(int, int);

int main()
{
	int n = 9, k = 8;
	subsets(n, k);
	system("pause");
    return 0;
}

void subsets(int n, int k)
{
	int shift = 1;
	if (n < k) 
	{
		cout << "Error!" << endl;
		return;
	}
	int * marks = new int[k];
	for (int i = 0; i < k; i++)
		marks[i] = i;

	int * arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = i + shift;

	int mark = k - 1;
	while (1)
	{
		for (int i = 0; i < k; i++)
			cout << arr[marks[i]] << " ";
		cout << endl;

		bool doInc = true;
		if (marks[mark] == (n - k + mark))
		{
			doInc = false;
			while (marks[mark] == (n - k + mark))
			{
				mark--;
				if (mark == -1)
					return;
			}
			for (int i = mark, j = ++marks[mark]; i < k; i++, j++)
				marks[i] = j;
			mark = k - 1;
			while (marks[mark-1] == (n - k + mark))
			{
				mark--;
				if (mark == -1)
					return;
			}
		}
		if(doInc)
			marks[mark]++;
	}
}