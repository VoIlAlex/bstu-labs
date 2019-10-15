g++ -c -std=c++17 main.cpp
g++ -c -std=c++17 RSASignature.cpp
g++ main.o RSASignature.o -o executable
./executable