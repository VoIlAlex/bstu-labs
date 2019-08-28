#include "stdafx.h"
#include <Windows.h>
#include <cstdio>
#include <cmath>

using namespace std;
const int NotName = system("color f0");

int main()
{
	int num;
	printf("Enter: ");
	scanf_s("%d", &num);

	{int len = 1;
	while (1) {
		double t = pow(10.0, (double)len - 1.0);
		if ((double)num / t >= 10.0)
			len++;
		else
			break;
	}

	if (len != 3) {
		system("pause");
		return 0;
	}}

	int n1 = num / 100, n2 = num / 10 - n1 * 10, n3 = num - n1 * 100 - n2 * 10, sum = n1 + n2 + n3;
	if (sum % 2 == 0) 
		printf("\nSumma zifr chetnaya\n");
	else
		printf("\nSumma zifr nechetnaya\n");
	

	system("pause");
    return 0;
}

