#include "stdafx.h"
#include <Windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	int x, y;
	printf("Enter x: ");
	scanf_s("%d", &x);
	printf("\nEnter y: ");
	scanf_s("%d", &y);

	if (x == 0 && y == 0)
		printf("\n1");
	else if (x == 0)
		printf("\n2");
	else if (y == 0)
		printf("\n3");
	else
		printf("\n0");


	system("pause");
    return 0;
}

