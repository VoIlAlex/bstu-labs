#include "deploy.h"
#include "Analysis.h"
#include "generators.h"

void analyseMixed()
{
	// lambda
	Analysis mixed(
		generateRandomNumber_mixed,
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

void analyseUniformDistr()
{
	Analysis uniform_distr(
		generateRandomNumber_uniform_distr,
		[](int i) -> std::vector<double> {
			return {
				9000, // lower border
				10000, // upper border
				double(i) // iteration
			};
		}
	);
	uniform_distr.setGeneratorName("Uniform distribution");
	uniform_distr.setAnalizedParameterName("Iterations");
	uniform_distr.execute(1000);
	uniform_distr.plot();
	std::cin.get();
}

void analyseNormalDistr()
{
	Analysis normal_distr(
		generateRandomNumber_normal_distr,
		[](int i) -> std::vector<double> {
			return {
				1000, // mean
				0.5, // D
				6, // n
				double(i) // iteration
			};
		}
	);
	normal_distr.setGeneratorName("Normal distribution");
	normal_distr.setAnalizedParameterName("Iterations");
	normal_distr.execute(1000);
	normal_distr.plot();
	std::cin.get();
}

void analyseExponentialDistr()
{
	Analysis exp_distr(
		generateRandomNumber_exp_distr,
		[](int i) -> std::vector<double> {
			return {
				10, // lambda
				double(i) // iteration
			};
		}
	);
	exp_distr.setGeneratorName("Exponential distribution");
	exp_distr.setAnalizedParameterName("Iterations");
	exp_distr.execute(1000);
	exp_distr.plot();
	std::cin.get();
}

void analyseGammaDistr()
{
	Analysis gamma_distr(
		generateRandomNumber_gamma_distr,
		[](int i) -> std::vector<double> {
			return {
				10, // lambda
				13, // gamma
				double(i) // iteration
			};
		}
	);
	gamma_distr.setGeneratorName("Gamma distribution");
	gamma_distr.setAnalizedParameterName("Iterations");
	gamma_distr.execute(1000);
	gamma_distr.plot();
	std::cin.get();
}

void analyseSimpsonDistr()
{
	Analysis simpson_distr(
		generateRandomNumber_simpson_distr,
		[](int i) -> std::vector<double> {
			return {
				5, // a
				10, // b
				double(i) // iteration
			};
		}
	);
	simpson_distr.setGeneratorName("Simpson distribution");
	simpson_distr.setAnalizedParameterName("Iterations");
	simpson_distr.execute(1000);
	simpson_distr.plot();
	std::cin.get();
}

void analyseLeftSideDistr()
{
	Analysis left_side_distr(
		generateRandomNumber_left_side,
		[](int i) -> std::vector<double> {
			return {
				5, // a
				10, // b
				double(i) // iteration
			};
		}
	);
	left_side_distr.setGeneratorName("Left side distribution");
	left_side_distr.setAnalizedParameterName("Iterations");
	left_side_distr.execute(1000);
	left_side_distr.plot();
	std::cin.get();

}

void lab_solution()
{
	double mean = 100;
	double d = 10;
	double n = 6;
	Analysis normal_distr(
		generateRandomNumber_normal_distr,
		[=](int i) -> std::vector<double> {
			return {
				mean, // mean
				d, // D
				n, // n
				double(i) // iteration
			};
		}
	);

	std::string dirname = std::filesystem::current_path().string() + "\\results" + "\\lab_results" + "\\";

	normal_distr.setGeneratorName("Normal distribution");
	normal_distr.setAnalizedParameterName("Iterations");

	double beta = 0.8;

	for (int value : { 100, 500, 1000, 10000, 30000 })
	{
		normal_distr.execute(value);
		std::string filename = dirname + "normal_" + std::to_string(value) + ".txt";
		normal_distr.print(filename);

		std::ofstream fout(filename, std::ios::app | std::ios::out);

		auto [mean_from, mean_to] = normal_distr.trustInterval("mean", mean, d * d, beta);
		auto [dispersion_from, dispersion_to] = normal_distr.trustInterval("dispersion", mean, d * d, beta);
		auto hi_square = normal_distr.hi_square([=](double x) -> double {
			return (1.0 / (d * sqrt(2 * 3.1415))) * exp(-pow(x - mean, 2) / (2 * d));
			});

		fout << "\nMean: " << mean_from << " --- " << mean_to << std::endl;
		fout << "Dispersion: " << dispersion_from << " --- " << dispersion_to << std::endl;
		fout << "Hi square: " << hi_square << std::endl;

		fout.close();
	}
}
