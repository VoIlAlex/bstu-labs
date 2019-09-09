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
double generateRandomNumber_mixed(const std::vector<double>& params);

/*
	Uniform distribution.

	Parameters:
	@params[0] - lower border
	@params[1] - upper border
	@params[2] - iteration
*/
double generateRandomNumber_uniform_distr(const std::vector<double>& params);

/*
	Uniform distribution.

	Parameters:
	@params[0] - mean
	@params[1] - D
	@params[2] - n // number 6 is nice one
	@params[3] - iteration
*/
double generateRandomNumber_normal_distr(const std::vector<double>& params);


/*
	Exponential distribution.

	Parameters:
	@params[0] - lambda
	@params[1] - iteration
*/
double generateRandomNumber_exp_distr(const std::vector<double>& params);