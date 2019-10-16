#include "RIPEMD128.h"
#include <iostream>

int main()
{

    RIPEMD128 ripemd;
    std::string input;
    while (true)
    {
        input.clear();
        std::cout << "Input: ";
        std::getline(std::cin, input);
        std::cout << "Output: " << ripemd(input) << std::endl;
    }
}
