#include <vector>
#include <functional>

typedef std::function<double(double)> PDF;


double range_probability_by_pdf(PDF pdf, double min, double max, double step = 0.001)
{
	double range_probability = 0;
	for (double i = min; i < max; i += step)
		range_probability += pdf(i) * step;
	return range_probability;
}


double hi_square(PDF pdf, int degrees_of_freedom, std::vector<double> generatedValues)
{
	double min_element = *std::min_element(generatedValues.begin(), generatedValues.end());
	double max_element = *std::max_element(generatedValues.begin(), generatedValues.end());
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

		for (auto value : generatedValues)
			if (value > lower_border && value <= upper_border)
				values_in_range++;


		range_probability = (double)values_in_range / generatedValues.size();
		actual_range_probability = range_probability_by_pdf(pdf, lower_border, upper_border);

		hi_square += pow(range_probability - actual_range_probability, 2) / actual_range_probability;
	}
	return hi_square * degrees_of_freedom;
}