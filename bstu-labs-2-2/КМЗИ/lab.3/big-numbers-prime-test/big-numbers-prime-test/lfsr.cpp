#include "pch.h"
#include "lfsr.h"

/** Class methods definitions **/
LFSR::LFSR(int nSize)
	: m_vecS(nSize), m_vecA(nSize), m_nMin(0), m_nMax(100)
{}
void LFSR::SetA(std::initializer_list<bool> ilA)
{
	int i = 0;
	for (bool a : ilA)
	{
		if (i >= m_vecA.size()) break;
		m_vecA[i] = a;
		i++;
	}
}
void LFSR::SetS(std::initializer_list<unsigned int> ilS)
{
	int i = 0;
	for (unsigned int S : ilS)
	{
		if (i >= m_vecS.size()) break;
		m_vecS[i] = S;
		i++;
	}
}
void LFSR::SetS(std::function<unsigned int()> fnGenerator)
{
	for (unsigned int& S : m_vecS)
		S = fnGenerator();
}
void LFSR::SetMin(int nMin)
{
	m_nMin = nMin;
}
void LFSR::SetMax(int nMax)
{
	m_nMax = nMax;
}
void LFSR::Forward()
{
	for (int i = 0; i < m_vecS.size(); i++)
	{
		if (i == m_vecS.size() - 1)
		{
			m_vecS[i] = 0;
			for (int j = 0; j < m_vecS.size() - 1; j++)
				m_vecS[i] += m_vecA[j] * m_vecS[j];
		}
		else
		{
			m_vecS[i] = m_vecS[i + 1];
		}
		m_vecS[i] = m_vecS[i] % (m_nMax - m_nMin) + m_nMin;
	}
}
void LFSR::Init()
{
	for (int i = 0; i < m_vecA.size(); i++)
		Forward();
}
void LFSR::Write(std::ostream& stream) const
{
	std::ostream_iterator<int> it(stream, " ");
	std::copy(m_vecS.begin(), m_vecS.end(), it);
	std::endl(stream);
}
unsigned int LFSR::Front()
{
	Forward();
	return m_vecS.front();
}