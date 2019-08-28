// homoph_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "homoph.h"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>


// TODO: Parse .csv file into operatable format (might be separate function)
// TODO: Replace characters in initial string with random value from homophonic table

namespace homoph
{
	// contains homophonic table for encoding and decoding
	struct SHomophTable : public std::vector<std::string>
	{
		bool m_fCorrectness;
		// This function checks the order of symbols in .csv file
		bool fnIsCorrect(const std::string& sLine) const
		{
			static int c_cItem = 0;
			if (sLine[0] == c_cItem + 97)
			{
				c_cItem++;
				return true;
			}
			if (sLine[0] == ' ')
			{
				if (c_cItem - 26 == 0)
				{
					c_cItem = 0;
					return true;
				}
			}
			return false;
		}
		// This function converts the line of csv into a vector
		std::string fnParseLine(const std::string& sLine) throw(std::exception)
		{
			std::string sResult;

			std::string sCurrent;
			for (int i = 1; i < sLine.length(); i++)
			{
				if (i == sLine.length() - 1)
				{
					try
					{
						sResult.push_back((char)boost::lexical_cast<int>(sCurrent));
						sCurrent.clear();
					}
					catch (boost::bad_lexical_cast e)
					{
						throw std::exception("Wrong element in line");
					}
				}
				if (sLine[i] == ' ')  // a,|     |5,3 
					continue;
				else if (sLine[i] == ',') // a|,|5|,|3
				{
					if (!sCurrent.length())
						continue;
					// trying to convert another element from .csv to int. If cannot then throw an exception
					try
					{
						sResult.push_back((char)boost::lexical_cast<int>(sCurrent));
						sCurrent.clear();
					}
					catch (boost::bad_lexical_cast e)
					{
						throw std::exception("Wrong element in line");
					}
				}
				else
				{
					sCurrent += sLine[i];
				}
			}

			return sResult;
		}
	public:
		SHomophTable(const std::string& csv_file)
			: m_fCorrectness(true)
		{
			std::ifstream ifsCSV(csv_file);
			if (!ifsCSV)
			{
				m_fCorrectness = false;
				return;
			}
			std::string sLine;
			while (std::getline(ifsCSV, sLine))
			{
				if (!fnIsCorrect(sLine))
				{
					m_fCorrectness = false;
					break;
				}
				try
				{
					this->push_back(fnParseLine(sLine));
				}
				catch (std::exception e)
				{
					m_fCorrectness = false;
					break;
				}
			}
		}
		operator bool() const
		{
			return m_fCorrectness;
		}
	};

	// support functions
	void fnTextToCipher(std::string& sPlainText, const SHomophTable& htTable)
	{
		boost::to_lower(sPlainText);
		for (char& symbol : sPlainText)
		{
			int iSymbol = symbol - 97;
			if (symbol == ' ')
				iSymbol = 26;
			int avaibleLen = htTable.at(iSymbol).length();
			symbol = htTable.at(iSymbol)[rand() % avaibleLen];
		}
	}
	void fnCipherToText(std::string& sCipher, const SHomophTable& htTable)
	{
		for (char& symbol : sCipher)
		{
			bool fIsThere = false;
			for (int i = 0; i < htTable.size(); i++)
			{
				for (char subst : htTable[i])
					if (subst == symbol)
					{
						fIsThere = true;
						break;
					}
				if (fIsThere)
				{
					symbol = static_cast<char>(i + 97);
					break;
				}
			}
			if (!fIsThere)
				throw std::exception("Homophonic table have not enough items");
		}
	}
	std::string fnReadFile(const std::string& filePath) throw(std::exception)
	{
		std::string text;
		std::ifstream file{ filePath };
		if (!file)
			throw std::exception("Cannot open file");
		std::string tmp;
		while (std::getline(file, tmp))
		{
			text += tmp;
		}
		return text;
	}
	void fnWriteToFile(const std::string& filePath, const std::string& sText) throw(std::exception)
	{
		std::ofstream file{ filePath, std::ios::out | std::ios::trunc };
		if (!file)
			throw std::exception("Cannot open the file");

		file << sText;
	}

	/////
	// "file" is path to file we're going to encrypt
	//	Encrypted information will be pasted into the same file
	// "csv_file" is path to file with csv homophonic table in it
	/////
	int EncodeFileWithCSV(const std::string& file, const std::string& csv_file)
	{
		SHomophTable htTable{ csv_file };
		if (!htTable)
			return -1;
		try
		{
			std::string sPlainText = fnReadFile(file);
			fnTextToCipher(sPlainText, htTable);
			fnWriteToFile(file, sPlainText);
		}
		catch (std::exception)
		{
			return -1;
		}
		catch (std::out_of_range)
		{
			return -2;
		}

		return 0;
	}

	/////
	// "src" is path to file we're going to encrypt
	// "dst" is path to file where we're going to paste information
	// "csv_file" is path to file with csv homophonic table in it
	/////
	int EncodeFileWithCSV_n(const std::string& src, const std::string& dst, const std::string csv_file)
	{
		SHomophTable htTable{ csv_file };
		if (!htTable)
		{
			return -1;
		}
		try
		{
			std::string sPlainText = fnReadFile(src);
			fnTextToCipher(sPlainText, htTable);
			fnWriteToFile(dst, sPlainText);
		}
		catch (std::exception)
		{
			return -1;
		}
		catch (std::out_of_range)
		{
			return -2;
		}

		return 0;
	}

	/////
	// "str" is the string we're going to encrypt
	//	Encrypted information will be pasted into the same string
	// "csv_file" is path to file with csv homophonic table in it
	/////
	int DecodeFileWithCSV(std::string& file, const std::string& csv_file)
	{
		SHomophTable htTable{ csv_file };
		if (!htTable)
			return -1;
		try
		{
			std::string sCipher = fnReadFile(file);
			fnCipherToText(sCipher, htTable);
			fnWriteToFile(file, sCipher);
		}
		catch (std::exception)
		{
			return -2;
		}

		return 0;
	}


	/////
	// "str_src" is the string we're going to encrypt
	//	Encrypted information will be returned in a new string
	// "csv_file" is path to file with csv homophonic table in it
	/////
	int DecodeFileWithCSV_n(const std::string& src, const std::string& dst, const std::string& csv_file)
	{
		SHomophTable htTable{ csv_file };
		if (!htTable)
			return -1;
		try
		{
			std::string sCipher = fnReadFile(src);
			fnCipherToText(sCipher, htTable);
			fnWriteToFile(dst, sCipher);
		}
		catch (std::exception)
		{
			return -2;
		}

		return 0;
	}
}