#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	setlocale(LC_ALL, "russian");

	float st;
	printf("������� ����� ������� ������������: ");
	scanf_s("%f", &st);
	float S = pow(st, 2)*pow(3, 0.5) / 4;
	printf("\a������� ������������ ����� %f\n", S);

	system("pause");
    return 0;
}

