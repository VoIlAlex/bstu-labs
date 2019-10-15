#include "RIPEMD128.h"
#include <iostream>



int main()
{

    RIPEMD128 ripemd;
    std::string input;
    while(true)
    {
        std::cout << "Input: ";
        std::getline(std::cin, input);
        std::cout << "Output: " << ripemd.format_output(ripemd(input)) << std::endl;
    }
}
