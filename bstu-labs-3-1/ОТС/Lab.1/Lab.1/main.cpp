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
#include "Analysis.h" // for Analysis class
#include "generators.h" // for random number generators

/** Functions **/

void analyseMixed();



int main()
{
	analyseMixed();

	return 0;
}

/*
	Analysis of mixed method 
	of random numbers generation
*/
void analyseMixed()
{
	// lambda
	Analysis mixed(
		generateRandomNumbers_mixed,
		[](int i) -> std::vector<double> {
			return std::vector<double>{
				double(i), // lambda
					1.0,	   //mu
					1000.0,	//M
					123.0,	 // X<0>
					100		   // number of iterations
			};
		});
	mixed.setGeneratorName("Mixed");
	mixed.setAnalizedParameterName("Lambda");
	mixed.execute(1000);
	std::cout << mixed << std::endl;
	mixed.plot(false);

	// mu
	mixed.setParamsGenerator(
		[](int i) -> std::vector<double> {
			return std::vector<double>{
				1.0,	   // lambda
					double(i), //mu
					1000.0,	//M
					123.0,	 // X<0>
					100		   // number of iterations
			};
		});
	mixed.setAnalizedParameterName("Mu");
	mixed.execute(1000);
	std::cout << mixed << std::endl;
	mixed.plot(false);

	// M
	mixed.setParamsGenerator(
		[](int i) -> std::vector<double> {
			return std::vector<double>{
				1.0,	   // lambda
					1.0,	   //mu
					double(i + 1), // M
					123.0,	 // X<0>
					100		   // number of iterations
			};
		});
	mixed.setAnalizedParameterName("M");
	mixed.execute(1000);
	std::cout << mixed << std::endl;
	mixed.plot(false);

	// Iterations number
	mixed.setParamsGenerator(
		[](int i) -> std::vector<double> {
			return std::vector<double>{
				1.0,	  // lambda
					1.0,	  //mu
					1000,	 // M
					123.0,	// X<0>
					double(i) // number of iterations
			};
		});
	mixed.setAnalizedParameterName("Iterations");
	mixed.execute(1000);
	std::cout << mixed << std::endl;
	mixed.plot(false);
}

