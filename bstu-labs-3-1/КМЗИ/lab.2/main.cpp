#include "RSASignature.h"
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;



int main()
{
    RSASignature rsa_signature;
    auto [e, n] = rsa_signature.get_public_key();

    // mp::cpp_int message;
    // std::cout << "Message (unsigned int): " << std::endl;
    // std::cin >> message;
    
    mp::cpp_int message ( "1128" );
    std::cout << "Message (unsigned int): " << message << std::endl;

    mp::cpp_int signature = rsa_signature.sign(message);

    // Checking the signature
    mp::cpp_int message_from_signature = mp::pow(signature, e) % n;
    std::cout << "Message from signature: " << message_from_signature << std::endl;

    if (message_from_signature == message)
        std::cout << "Signature is correct!" << std::endl;

    else
        std::cout << "Signature isn't correct!" << std::endl;

}
