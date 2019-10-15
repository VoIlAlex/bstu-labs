g++ -c -std=c++17 main.cpp
g++ -c -std=c++17 RIPEMD128.cpp
g++ main.o RIPEMD128.o -o executable
./executable
