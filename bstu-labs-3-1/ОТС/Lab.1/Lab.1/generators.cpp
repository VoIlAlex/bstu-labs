#include "generators.h"

<<<<<<< Updated upstream
double generateRandomNumbers_mixed(const std::vector<double>& params)
=======
double generateRandomNumber_mixed(const std::vector<double>& params)
>>>>>>> Stashed changes
{
	// converting parameters
	// to integers
	int lambda = params[0];
	int mu = params[1];
	int M = params[2];
	int x0 = params[3];
	int iterations = params[4];

<<<<<<< Updated upstream
	int xi = x0;
=======
	long long int xi = x0;
>>>>>>> Stashed changes
	for (int i = 0; i < iterations; i++)
		xi = (lambda * xi + mu) % M;

	return xi;
<<<<<<< Updated upstream
}
=======
}

double generateRandomNumber_uniform_distr(const std::vector<double>& params)
{
	double lowerBorder = params[0];
	double upperBorder = params[1];
	double iterations = params[2];

	double R = generateRandomNumber_mixed({
		12312331, // lambda
		111, // mu
		std::numeric_limits<int>::max(), // M
		13, // x<0>
		iterations // iterations
		});
	R = R / std::numeric_limits<int>::max();

	// uniform distribution
	double x = lowerBorder + (upperBorder - lowerBorder) * R;

	return x;
}
>>>>>>> Stashed changes
