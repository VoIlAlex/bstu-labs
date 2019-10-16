#include <vector>
#include <string>


class SHA512
{
	// Initial values
	std::vector<int64_t> H;
    std::vector<int64_t> K;
    // step 1
	std::string add_additional_bits(const std::string& input);

   	// step 2
	std::string add_initial_length(const std::string& input);

    // step 4
    void main_cycle(const std::string& input);

    // result
    std::string generate_result() const;
public:
    SHA512();

    std::string operator()(const std::string& input);
};