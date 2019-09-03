#include "generators.h"

double generateRandomNumbers_mixed(const std::vector<double>& params)
{
	// converting parameters
	// to integers
	int lambda = params[0];
	int mu = params[1];
	int M = params[2];
	int x0 = params[3];
	int iterations = params[4];

	int xi = x0;
	for (int i = 0; i < iterations; i++)
		xi = (lambda * xi + mu) % M;

	return xi;
}