#include "stdafx.h"
#include <Windows.h>
#include <cmath>

using namespace std;
const int NotName = system("color f0");

int main()
{
	double ** pr;
	pr = new double*[2];// координаты 2-х крайних точек пр€моугольника
	char xy[] = "xy";
	printf("Zadanie 2 tochek pryamougolnika: \n");
	/* ввод 2-х точек пр€моугольника */
	for (int i = 0; i < 2; i++)	
	{
		int el = i + 1;
		pr[i] = new double[2];
		for (int k = 0; k < 2; k++) 
		{
			float pr_f;
			printf("%c %d-i tochki: ", xy[k], el);
			scanf_s("%f", &pr_f);
			pr[i][k] = pr_f;
		}
	}

	double st[2][2];	// {{лева€, права€}, {нижн€€, верхн€€}} 
	st[0][0] = (pr[0][0] + pr[1][0] - fabs(pr[0][0] - pr[1][0])) / 2;
	st[0][1] = pr[0][0] + pr[1][0] - st[0][0];
	st[1][0] = (pr[0][1] + pr[1][1] - fabs(pr[0][1] - pr[1][1])) / 2;
	st[1][1] = pr[0][1] + pr[1][1] - st[1][0];

	int N;//количество точек
	printf("\nWwedite N: ");
	scanf_s("%d", &N);
	if (N < 0 || N>100)
		system("pause");
	double ** t = new double*[N];
	/* ввод точек */
	for (int i = 0; i < N; i++) 
	{
		int el = i + 1;
		t[i] = new double[2];
		for (int k = 0; k < 2; k++) 
		{
			float t_f;
			printf("%c %d-i tochki: ", xy[k], el);
			scanf_s("%f", &t_f);
			t[i][k] = t_f;
		}
		printf("\n");
	}

	printf("Whodyat w pryamougolnik tochki: ");
	double min_val = -1;// минимальное рассто€ние до пр-ка
	int min_num;// номер ближней точки
	/* вывод вход€щих в пр€моугольник точек, нахождение минимума */
	for (int i = 0; i < N; i++) 
	{
		if (t[i][0] >= st[1][0] && t[i][0] <= st[1][1] && t[i][1] >= st[0][0] && t[i][1] <= st[0][1])
		{
			printf("%d ", i+1);
			double min_now = -1;
			for (int k = 0; k < 2; k++) 
			{
				for (int z = 0; z < 2; z++) 
				{
					double min = fabs(t[i][k] - st[k][z]);
					if (min < min_now || min_now == -1)
						min_now = min;
				}
			}
			if (min_now < min_val || min_val == -1)
			{
				min_val = min_now;
				min_num = i;
			}

		}
	}

	printf("\n Minimalnoye rasstoyaniye do pryamougolnika %f u tochki nomer %d", min_val, min_num + 1);
	printf("\n");

	system("pause");
    return 0;
}

