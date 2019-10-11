#include "stdafx.h"
#include <math.h>
#include <Windows.h>
#include <iostream>

using namespace std;
const int NotName = system("color f0");

int main()
{
	setlocale(LC_ALL, "russian");

	float a, b, c, d, e, f, g, h, res;
	a = 100;
	b = 0.001;
	c = pow(a - b, 4);
	d = pow(a, 4);
	e = 4 * a*a*a*b;
	f = 6 * a*a*b*b;
	g = 4 * a*b*b*b;
	h = pow(b, 4);

	res = (c - (d - e)) / (f - g + h);

	cout << "Result: " << res << endl;

	system("pause");
    return 0;
}

