#include "Analysis.h"
#include <algorithm>


/*
@randomGenerator: random numbers generator - double(vector<double>)
@paramsGenerator: parameters generator - double(int)
*/

Analysis::Analysis(RandomGenerator randomGenerator, ParamsGenerator paramsGenerator)
	: m_randomGenerator(randomGenerator),
	m_paramsGenerator(paramsGenerator),
	m_is_executed(false),
	m_mean(0),
	m_dispersion(0)
{
}

void Analysis::setRandomGenerator(RandomGenerator randomGenerator)
{
	m_randomGenerator = randomGenerator;
}

void Analysis::setParamsGenerator(ParamsGenerator paramsGenerator)
{
	m_paramsGenerator = paramsGenerator;
}

/*
Plots results using python.
*/

void Analysis::plot()
{
	if (!m_is_executed)
	{
		std::cerr
			<< "[ERROR] Analysis isn't executed"
			<< std::endl;
		return;
	}

	// opening a file
	// to hold information
	std::ofstream info_buffer;
	if (!std::filesystem::exists("results"))
	{
		std::filesystem::create_directory("results");
	}
	std::string fileName = std::filesystem::current_path().string()
		+ "\\results\\"
		+ m_generatorName
		+ "_"
		+ m_analizedParameterName
		+ ".txt";
	info_buffer.open(fileName, std::ios::out | std::ios::trunc);
	if (!info_buffer)
	{
		std::cerr
			<< "[ERROR] Cannot open the file "
			<< fileName
			<< std::endl;
		return;
	}

	// print name of generator
	info_buffer << m_generatorName << std::endl;
	// and name of parameter
	info_buffer << m_analizedParameterName << std::endl;

	// print values
	for (int i = 0; i < m_generatedValues.size(); i++)
	{
		if (i != 0)
			info_buffer << ",";
		info_buffer << m_generatedValues[i];
	}

	// print mean and dispersion
	info_buffer << std::endl << "Mean: " << m_mean << std::endl;
	info_buffer << "Dispersion: " << m_dispersion << std::endl;

	info_buffer.close();

	// save additional info
	// for lab report
	info_buffer << print();

	// call to python script
	std::string command = "python plot_it.py --path \"";
	system((command + fileName + "\"").c_str());
}

/*
Calculation of mathematical parameters
like mean, std, etc. And makes vector
of randomly generated numbers.

Parameters:
@size - size of vector to generate
*/

void Analysis::execute(int size, bool normalize)
{
	// clear buffers
	m_mean = 0;
	m_dispersion = 0;
	m_generatedValues.clear();

	std::vector<double> params;

	double generatedValue;

	for (int i = 0; i < size; i++)
	{
		// generate parameters of
		// the current iteration
		params = m_paramsGenerator(i);

		// save a value generated
		// by specified random generator
		// using previously generated
		// parameters
		generatedValue = m_randomGenerator(params);
		m_generatedValues.push_back(
			generatedValue
		);
	}

	// calculation of the mean
	for (auto it = m_generatedValues.begin(); it != m_generatedValues.end(); it++)
		m_mean += *it;
	m_mean /= m_generatedValues.size();

	// calculation of the dispersion
	for (auto it = m_generatedValues.begin(); it != m_generatedValues.end(); it++)
		m_dispersion += pow(*it - m_mean, 2);
	m_dispersion /= m_generatedValues.size() - 1;

	// set this analysis as
	// executed
	m_is_executed = true;
}

void Analysis::setGeneratorName(const std::string& name)
{
	m_generatorName = name;
}

void Analysis::setAnalizedParameterName(const std::string& name)
{
	m_analizedParameterName = name;
}

void Analysis::print(const std::string& fileName) const
{
	std::ofstream results(fileName, std::ios::out);
	if (!results)
	{
		std::cerr
			<< "[ERROR] Cannot open the file "
			<< fileName
			<< std::endl;
		return;
	}
	results << print();
}

std::string Analysis::print() const
{
	std::stringstream results;
	results << "Generator: " << m_generatorName << std::endl;
	results << "Analyzed parameter: " << m_analizedParameterName << std::endl;
	results << "Mean: " << m_mean << std::endl;
	results << "Dispersion: " << m_dispersion << std::endl;
	results << "Values: ";
	for (auto it = m_generatedValues.begin(); it != m_generatedValues.end(); it++)
	{
		if (it != m_generatedValues.begin())
			results << " ";
		results << *it;
	}
	return results.str();
}

std::pair<double, double> Analysis::trustInterval(const std::string& type, double mean, double dispersion, double beta)
{
	if (!m_is_executed)
		throw std::runtime_error("Analysis isn't executed");

	double epsilon;
	double t = m_t[beta];
	double sigma;
	double value;
	if (type == "mean")
	{
		value = m_mean;
		sigma = sqrt(value / m_generatedValues.size());
	}
	else if (type == "dispersion")
	{
		value = m_dispersion;
		size_t N = m_generatedValues.size();
		sigma = sqrt(get_mu(4) / N - (N - 3) * pow(m_dispersion, 2) / (N * (N - 1)));
	}
	else throw std::runtime_error("type must have values 'mean' or 'dispersion'");

	epsilon = sigma * t;

	return {
		value - epsilon,
		value + epsilon
	};
}

double range_probability_by_pdf(PDF pdf, double min, double max, double step = 0.001)
{
	double range_probability = 0;
	for (double i = min; i < max; i += step)
		range_probability += pdf(i) * step;
	return range_probability;
}

double Analysis::hi_square(PDF pdf, int degrees_of_freedom)
{
	double min_element = *std::min_element(m_generatedValues.begin(), m_generatedValues.end());
	double max_element = *std::max_element(m_generatedValues.begin(), m_generatedValues.end());
	double step = max_element - min_element;

	double hi_square = 0;
	double lower_border, upper_border;
	int values_in_range;
	double	range_probability,
		actual_range_probability;
	for (int i = min_element + step; i <= max_element; i += step)
	{
		lower_border = i - step;
		upper_border = i;
		values_in_range = 0;

		for (auto value : m_generatedValues)
			if (value > lower_border && value <= upper_border)
				values_in_range++;


		range_probability = (double)values_in_range / m_generatedValues.size();
		actual_range_probability = range_probability_by_pdf(pdf, lower_border, upper_border);

		hi_square += pow(range_probability - actual_range_probability, 2) / actual_range_probability;
	}
	return hi_square * degrees_of_freedom;
}

double Analysis::get_mu(int degree)
{
	double mu = 0;
	for (int i = 0; i < m_generatedValues.size(); i++)
		mu += pow(m_generatedValues[i] - m_mean, degree);
	mu /= m_generatedValues.size();
	return mu;
}

std::ostream& operator<<(std::ostream& stream, const Analysis& analysis)
{
	stream << analysis.print();
	return stream;
}