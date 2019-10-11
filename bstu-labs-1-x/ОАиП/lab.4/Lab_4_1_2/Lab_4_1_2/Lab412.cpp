#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;
const int NotName = system("color f0");

int main()
{
	setlocale(LC_ALL, "russian");

	int n, m;

	cout << "¬ведите n: ";
	cin >> n;
	cout << "\n¬ведите m: ";
	cin >> m;
	cout << endl;

	int res1, res2, res3;

	res1 = n++ * m;
	res2 = n++ < m;
	res3 = m-- > m;

	cout << "n++ * m = " << res1 << endl;
	cout << "n++ < m = " << res2 << endl;
	cout << "m-- > m = " << res3 << endl;

	system("pause");
    return 0;
}

