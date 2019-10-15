#include "RSASignature.h"


mp::cpp_int pow_mod(const mp::cpp_int& value, int degree, unsigned int mod)
{
    mp::cpp_int result = 1;
    for(int i = 0; i < degree; i++)
    {
        result *= value;
        result %= mod;
    }
    return result;
}


//////////////////
// Construction //
//////////////////
RSASignature::RSASignature()
{
    m_p = generate_prime();
    std::clog << "[INFO] p = " << m_p << std::endl;

    m_q = generate_prime();
    while (m_p == m_q)
        m_q = generate_prime();
    std::clog << "[INFO] q = " << m_q << std::endl;

    m_n = m_p * m_q;
    std::clog << "[INFO] n = " << m_n << std::endl;

    m_fi = (m_p - 1) * (m_q - 1);
    std::clog << "[INFO] fi = " << m_fi << std::endl;

    m_d = generate_d();
    std::clog << "[INFO] d = " << m_d << std::endl;

    m_e = generate_e();
    std::clog << "[INFO] e = " << m_e << std::endl;
}



///////////////
// Interface //
///////////////
std::pair<int, int> RSASignature::get_public_key() const
{
    return {m_e, m_n};
}


mp::cpp_int RSASignature::sign(const mp::cpp_int& message) const
{
    return pow_mod(message, m_d, m_n);
}


////////////////////////
// Parameters finding //
////////////////////////

unsigned int RSASignature::generate_prime() const
{
    static std::vector<unsigned int> prime_numbers = {
        11,
        1153,
        5581,
        101,
        12163
    };
    static std::vector<unsigned int>::iterator cur = prime_numbers.begin();

    unsigned int value = *cur;
    cur++;
    return value;
}

unsigned int mcd(unsigned int x1, unsigned int x2)
{
    for(int i = x1 / 2; i != 0; i--)
        if (x1 % i == 0 && x2 % i == 0)
            return i;
}

unsigned int RSASignature::generate_d() const
{
    srand(time(NULL));
    unsigned int value;
    do
    {
        value = rand() % 100 + 2;
    } while (mcd(value, m_fi) != 1);
    return value;
}

unsigned int RSASignature::generate_e() const
{
    int value;
    for(value = 2;; value++)
        if ((value * m_d) % m_fi == 1)
            break;
    return value;
}
