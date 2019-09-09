#pragma once

#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <filesystem>

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
<<<<<<< Updated upstream
	void plot(bool show = true);
=======
	void plot();
>>>>>>> Stashed changes
	/*
		Calculation of mathematical parameters
		like mean, std, etc. And makes vector
		of randomly generated numbers.

		Parameters:
		@size - size of vector to generate
	*/
<<<<<<< Updated upstream
	void execute(int size);
=======
	void execute(int size, bool normalize = false);
>>>>>>> Stashed changes
	void setGeneratorName(const std::string& name);
	void setAnalizedParameterName(const std::string& name);
	void print(const std::string& fileName) const;
	std::string print() const;
	friend std::ostream& operator<<(std::ostream& stream, const Analysis& analysis);
};

std::ostream& operator<<(std::ostream& stream, const Analysis& analysis);