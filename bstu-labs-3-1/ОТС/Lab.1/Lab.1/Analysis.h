#pragma once

#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <filesystem>
#include <map>

/** Type definitions **/
typedef std::function<double(const std::vector<double>&)> RandomGenerator;
typedef std::function<std::vector<double>(double)> ParamsGenerator;

/*
	This class makes analyzes of
	a given random number generator.
*/
class Analysis
{
	// generator of random numbers
	RandomGenerator m_randomGenerator;

	// generator of parameters for random
	// numbers generator
	ParamsGenerator m_paramsGenerator;

	// name is used in plotting
	std::string m_generatorName;

	// name of parameter being currently
	// analyzed
	std::string m_analizedParameterName;

	// buffer for generated values
	std::vector<double> m_generatedValues;

	// probabilistic parameters
	bool m_is_executed;
	double m_mean;
	double m_dispersion;

	// parameter for trust intervals calculation
	std::map<double, double> m_t = {
		{0.8, 1.282	},	{0.86, 1.475},	{0.92, 1.750},	{0.98,  2.325},
		{0.81, 1.310},	{0.87, 1.513},	{0.93, 1.810},	{0.99,  2.576},
		{0.82, 1.340},	{0.88, 1.539},	{0.94, 1.880},	{0.998, 3.000},
		{0.83, 1.371},	{0.89, 1.592},	{0.95, 1.960},	{0.999, 3.290},
		{0.84, 1.404},	{0.90, 1.643},	{0.96, 2.053},
		{0.85, 1.439},	{0.91, 1.694},	{0.97, 2.169}
	};

public:
	/*
		@randomGenerator: random numbers generator - double(vector<double>)
		@paramsGenerator: parameters generator - double(int)
	*/
	Analysis(RandomGenerator randomGenerator, ParamsGenerator paramsGenerator);
	void setRandomGenerator(RandomGenerator randomGenerator);
	void setParamsGenerator(ParamsGenerator paramsGenerator);

	/*
		Plots results using python.
	*/
	void plot();
	/*
		Calculation of mathematical parameters
		like mean, std, etc. And makes vector
		of randomly generated numbers.

		Parameters:
		@size - size of vector to generate
	*/
	void execute(int size, bool normalize = false);
	void setGeneratorName(const std::string& name);
	void setAnalizedParameterName(const std::string& name);
	void print(const std::string& fileName) const;
	std::string print() const;
	std::pair<double, double> trustInterval(const std::string& type, double mean, double dispersion, double beta);
	friend ::std::ostream& operator<<(std::ostream& stream, const Analysis& analysis);
private:
	double get_mu(int degree);
};

std::ostream& operator<<(std::ostream& stream, const Analysis& analysis);