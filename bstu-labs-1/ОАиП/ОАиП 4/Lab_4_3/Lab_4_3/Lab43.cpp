#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	setlocale(LC_ALL, "russian");

	float x, y;
	printf("Введите значения\n\tx: ");
	scanf_s("%f", &x);
	printf("\ty: ");
	scanf_s("%f", &y);

	float res1 = 1.7*pow(10, -3.0)*tan(x*y) + 7.2*pow(cos(pow(x, 2.0)), 3.0);
	float res2 = 1.1*pow(x*y, 1.0 / 5.0)*(1 + pow(x, 3));
	float res = res1 / res2;
	printf("Значение функции равно %f\n", res);

	system("pause");
	return 0;
}

