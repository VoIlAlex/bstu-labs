#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <Windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	int n;
	float x_f;
	printf("n = ");
	scanf_s("%d", &n);
	printf("x = ");
	scanf_s("%f", &x_f);

	double x = (double)x_f;

	double num, num_1, num_2;
	double num_now = 0.0, num_now_val = 1.0;

	for (int k = 1; k <= n; k++) 
	{
		num = pow(M_E, cos(pow(x, 2.0*(double)k)))*sin(pow(x, 3.0*(double)k));
		num_1 = num - (int)num;
		num_2 = 1 - num_1;
		if (num_1 <= num_2)
		{
			if (num_1 <= num_now_val)
			{
				num_now_val = num_1;
				num_now = num;
			}
		}
		else 
		{
			if (num_2 <= num_now_val)
			{
				num_now_val = num_2;
				num_now = num;
			}
		}
	}

	printf("Blijnee k zelomu: %f\n", num_now);

	system("pause");
    return 0;
}

