#include "stdafx.h"
#include <Windows.h>
#include <cmath>

using namespace std;
const int NotName = system("color f0");

int main()
{
	int N;
	printf("Wwedite N: ");
	scanf_s("%d", &N);

	float num_f;
	double num_last, num_dlast, num, res_1 = 0, res_2 = 1, res_3 = 0, res_4 = 1, res_5 = 0, res_6 = 1, res_7 = 0, res_8 = 0, res_9 = 0;

	for (int i = 0; i < N; i++) {

		if (i > 1)
			num_dlast = num_last;

		if (i > 0)
			num_last = num;

		printf("Wwedite chislo ");
		printf("%d", i + 1);
		printf(": ");
		scanf_s("%f", &num_f);
		num = num_f;

		if (i > 0 && i < N-1) {
			res_1 += pow(num, 2);												//1
			res_2 *= num + i + 1;													//2
		}

		res_3 += num / (double)N;												//3
		res_4 *= pow(num, 1 / (double)N);										//4

		if (i > 1) {
			res_5 += num_last * num;											//5
		}

		if (i > 0) {
			res_6 *= num_last + num;											//6
			res_7 += num_last / (fabs(num) + 1);								//7
		}

		if (i > 1 && num_last>0) {
			res_8 += pow(num_last, num);										//8
		}

		if (i > 1) {
			res_9 += num_dlast* num_last * num;									//9
		}
	}

	printf("1) %f\n2) %f\n3) %f\n4) %f\n5) %f\n6) %f\n7) %f\n8) %f\n9) %f\n", res_1, res_2, res_3, res_4, res_5, res_6, res_7, res_8, res_9);

	system("pause");
    return 0;
}

