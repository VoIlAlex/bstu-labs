#include <iostream>
#include <iomanip>
#include <cmath>
#include <iomanip>

constexpr int N = 3;
constexpr int EDUCATION = 30;
constexpr int FORECAST = 15;
constexpr double ALPHA = 0.2;

double func(double x)
{
	double a = 1.0, b = 5.0, d = 0.1;
	return (a * sin(b * x) + d);
}

int main()
{
	double x[EDUCATION + FORECAST]; // input
	double t[EDUCATION + FORECAST]; // model result
	double y[EDUCATION + FORECAST]; // net result

	// filling input and model result
	for (int i = 0; i < (EDUCATION + FORECAST); i++)
	{
		x[i] = (double)i * 0.1;
		t[i] = func(x[i]);
	}

	for (int i = 0; i < N; i++)
		y[i] = t[i];

	// net
	double W[N];
	double T;
	for (int i = 0; i < N; i++)
		W[i] = (double)(rand() % 9000 + 1000) / 1000.0;
	T = (double)(rand() % 9000 + 1000) / 1000.0;

	// training
	double Em = 0.000000001; // minumum error
	double E = 0; // current error
	do
	{
		std::cout << std::setw(15) << "Model" << std::setw(15) << "Forecast" << std::setw(15) << "Error" << std::endl;
		E = 0;
		for (int i = 0; i < (EDUCATION - N); i++)
		{
			y[N + i] = 0;
			for (int j = 0; j < N; j++)
				y[N + i] += W[j] * t[i + j];
			y[N + i] -= T;
			for (int j = 0; j < N; j++)
				W[j] -= ALPHA * (y[N + i] - t[N + i])*t[i + j];
			T += ALPHA * (y[N + i] - t[N + i]);
			E += pow((y[N + i] - t[N + i]), 2.0)/2.0;

			std::cout << std::setw(15) << t[N + i] << std::setw(15) << y[N + i] << std::setw(15) << E << std::endl;
		}
		std::cout << "E - " << E << std::endl;
	} while (E > Em);

	// forecasting
	std::cout << std::setw(15) << "X" << std::setw(15) << "Y(model)" << std::setw(15) << "Y(forecast)" << std::setw(15) << "Error" << std::endl;
	for (int i = EDUCATION; i < (EDUCATION + FORECAST); i++)
	{
		y[i] = 0;
		for (int j = 0; j < N; j++)
			y[i] += W[j] * y[i + j - N];
		y[i] -= T;

		std::cout << std::setw(15) << x[i] << std::setw(15) << t[i] << std::setw(15) << y[i] << std::setw(15) << abs(y[i] - t[i]) << std::endl;
	}

	system("pause");
	return 0;
}