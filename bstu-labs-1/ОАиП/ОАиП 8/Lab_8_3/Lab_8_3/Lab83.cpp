#include "stdafx.h"
#include <Windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	char result[100] = "";
	int res_i = 0;

	char word[6][100] = { "THIS", "IS", "A", "TABLE", "HELLO","\0"};
	char translate[6][100] = {"ETO", "", "", "STOL", "PRIVET", "\0"};
	
	char str[100] = "";
	gets_s(str);

	char word_now[100] = "";

	int i = 0, x = 0;
	while(str[x]!='\0')
	{
		i = 0;
		while (str[x] != '_')
		{
			word_now[i] = str[x];
			if (str[x + 1] == '\0')
				break;
			i++;
			x++;
		}
		x++;
		int sovpadenie = -1;
		i = 0;
		while (strcmp(word[i],"\0"))
		{
			if (!(strcmp(word[i], word_now)))
			{
				sovpadenie = i;
				break;
			}
			i++;
		}

		if (sovpadenie == -1)
		{
			if (res_i && strcmp(word_now, ""))
			{
				result[res_i] = '_';
				res_i++;
			}
			i = 0;
			while (word_now[i] != '\0')
			{
				result[res_i] = word_now[i];
				i++; res_i++;
			}
		}
		else
		{
			if (res_i && strcmp(translate[sovpadenie], ""))
			{
				result[res_i] = '_';
				res_i++;
			}
			i = 0;
			while (translate[sovpadenie][i] != '\0')
			{
				result[res_i] = translate[sovpadenie][i];
				i++;  res_i++;
			}
		}
		i = 0;
		while (word_now[i] != '\0')
		{
			word_now[i] = '\0';
			i++;
		}
	}

	printf("%s\n", result);

	system("pause");
    return 0;
}

