g++ -c -std=c++17 SHA512.cxx
g++ -c -std=c++17 main.cpp
g++ -I D:/Documents/Libraries/Catch2/single_include SHA512.o main.o -o a.exe
./a.exe