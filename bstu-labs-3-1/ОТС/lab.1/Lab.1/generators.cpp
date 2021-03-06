#include "generators.h"
#include <math.h>

double generateRandomNumber_mixed(const std::vector<double>& params)
{
	// converting parameters
	// to integers
	int lambda = params[0];
	int mu = params[1];
	int M = params[2];
	int x0 = params[3];
	int iterations = params[4];

	long long int xi = x0;
	for (int i = 0; i < iterations; i++)
		xi = (lambda * xi + mu) % M;

	return xi;
}

double generateRandomNumber_uniform_distr(const std::vector<double>& params)
{
	double lowerBorder = params[0];
	double upperBorder = params[1];
	double iterations = params[2];

	// Random number within (0, 1)
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

double generateRandomNumber_normal_distr(const std::vector<double>& params)
{
	double mean = params[0];
	double D = params[1];
	int n = params[2];
	double iterations = params[3];

	// generation of n random
	// numbers within (0, 1)
	auto gen = [=](int iterations) -> std::vector<double> {
		std::vector<double> nums;
		for (int i = iterations * n; i < n + iterations * n; i++)
		{
			double random_num = generateRandomNumber_mixed({
				12312331, // lambda
				111, // mu
				std::numeric_limits<int>::max(), // M
				13, // x<0>
				double(i) // iterations
				});
			random_num /= std::numeric_limits<int>::max();
			nums.push_back(
				random_num
			);
		}
		return nums;
	};

	// n random numbers within (0, 1)
	auto random_nums = gen(iterations);


	double sum_of_random_nums = 0.0;
	for (auto random_num : random_nums)
		sum_of_random_nums += random_num;

	double final_random_num = mean + D * pow(2, 0.5) * (sum_of_random_nums - 3);
	return final_random_num;
}

double generateRandomNumber_exp_distr(const std::vector<double>& params)
{
	double lambda = params[0];
	int iterations = params[1];

	// Random number within (0, 1)
	double R = generateRandomNumber_mixed({
		12312331, // lambda
		111, // mu
		std::numeric_limits<int>::max(), // M
		13, // x<0>
		double(iterations) // iterations
		});
	R = R / std::numeric_limits<int>::max();

	double final_random_number = -(1 / lambda) * log(1 - R);
	return final_random_number;
}

double generateRandomNumber_gamma_distr(const std::vector<double>& params)
{
	double lambda = params[0];
	int gamma = params[1];
	int iterations = params[2];

	// generation of <gamma> random
	// numbers within (0, 1)
	auto gen = [=](int iterations) -> std::vector<double> {
		std::vector<double> nums;
		for (int i = iterations * gamma; i < gamma + iterations * gamma; i++)
		{
			double random_num = generateRandomNumber_mixed({
				12312331, // lambda
				111, // mu
				std::numeric_limits<int>::max(), // M
				13, // x<0>
				double(i) // iterations
				});
			random_num /= std::numeric_limits<int>::max();
			nums.push_back(
				random_num
			);
		}
		return nums;
	};

	// n random numbers within (0, 1)
	auto random_nums = gen(iterations);

	double random_sum = 0.0;
	for (int i = 0; i < gamma; i++)
		random_sum = log(random_nums[i]);

	return -(1 / lambda) * random_sum;
}

double generateRandomNumber_simpson_distr(const std::vector<double>& params)
{
	double a = params[0];
	double b = params[1];
	int iteration = params[2];

	// 2 random numbers within (0, 1)
	double R1 = generateRandomNumber_uniform_distr(
		{
			a / 2,
			b / 2,
			double(iteration)
		}
	);

	double R2 = generateRandomNumber_uniform_distr(
		{
			a / 2,
			b / 2,
			double(iteration + 13)
		}
	);


	return R1 + R2;
}

double generateRandomNumber_left_side(const std::vector<double>& params)
{
	static int steps_ahead = 0;
	double a = params[0];
	double b = params[1];
	int iteration = params[2];

	double R1 = 0, R2 = 0;
	while (!(R2 < R1) && ++steps_ahead)
	{
		// 2 random numbers within (0, 1)
		R1 = generateRandomNumber_uniform_distr(
			{
				a / 2,
				b / 2,
				double(iteration + steps_ahead)
			}
		);

		R2 = generateRandomNumber_uniform_distr(
			{
				a / 2,
				b / 2,
				double(iteration + 13 + steps_ahead)
			}
		);
	}

	return a + (b - a) * R1;
}