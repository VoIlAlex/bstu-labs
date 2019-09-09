/*
	PSEUDO RANDOM NUMBERS GENERATOR


	Functions for generation
	random numbers goes in form:

	double generateRandomNumbers_<method name>(std::vector<double> params) {...}

	where <method name> is name of method used to generated a
	random number, <params> - parameters for random numbers
	generation.

	Analysis of a function is made by
	void analyze(std::function<...>

*/
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <filesystem>

// My headers
#include "Analysis.h" // for Analysis
#include "generators.h" // for random number generators
#include "deploy.h" // for deployment functions





int main()
{
	analyseUniformDistr();

	return 0;
}

