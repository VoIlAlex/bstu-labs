// RIPEMD-128
#include "RIPEMD128.h"

std::string RIPEMD128::add_additional_bits(const std::string& input)
{
	std::string result(input);
	result += char(1 << 7);
	for(int i = result.size(); i % 64 != 56; i++)
		result += char(0);
	return {};
}

std::string RIPEMD128::add_initial_length(const std::string& input)
{
	std::string result(input);
	for(int i = 0; i < 4; i++)
		result += ((3 - i) * 8 >> m_initial_length) & 0xFF;
	return result;
}

void RIPEMD128::main_cycle(const std::string& input)
{
	int T, 
		A1, B1, C1, D1,
		A2, B2, C2, D2;
	for(int i = 0; i < input.size() / 512 + 1; i++)
	{
		A1 = h[0]; B1 = h[1]; C1 = h[2]; D1 = h[3];
		A2 = h[0]; B2 = h[1]; C2 = h[2]; D2 = h[3];
		for(int j = 0; j < 64; j++)
		{
			int T = (A1 + f(j, B1, C1, D1) + M[i][R1(j)] + K1(j)) << S1(j);
			A1 = D1;
			D1 = C1;
			C1 = B1;
			B1 = T1;
			T = (A2 + f(63-j, B2, C2, D2) + M[i][R2(j)] + K2(j)) << S2(j);
			A2 = D2;
			D2 = C2;
			C2 = B2;
			B2 = T;
		}
		T = h[1] + C1 + D2;
		h[1] = h[2] + D1 + A2;
		h[2] = h[3] + A1 + B2;
		h[3] = h[0] + B1 + C2;
		h[0] = T;
	}
}

std::string RIPEMD128::operator()(const std::string& input)
{
	m_initial_length = input.size() * 8;
	std::string result = add_additional_bits(input);
	result = add_initial_length(input);
	main_cycle(result);
	std::string result;
	for(int value : {h.begin(), h.begin()+4})
		for(int i = 0; i < 4; i++)
			result += (value >> (3 - i ) * 8) & 0xFF;
	return result;
}

void RIPEMD128::init_h() 
{
	h = {
		0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476,
		0xC3D2E1F0, 0x76543210, 0xFEDCBA98, 0x89ABCDEF,
		0x01234567, 0x3C2D1E0F
	};
}

/////////////////////////
// Constants and functions //
/////////////////////////

char RIPEMD128::f(int j, char x, char y, char z)
{
	if(0 <= j && j <= 15)
		return x ^ y ^ z;
	else if( 16 <= j && j <= 31)
		return (x & y) | (~x & z);
	else if (32 <= j && j <= 47)
		return (x | ~y) ^ z;
	else if (48 <= j && j <= 63)
		return (x & z) | (y & ~z);
	else if (64 <= j && j <= 79)
		return x ^ (y | ~z);
	else
		throw std::out_of_range("j is out of range");
}
int RIPEMD128::K1(int j)
{
	// TODO: implement
	return{};
}
int RIPEMD128::K2(int j)
{
	// TODO: implement
	return{};
}
std::vector<int> RIPEMD128::R1(int j)
{	
	// TODO: implement
	return{};
}
std::vector<int> RIPEMD128::R2(int j)
{
	// TODO: implement
	return{};
}
std::vector<int> RIPEMD128::S1(int j)
{
	// TODO: implement
	return{};
}
std::vector<int> RIPEMD128::S2(int j)
{
	// TODO: implement
	return{};
}
