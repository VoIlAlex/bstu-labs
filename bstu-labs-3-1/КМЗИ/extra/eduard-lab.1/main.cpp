#include "SHA512.hxx"
#include <iostream>

/*
    I was to lazy for
    including some third-party
    dependencies, so I just
    wrote my own testing tool. Lol
*/
class Test
{
    int m_passed;
    int m_total;

public:
    Test() : m_passed(0), m_total(0) {}

    void add(bool result)
    {
        m_total++;
        if (result == true)
            m_passed++;
    }

    ~Test()
    {
        std::clog << "Results: " << m_passed << "/" << m_total << std::endl;
    }
};
Test test;
#define REQUIRE(expression) test.add(expression)

int main()
{
    SHA512 sha;
    REQUIRE(sha("") == "cf83e1357eefb8bd f1542850d66d8007 d620e4050b5715dc 83f4a921d36ce9ce 47d0d13c5d85f2b0 ff8318d2877eec2f 63b931bd47417a81 a538327af927da3e");
    REQUIRE(sha("abc") == "ddaf35a193617aba cc417349ae204131 12e6fa4e89a97ea2 0a9eeee64b55d39a 2192992a274fc1a8 36ba3c23a3feebbd 454d4423643ce80e 2a9ac94fa54ca49f");
    REQUIRE(sha("abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklm-noijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu") == "8e959b75dae313da 8cf4f72814fc143f 8f7779c6eb9f7fa1 7299aeadb6889018 501d289e4900f7e4 331b99dec4b5433a c7d329eeb6dd2654 5e96e55b874be909");
    std::cout << sha("") << std::endl;
    std::cout << sha("abc") << std::endl;
    std::cout << sha("abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklm-noijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu") << std::endl;
}
