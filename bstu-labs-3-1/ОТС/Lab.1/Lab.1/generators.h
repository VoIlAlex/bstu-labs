#pragma once

#include <vector>

/*
	Implementation of mixed method of
	generation random numbers.

	Formula:
	X<i+1> = (lambda * X<i> + mu)mod(M)

	Parameters:
	@params[0] - lambda
	@params[1] - mu
	@params[2] - M
	@params[3] - X<0>
	@params[4] - number of iterations
*/
double generateRandomNumbers_mixed(const std::vector<double>& params);