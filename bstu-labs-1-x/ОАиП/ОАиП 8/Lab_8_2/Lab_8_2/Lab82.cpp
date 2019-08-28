#include "stdafx.h"
#include <Windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	char str[100] = "";
	gets_s(str);
	char str_max[100] = "";
	char str_now[100] = "";

	int i = 0, x = 0, online = 0, size, max_size = 0;
	/* Нахождение наибольшей подстроки a...b, вывод её в str_max  */
	while (str[i] != '\0')
	{
		if (online == 0 && str[i] == 'a')
		{
			str_now[x] = str[i];
			online = 1;
			size = 1;
			x++;
		}
		else if (online == 1 && str[i] != 'b')
		{
			size++;
			str_now[x] = str[i];
			x++;

		}
		else if (online == 1 && str[i] == 'b')
		{
			size++;
			str_now[x] = str[i];
			if (size > max_size)
			{
				max_size = size;
				for (int y = 0; y < 100; y++) {
					str_max[y] = str_now[y];
				}
			}
			for(int y = 0; y < 100; y++)
			{
				str_now[y] = '\0';
			}
			x = 0;
			online = 0;
		}

		i++;
	}

	/* Если строки нет */
	if ((online == 1 && str_max[0] == '\0') || (online == 0 && str_max[0] == '\0'))
	{
		printf("Stroki net!\n");
		system("pause");
		return 0;
	}

	printf("Maximum simwolow: %d\nStr: %s\n", max_size, str_max);

	system("pause");
    return 0;
}

