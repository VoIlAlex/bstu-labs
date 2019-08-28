#include "stdafx.h"
#include <Windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	char str[100] = "";
	gets_s(str);

	char str_8r[100] = ""; // 8-ричные числа через ,-ю
	int online = 0;
	int num = 1, i = 0, x = 0;
	
	/* вывод 8-ричныз чисел и перенос их в массив */
	while(str[i]!='\0')
	{
		char ch = str[i];
		if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8')
		{
			if(online==0)
			{
				online = 1;
				str_8r[x] = ch;
				//printf("\n%d - %c", num, str_8r[x]);
				num++;
				x++;
			}
			else
			{
				str_8r[x] = ch;
				printf("%c", str_8r[x]);
				x++;
			}
		}
		else
		{
			if(online==1)
			{
				online = 0;
				str_8r[x] = ',';
				x++;
				str_8r[x] = ' ';
				x++;
			}
		}
		i++;
	}

	printf("%s\n", str_8r);

	system("pause");
    return 0;
}

