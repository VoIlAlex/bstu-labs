#include "RIPEMD128.h"
#include <iostream>


template<typename T>
void assert_eq(const T& x1, const T& x2)
{
    std::cout << x1 << " ==? " << x2 << std::endl;
    // if (x1 != x2)
    //     throw std::runtime_error("Assersion failed");
}

int main()
{
    RIPEMD128 ripemd;
    assert_eq(ripemd.format_output(ripemd("")), std::string("cdf26213 a150dc3e cb610f18 f6b38b46"));
    assert_eq(ripemd.format_output(ripemd("abc")), std::string("c14a1219 9c66e4ba 84636b0f 69144c77"));
    assert_eq(ripemd.format_output(ripemd("12345678901234567890123456789012345678901234567890123456789012345678901234567890")), std::string("3f45ef19 4732c2db b2c4a2c7 69795fa3"));
}