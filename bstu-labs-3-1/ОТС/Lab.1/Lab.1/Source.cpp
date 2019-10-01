#include "deploy.h"

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
	mixed.plot();

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
	mixed.plot();

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
	mixed.plot();

	// Iterations number
	mixed.setParamsGenerator(
		[](int i) -> std::vector<double> {
			return std::vector<double>{
				13.33,	  // lambda
					123.0,	  //mu
					1000,	 // M
					123.0,	// X<0>
					double(i) // number of iterations
			};
		});
	mixed.setAnalizedParameterName("Iterations");
	mixed.execute(1000);
	std::cout << mixed << std::endl;
	mixed.plot();
}