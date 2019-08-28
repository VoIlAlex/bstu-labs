#include "stdafx.h"
#include <Windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	int a, b;
	double X;
	printf("a=");
	scanf_s("%d", &a);
	printf("\nb=");
	scanf_s("%d", &b);

	if (a > b)
		X = (a*b) + 1;
	else if (a == b)
		X = 25;
	else
		X = (double)(a - 5) / (double)b;

	printf("\nX=%f", X);

	system("pause");
    return 0;
}

