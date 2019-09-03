#include "Analysis.h"


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

void Analysis::plot(bool show)
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

	// save additional info
	// for lab report
	info_buffer << std::endl << print();

	// I won't be useful anymore
	info_buffer.close();

	
	// call to python script
	std::string command = "python plot_it.py";
	if (!show)
		command += " --silent ";
	system((command + " --path " + fileName).c_str());
}

/*
Calculation of mathematical parameters
like mean, std, etc. And makes vector
of randomly generated numbers.

Parameters:
@size - size of vector to generate
*/

void Analysis::execute(int size)
{
	// clear buffers
	m_mean = 0;
	m_dispersion = 0;
	m_generatedValues.clear();

	std::vector<double> params;
	for (int i = 0; i < size; i++)
	{
		// generate parameters of
		// the current iteration
		params = m_paramsGenerator(i);

		// save a value generated
		// by specified random generator
		// using previously generated
		// parameters
		m_generatedValues.push_back(
			m_randomGenerator(params));
	}

	// calculation of the mean
	for (auto it = m_generatedValues.begin(); it != m_generatedValues.end(); it++)
		m_mean += *it;
	m_mean /= m_generatedValues.size();

	// calculation of the dispersion
	for (auto it = m_generatedValues.begin(); it != m_generatedValues.end(); it++)
		m_dispersion += pow(*it - m_mean, 2);
	m_dispersion /= m_generatedValues.size();

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
	std::ofstream results(fileName);
	if (!results)
	{
		std::cerr
			<< "[ERROR] Cannot open the file "
			<< fileName
			<< std::endl;
		return;
	}
	results << "Generator: " << m_generatorName << std::endl;
	results << "Analyzed parameter: " << m_analizedParameterName << std::endl;
	results << "Mean: " << m_mean << std::endl;
	results << "Dispersion: " << m_dispersion << std::endl;
}

std::string Analysis::print() const
{
	std::stringstream results;
	results << "Generator: " << m_generatorName << std::endl;
	results << "Analyzed parameter: " << m_analizedParameterName << std::endl;
	results << "Mean: " << m_mean << std::endl;
	results << "Dispersion: " << m_dispersion << std::endl;
	return results.str();
}

std::ostream& operator<<(std::ostream& stream, const Analysis& analysis)
{
	stream << analysis.print();
	return stream;
}