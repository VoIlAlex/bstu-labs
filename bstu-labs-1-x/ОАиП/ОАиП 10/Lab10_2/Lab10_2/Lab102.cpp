#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
const int notName = system("color f0");

char * WordK(char*, int);

int main()
{
	char S[1024];
	cout << " Enter the sentence: ";
	gets_s(S);
	char ** K = new char*[3];

	for (int i = 1; i < 4; i++)
	{
		int numOfWord;
		cout << "\nEnter the number of word: "; cin >> numOfWord;
		K[i-1] = WordK(S, numOfWord);
		cout << endl << " Word: ";
		int j = 0;
		while (K[i-1][j] != '\0')
		{
			cout << K[i-1][j]; j++;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

char * WordK(char * S, int K)
{
	int wordN = 0, i = 0, iW = 0;
	char * word = new char[1024];
	while (1)
	{
		char * chPointer = word + iW;
		if (!iW)
		{
			if (S[i] == ' ') { i++; continue; }
			else if (S[i] == '\0') return "";
			else { *chPointer = S[i]; i++; iW++; }
		}
		else
		{
			if (S[i] == ' ' || S[i] == '\0')
			{
				*chPointer = '\0';
				iW = 0;
				wordN++;
				if (wordN == K) return word;
				else if (S[i] == '\0') return "";
				i++;
			}
			else { *chPointer = S[i]; iW++; i++; }
		}
	}
}