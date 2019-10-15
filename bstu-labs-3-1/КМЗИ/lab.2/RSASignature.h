// http://www.e-nigma.ru/stat/rsa/

#include <utility>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

// Utility
mp::cpp_int pow_mod(const mp::cpp_int& value, int degree, unsigned int mod);

class RSASignature
{
    unsigned int m_p;
    unsigned int m_q;
    unsigned int m_n;
    unsigned int m_fi;
    unsigned int m_d;
    unsigned int m_e;

private:
    unsigned int generate_prime() const;
    unsigned int generate_d() const;
    unsigned int generate_e() const;
public:
    RSASignature();
    std::pair<int, int> get_public_key() const;
    mp::cpp_int sign(const mp::cpp_int& message) const;
};
