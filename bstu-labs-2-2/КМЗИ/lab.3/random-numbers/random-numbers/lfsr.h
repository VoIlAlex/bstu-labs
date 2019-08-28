#pragma once

#include <iostream>
#include <exception>
#include <iterator>
#include <vector>
#include <set>
#include <utility>
#include <boost/random.hpp>
#include <boost/program_options.hpp>
#include <functional>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <string>


class LFSR
{
public:
	LFSR(int nSize = 8);
	void SetA(std::initializer_list<bool> ilA);
	void SetS(std::initializer_list<unsigned int> ilS);
	void SetS(std::function<unsigned int()> fnGenerator);
	void SetMin(int nMin);
	void SetMax(int nMax);
	void Forward();
	// At the beginning we have 
	// initializaton values
	// If we want to generate different values at the front
	// we have to go forward n times where n is size
	// of our machine
	void Init();
	void Write(std::ostream& stream) const;
	unsigned int Front();
private:
	std::vector<unsigned int> m_vecS;
	std::vector<bool> m_vecA;
	int m_nMin, m_nMax;
};