#include "stdafx.h"
#include <stdio.h>
#include <windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	double d = 3.2, x;
	int    i = 2, y;

	x = (y = d / i) * 2;
	printf("x = %.8g\t", (double)(x));
	printf("y = %.8g\t", (double)(y));

	y = (x = d / i) * 2;
	printf("x = %.8g\t", (double)(x));
	printf("y = %.8g\t\n", (double)(y));

	y = d * (x = 2.5 / d);
	printf("y = %.8g\t\n", (double)(y));

	x = d * (y = ((int)2.9 + 1.1) / d);
	printf("x = %.8g\t", (double)(x));
	printf("y = %.8g\t\n", (double)(y));

	system("pause");
	return 0;
}

