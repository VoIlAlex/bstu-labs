#include <iostream>
//#define SYNCH
#include "hopfnet.h"

constexpr int N = 13;
constexpr int SIZE_OF_SET = 3;

int main()
{
	using namespace HopfieldNetwork;
#ifdef SYNCH
	std::cout << "::Synchronous mode::" << std::endl;
#else
	std::cout << "::Asynchronous mode::" << std::endl;
#endif

	//Sample<N>					sample3 = { 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0 };
	Sample<N>					sample8 = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1 };
	Sample<N>					sample4 = { 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1 };
	Sample<N>					sample9 = { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 };
	SampleSet<N, SIZE_OF_SET>	set = {/* sample3,*/ sample8, sample4, sample9 };
	Net<N, SIZE_OF_SET>			net(set);

	/*Sample<N>					test1 = { 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };
	test1.view("Test", 2);
	net.process(test1);
	test1.view("Processed test");
	sample3.view("Sample", 1);
	std::cout << std::endl;*/

	Sample<N>					test2 = { 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 };
	test2.view("Test", 2);
	net.process(test2);
	test2.view("Processed test");
	sample8.view("Sample", 1);
	std::cout << std::endl;

	Sample<N>					test3 = { 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1 };
	test3.view("Test", 2);
	net.process(test3);
	test3.view("Processed test");
	sample4.view("Sample", 1);
	std::cout << std::endl;

	Sample<N>					test4 = { 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 };
	test4.view("Test", 2);
	net.process(test4);
	test4.view("Processed test");
	sample9.view("Sample", 1);
	std::cout << std::endl;

	std::cin.get();
}