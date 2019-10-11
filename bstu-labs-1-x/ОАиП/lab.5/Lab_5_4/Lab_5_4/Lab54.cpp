#include "stdafx.h"
#include <Windows.h>

using namespace std;
const int NotName = system("color f0");

int main()
{
	int choice, mass;
	double mass_kg;
	printf("1 - kilogram\n2 - milligram\n3 - gram\n4 - ton\n5 - centner\nYour choice: ");
	scanf_s("%d", &choice);
	printf("\nWeight: ");
	scanf_s("%d", &mass);

	if (choice == 1)
		mass_kg = (double)mass;
	else if (choice == 2)
		mass_kg = (double)mass / 1000000;
	else if (choice == 3)
		mass_kg = (double)mass / 1000;
	else if (choice == 4)
		mass_kg = (double)mass * 1000;
	else if (choice == 5)
		mass_kg = (double)mass * 100;
	else
		return 0;

	printf("Mass in kg = %f", mass_kg);

	system("pause");
	return 0;
}
