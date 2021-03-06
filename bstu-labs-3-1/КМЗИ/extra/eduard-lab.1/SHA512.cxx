
#include <sstream>
#include "SHA512.hxx"

std::string SHA512::add_additional_bits(const std::string &input)
{
	std::string result = input;
	result += char(1 << 7);
	for (int i = result.size(); i % 64 != 56; i++)
		result += char(0);
	return result;
}

std::string SHA512::add_initial_length(const std::string &input)
{
	std::string result = input;
	for (int i = 0; i < 8; i++)
		result += ((7 - i) * 8 >> m_initial_length) & 0xFF;
	return result;
}

SHA512::SHA512()
{
	K = {
		0x428a2f98d728ae22,
		0x3956c25bf348b538,
		0xd807aa98a3030242,
		0x72be5d74f27b896f,
		0xe49b69c19ef14ad2,
		0x2de92c6f592b0275,
		0x983e5152ee66dfab,
		0xc6e00bf33da88fc2,
		0x27b70a8546d22ffc,
		0x650a73548baf63de,
		0xa2bfe8a14cf10364,
		0xd192e819d6ef5218,
		0x19a4c116b8d2d0c8,
		0x391c0cb3c5c95a63,
		0x748f82ee5defb2fc,
		0x90befffa23631e28,
		0xca273eceea26619c,
		0x06f067aa72176fba,
		0x28db77f523047d84,
		0x4cc5d4becb3e42b6,
		0x7137449123ef65cd,
		0x59f111f1b605d019,
		0x12835b0145706fbe,
		0x80deb1fe3b1696b1,
		0xefbe4786384f25e3,
		0x4a7484aa6ea6e483,
		0xa831c66d2db43210,
		0xd5a79147930aa725,
		0x2e1b21385c26c926,
		0x766a0abb3c77b2a8,
		0xa81a664bbc423001,
		0xd69906245565a910,
		0x1e376c085141ab53,
		0x4ed8aa4ae3418acb,
		0x78a5636f43172f60,
		0xa4506cebde82bde9,
		0xd186b8c721c0c207,
		0x0a637dc5a2c898a6,
		0x32caab7b40c72493,
		0x597f299cfc657e2a,
		0xb5c0fbcfec4d3b2f,
		0x923f82a4af194f9b,
		0x243185be4ee4b28c,
		0x9bdc06a725c71235,
		0x0fc19dc68b8cd5b5,
		0x5cb0a9dcbd41fbd4,
		0xb00327c898fb213f,
		0x06ca6351e003826f,
		0x4d2c6dfc5ac42aed,
		0x81c2c92e47edaee6,
		0xc24b8b70d0f89791,
		0xf40e35855771202a,
		0x2748774cdf8eeb99,
		0x5b9cca4f7763e373,
		0x84c87814a1f0ab72,
		0xbef9a3f7b2c67915,
		0xeada7dd6cde0eb1e,
		0x113f9804bef90dae,
		0x3c9ebe0a15c9bebc,
		0x5fcb6fab3ad6faec,
		0xe9b5dba58189dbbc,
		0xab1c5ed5da6d8118,
		0x550c7dc3d5ffb4e2,
		0xc19bf174cf692694,
		0x240ca1cc77ac9c65,
		0x76f988da831153b5,
		0xbf597fc7beef0ee4,
		0x142929670a0e6e70,
		0x53380d139d95b3df,
		0x92722c851482353b,
		0xc76c51a30654be30,
		0x106aa07032bbd1b8,
		0x34b0bcb5e19b48a8,
		0x682e6ff3d6b2b8a3,
		0x8cc702081a6439ec,
		0xc67178f2e372532b,
		0xf57d4f7fee6ed178,
		0x1b710b35131c471b,
		0x431d67c49c100d4c,
		0x6c44198c4a475817};
	H = {
		0x6a09e667f3bcc908,
		0xbb67ae8584caa73b,
		0x3c6ef372fe94f82b,
		0xa54ff53a5f1d36f1,
		0x510e527fade682d1,
		0x9b05688c2b3e6c1f,
		0x1f83d9abfb41bd6b,
		0x5be0cd19137e2179};
}

uint64_t ROTR(uint64_t x, int n)
{
	return (x >> n) | (x << (64 - n));
}

uint64_t SHR(uint64_t x, int n)
{
	return x >> n;
}

uint64_t sigma_0(uint64_t x)
{
	return ROTR(x, 1) ^ ROTR(x, 8) ^ ROTR(x, 7);
}

uint64_t sigma_1(uint64_t x)
{
	return ROTR(x, 19) ^ ROTR(x, 61) ^ SHR(x, 6);
}

uint64_t weird_sigma_0(uint64_t x)
{
	return ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39);
}

uint64_t weird_sigma_1(uint64_t x)
{
	return ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41);
}

uint64_t Ch(uint64_t x, uint64_t y, uint64_t z)
{
	return (x & y) | (~x & z);
}

uint64_t Maj(uint64_t x, uint64_t y, uint64_t z)
{
	return (x & y) | (x & z) | (y & z);
}

void SHA512::main_cycle(const std::string &input)
{
	for (int i = 0; i < input.size() / 64; i++)
	{
		// 1. Подготовка списка преобразованных слов сообщения
		std::string word{input.begin() + i * 64, input.begin() + (i + 1) * 64};
		std::vector<int32_t> W(80);

		// first 16 values
		for (int j = 0; j < 16; j++)
		{
			int32_t value = 0;
			for (int t = 0; t < 4; t++)
			{
				value <<= 8;
				value = value | word[j * 4 + t];
			}
			W.push_back(value);
		}

		// other values
		for (int j = 16; j < 80; j++)
		{
			W.push_back(
				sigma_1(W[j - 2]) + W[j - 7] + sigma_0(W[j - 15]) + W[j - 16]);
		}

		// 2. Инициализация рабочих переменных
		int a = H[0],
			b = H[1],
			c = H[2],
			d = H[3],
			e = H[4],
			f = H[5],
			g = H[6],
			h = H[7];

		// 3. Внутренний цикл
		for (int t = 0; t < 80; t++)
		{
			uint64_t T1 = h + weird_sigma_1(e) + Ch(e, f, g) + K[t] + W[t];
			uint64_t T2 = weird_sigma_0(a) + Maj(a, b, c);
			h = g;
			g = f;
			f = e;
			e = d + T1;
			d = c;
			c = b;
			b = a;
			a = T1 + T2;
		}

		// 4. Вычисление промежуточного значения хэш-функции
		H[0] = a + H[0];
		H[1] = b + H[1];
		H[2] = c + H[2];
		H[3] = d + H[3];
		H[4] = e + H[4];
		H[5] = f + H[5];
		H[6] = g + H[6];
		H[7] = h + H[7];
	}
}

std::string SHA512::generate_result() const
{
	std::stringstream result;
	for (int i = 0; i < 8; i++)
	{
		if (i != 0)
			result << ' ';
		result << std::hex << H[i];
	}
	return result.str();
}

std::string SHA512::operator()(const std::string &input)
{
	m_initial_length = input.size() * 8;
	std::string result = add_additional_bits(input);
	result = add_initial_length(result);
	main_cycle(result);
	return generate_result();
}
