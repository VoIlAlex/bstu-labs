
#include <vector>
#include <stdexcept>
#include <string>


class RIPEMD128
{
	// Initial values
	std::vector<unsigned int> h;
	
	// Initial lenght
	size_t m_initial_length;
private:
	// step 1
	std::string add_additional_bits(const std::string& input);
	
	// step 2
	std::string add_initial_length(const std::string& input);
	
	// step 4
	void main_cycle(const std::string& input);
	
	// constants and functions
	char f(int j, char x, char y, char z);
	int K1(int j);
	int K2(int j);
	std::vector<int> R1(int j);
	std::vector<int> R2(int j);
	std::vector<int> S1(int j);
	std::vector<int> S2(int j);
	
	// initialize the output vector
	void init_h();
public:
	RIPEMD128();
	// step 5. Result
	std::string operator()(const std::string& input);

	// Format output to look like 
	// in  the instruction
	static std::string format_output(const std::string& output);
	
};