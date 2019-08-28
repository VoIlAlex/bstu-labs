
#include "pch.h"
#include <iostream>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/random.hpp>
#include <boost/algorithm/string.hpp>

/** Definitions **/
using namespace boost::numeric::ublas;
typedef boost::random::mt19937 boost_rand;
/*****************/

/** Classes **/
class ICipher;
class VigenereCipher;
/*************/

/** Functions (declarations) **/
std::string CBC(const std::string& sText, char cIV, char cMode, ICipher& cipher); // for one char
std::string CBC_block(const std::string& sText, std::string sIV, char cMode, ICipher& cipher); // for string
std::vector<std::string> SplitIntoBlocks(const std::string& str, int nBlockSize);
/***************/

/** Classes (declarations) **/
class ICipher
{
public:
	virtual char Encrypt(char cPlainBlock) = 0;
	virtual char Decrypt(char cEncryptedBlock) = 0;
	virtual std::string EncryptBlock(const std::string& sPlainBlock) = 0;
	virtual std::string DecryptBlock(const std::string& sEncryptedBlock) = 0;
};

class VigenereCipher : public ICipher
{
	matrix<char> m_mxTable;
	std::string m_sKey;
	int nCurrentSymbol; // state of the key for next plain symbol
public:
	VigenereCipher(const std::string& sKey);
	virtual char Encrypt(char cPlainBlock);
	virtual char Decrypt(char cEncryptedBlock);
	virtual std::string EncryptBlock(const std::string&  sPlainBlock);
	virtual std::string DecryptBlock(const std::string&  sEncryptedBlock);

	void Reload();
};
/**************************/


int main()
{
	std::string sKey("key_phrase");
	std::string sIV; sIV.resize(sKey.length());
	std::generate(sIV.begin(), sIV.end(), []() -> char {
		static boost_rand gen;
		return gen() % 256;
	});

	std::string sPlainText;
	std::getline(std::cin, sPlainText);

	// Encryption
	VigenereCipher vc(sKey);
	std::string sCipherText = CBC_block(sPlainText, sIV, 'e', vc);
	std::cout << "Encrypted: " << sCipherText << std::endl;


	// Decrypted
	sPlainText = CBC_block(sCipherText, sIV, 'd', vc);
	std::cout << "Decrypted: " << sPlainText << std::endl;
}

/** Classes (definitions) **/
VigenereCipher::VigenereCipher(const std::string& sKey)
	: m_mxTable(sKey.length(), 256), nCurrentSymbol(0)
{
	m_sKey = boost::to_lower_copy(sKey);

	// fill our matrix
	boost_rand gen;
	for (int i = 0; i < m_mxTable.size1(); i++)
	{
		std::string sAlphabet;
		for (int i = 0; i < 256; i++)
			sAlphabet.push_back(i);
		for (int j = 0; j < m_mxTable.size2(); j++)
		{
			int idx = gen() % sAlphabet.length();
			m_mxTable(i, j) = sAlphabet[idx];
			sAlphabet.erase(idx, 1);
		}
	}
}
char VigenereCipher::Encrypt(char cPlainBlock)
{
	unsigned int nPlainBlock = cPlainBlock;
	nPlainBlock &= 0xFF;
	char cResult = m_mxTable(nCurrentSymbol, nPlainBlock);
	nCurrentSymbol = (nCurrentSymbol + 1) % m_sKey.length();
	return cResult;
}
char VigenereCipher::Decrypt(char cEncryptedBlock)
{
	char cResult;
	for (int i = 0; i < m_mxTable.size2(); i++)
	{
		if (m_mxTable(nCurrentSymbol, i) == cEncryptedBlock)
		{
			cResult = i;
			break;
		}
	}
	nCurrentSymbol = (nCurrentSymbol + 1) % m_sKey.length();
	return cResult;
}
std::string VigenereCipher::EncryptBlock(const std::string&  sPlainBlock)
{
	Reload();
	std::string sResult;
	for (char c : sPlainBlock)
		sResult.push_back(Encrypt(c));
	return sResult;
}
std::string VigenereCipher::DecryptBlock(const std::string&  sEncryptedBlock)
{
	Reload();
	std::string sResult;
	for (char c : sEncryptedBlock)
		sResult.push_back(Decrypt(c));
	return sResult;
}
void VigenereCipher::Reload()
{
	nCurrentSymbol = 0;
}
/************************/

/** Function (definitions) **/
std::string CBC(const std::string& sText, char cIV, char cMode, ICipher& cipher)
{
	std::string sResult;
	char cXOR = cIV;

	switch (cMode)
	{
	case 'e':
	{
		for (char ch : sText)
		{
			char cXOR_res = ch ^ cXOR;
			char cEncrypted = cipher.Encrypt(cXOR_res);
			sResult.push_back(cEncrypted);
			cXOR = cEncrypted;
		}
	}
	break;
	case 'd':
	{
		for (char ch : sText)
		{
			char cDecrypted = cipher.Decrypt(ch);
			char cXOR_res = cXOR ^ cDecrypted;
			sResult.push_back(cXOR_res);
			cXOR = ch;
		}
	}
	break;
	default:
		break;
	}
	return sResult;
}
std::vector<std::string> SplitIntoBlocks(const std::string& str, int nBlockSize)
{
	std::vector<std::string> vecResult;

	std::string sCurrent;
	for (char ch : str)
	{
		sCurrent.push_back(ch);
		if (sCurrent.length() == nBlockSize)
		{
			vecResult.push_back(sCurrent);
			sCurrent.clear();
		}
	}
	if (!sCurrent.empty())
		vecResult.push_back(sCurrent);
	return vecResult;
}
std::string operator^(const std::string& sLeft, const std::string& sRight)
{
	std::string sResult;
	int nLength = std::min(sLeft.length(), sRight.length());
	for (int i = 0; i < nLength; i++)
	{
		sResult.push_back(sLeft[i] ^ sRight[i]);
	}
	return sResult;
}
std::string CBC_block(const std::string& sText, std::string sIV, char cMode, ICipher& cipher)
{
	int nBlockSize = sIV.length();
	std::vector<std::string> vecBlocks = SplitIntoBlocks(sText, nBlockSize);
	std::string sResult;
	std::string sXOR = sIV;
	bool fShortBlock = false; // is the last block too short?
	if (vecBlocks.back().length() < nBlockSize)
		fShortBlock = true;
	switch (cMode)
	{
	case 'e': // encryption
	{
		for (auto it = vecBlocks.begin(); it != vecBlocks.end(); it++)
		{
			if (fShortBlock && it == vecBlocks.end() - 1)
			{
				sXOR = cipher.EncryptBlock(sXOR);
				sResult.append(*it ^ sXOR);
				break;
			}
			std::string sXORed = *it ^ sXOR;
			std::string sEncrypted = cipher.EncryptBlock(sXORed);
			sResult.append(sEncrypted);
			sXOR = sEncrypted;
		}
	}
	break;
	case 'd': // decryption
	{
		for (auto it = vecBlocks.begin(); it != vecBlocks.end(); it++)
		{
			if (fShortBlock && it == vecBlocks.end() - 1)
			{
				sXOR = cipher.EncryptBlock(sXOR);
				sResult.append(*it ^ sXOR);
				break;
			}
			std::string sDecrypted = cipher.DecryptBlock(*it);
			sResult.append(sDecrypted ^ sXOR);
			sXOR = *it;
		}
	}
	break;
	default:
		break;
	}
	return sResult;
}
/***************************/