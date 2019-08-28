#pragma once
#include <map>
#include <string>
#include <vector>
#include <boost/random.hpp>

#ifdef LAB1_EXPORTS
#define LAB1_API __declspec(dllexport)
#else
#define LAB1_API __declspec(dllimport)
#endif
#define VALUE	unsigned int
#define COUNT	int
#define CODE	std::string

namespace lab1
{
	typedef std::vector<std::tuple<VALUE, COUNT, CODE>>::iterator table_row_iterator;
	struct SCompressedData
	{
		std::map<VALUE, CODE> mapTable;
		std::string sCompressedData;
	};

	template<int cols> // Number of columns in table
	class CTableCipher
	{
	private:
		VALUE aTable[256][cols];
	public:
		CTableCipher()
		{
			boost::random::mt19937 gen;
			for (int i = 0; i < 256; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					unsigned int newValue;
					bool bFound = false;
					while (!bFound)
					{
						newValue = gen() % (256 * cols);
						if (IsInTable(newValue)) continue;
						bFound = true;
					}
					aTable[i][j] = newValue;
				}
			}
		}
		VALUE Encrypt(char cPlainBlock) const
		{
			int nPlainBlock = static_cast<int>(cPlainBlock);
			boost::random::mt19937 gen;
			int col = gen() % cols;
			return aTable[nPlainBlock][col];
		}
		char Decrypt(int nEncryptedBlock) const
		{
			VALUE nPlainBlock = -1;
			bool bFound = false;
			for (nPlainBlock = 0; nPlainBlock < 256; nPlainBlock++)
			{
				for (int col = 0; col < cols && !bFound; col++)
					if (aTable[nPlainBlock][col] == nEncryptedBlock)
						bFound = true;
				if (bFound)
					break;
			}
			return static_cast<char>(nPlainBlock);
		}
		std::vector<VALUE> EncryptString(const std::string& sPlainText) const
		{
			std::vector<VALUE> vecResult;
			for (char ch : sPlainText)
				vecResult.push_back(Encrypt(ch));
			return vecResult;
		}
		std::string DecryptVector(const std::vector<VALUE>& vecCipherText) const
		{
			std::string sResult;
			for (int n : vecCipherText)
				sResult.push_back(Decrypt(n));
			return sResult;
		}

	private:
		bool IsInTable(int nVal)
		{
			bool bResult = false;
			for (int i = 0; i < 256; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (aTable[i][j] == nVal)
					{
						bResult = true;
						break;
					}
				}
				if (bResult)
					break;
			}
			return bResult;
		}
	};

	std::string ReadFromFile(const std::string& sFilePath);
	void  WriteVectorToFile(const std::vector<VALUE>& vec, const std::string& sFilePath);
	SCompressedData ShannonFanoCompress(const std::vector<VALUE>& vecInit);
	std::vector<VALUE> ShannonFanoDecompress(const SCompressedData& data);
	void CompressedDataToFile(const SCompressedData& data, const std::string& sFilePath);
	SCompressedData CompressedDataFromFile(const std::string& sFilePath);
}
