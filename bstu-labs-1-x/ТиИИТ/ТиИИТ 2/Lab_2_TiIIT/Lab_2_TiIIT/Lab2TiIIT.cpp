#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	long double x0 = 1.5, x = x0, x_1 = x0;
	long double f;
	long double f_pr;

	int end = 1;

	goto cycle;
	
	while ((x - x_1) >= 0.01 || (x_1-x) >=0.01) {
	cycle:
		x = x_1;
		f = 2 * x*x*x*x - 2;
		f_pr = ((2 * (x + 0.000001) *(x + 0.000001)*(x + 0.000001)*(x + 0.000001) - 2 - f) / 0.000001);
		x_1 = x - f / f_pr;
		cout << x << endl;
	}
	cout << end << " корень = " << x << endl << endl;

	if(end==1){
		end++;
		x0 = -1.5;
		x = x0;
		x_1 = x0;
		goto cycle;
	}
	else {
		goto end;
	}
	
	end:

	system("pause");
    return 0;
}

