#include "pch.h"
#include "lab1.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

#define VALUE	unsigned int
#define COUNT	int
#define CODE	std::string

namespace lab1
{
	std::string ReadFromFile(const std::string& sFilePath)
	{
		std::stringstream ss;
		std::ifstream fin(sFilePath);

		std::string sTmp;
		while (std::getline(fin, sTmp))
			ss << sTmp;

		return ss.str();
	}

	void WriteVectorToFile(const std::vector<VALUE>& vec, const std::string& sFilePath)
	{
		std::ofstream fout{ sFilePath, std::ios::binary | std::ios::out };
		int size = vec.size();
		fout.write((char*)&size, sizeof(size));
		for (int n : vec)
			fout.write((char*)&n, sizeof(n));
	}

	typedef std::vector<std::tuple<VALUE, COUNT, CODE>>::iterator table_row_iterator;
	void FillCodes(table_row_iterator itBegin,
		table_row_iterator itEnd,
		int nTotalNumber)
	{
		// for debug
		auto x = itEnd - itBegin;
		// margin condition
		if (itBegin + 1 == itEnd)
			return;

		int nDivider = nTotalNumber / 2;

		table_row_iterator iSecondBegin;
		int nFirstTotalNumber = 0;
		int nProgress = 0;
		bool fSecondPart = false;
		for (auto it = itBegin; it != itEnd; it++)
		{
			nProgress += std::get<1>(*it);
			// there must be at least one elements in each group
			// Thus, we need to be sure if this condition is met
			if (fSecondPart)
			{
				if (!nFirstTotalNumber)
				{
					nFirstTotalNumber = nProgress - std::get<1>(*it);
					iSecondBegin = it;
					/*std::get<2>(*it).push_back('1');
					continue;*/
				}
				std::get<2>(*it).push_back('0');
			}
			else
			{
				std::get<2>(*it).push_back('1');
			}
			if (nProgress >= nDivider && !fSecondPart)
				fSecondPart = true;

		}

		FillCodes(itBegin, iSecondBegin, nFirstTotalNumber);
		FillCodes(iSecondBegin, itEnd, nTotalNumber - nFirstTotalNumber);
	}

	SCompressedData ShannonFanoCompress(const std::vector<VALUE>& vecInit)
	{
		std::map<VALUE, std::pair<COUNT, CODE>> mapTable; // var => count, code
		std::vector<unsigned int> vecValues;
		for (VALUE v : vecInit)
		{
			if (mapTable.find(v) == mapTable.end())
			{
				mapTable[v] = { 0, "" };
				vecValues.push_back(v);
			}
			mapTable[v].first++;
		}

		// I already wrote algorithm for std::vector<std::tuple<int, int, std::string>> 
		// It's for compatibility
		std::vector<std::tuple<VALUE, COUNT, CODE>> vecTable;
		for (auto i = vecValues.begin(); i != vecValues.end(); i++)
			vecTable.push_back({ *i, mapTable[*i].first , mapTable[*i].second });
		// sort by count of occurrences 
		std::sort(vecTable.begin(), vecTable.end(), [](auto left, auto right) {
			if (std::get<1>(left) > std::get<1>(right))
				return true;
			return false;
		});
		FillCodes(vecTable.begin(), vecTable.end(), vecInit.size());

		// fill map again
		for (int i = 0; i < vecTable.size(); i++)
		{
			int nKey = std::get<0>(vecTable[i]);
			std::string sCode = std::get<2>(vecTable[i]);
			mapTable[nKey].second = sCode;
		}

		// Get flatted string 
		std::string sFlattedString;
		for (int n : vecInit)
		{
			sFlattedString += mapTable[n].second;
		}

		// Fill result
		SCompressedData result;
		for (auto it : mapTable)
			result.mapTable[it.first] = it.second.second; // New map: value -> code, i.e. get rid of the count
		result.sCompressedData = sFlattedString;

		return result;
	}

	std::vector<VALUE> ShannonFanoDecompress(const SCompressedData& data)
	{
		std::vector<VALUE> vecResult;
		std::string sCurrentWindow;
		for (int i = 0; i < data.sCompressedData.length(); i++)
		{
			sCurrentWindow += data.sCompressedData[i];

			int nValue = -1;
			for (auto it = data.mapTable.begin(); it != data.mapTable.end(); it++)
			{
				if (it->second == sCurrentWindow) // if code of item is one we have 
				{
					nValue = it->first; // value of string in window
					break;
				}
			}
			if (nValue != -1)
			{
				vecResult.push_back(nValue);
				sCurrentWindow.clear();
			}
		}
		return vecResult;
	}

	void CompressedDataToFile(const SCompressedData& data, const std::string& sFilePath)
	{
		std::ofstream fout(sFilePath, std::ios::binary | std::ios::out, std::ios::trunc);

		///////////////////////////////////
		// Figuring out redundant bytes  //
		///////////////////////////////////

		// redundant meand the number of "0" we need to add at the end of text to fit
		int cbRedundant = (8 - data.sCompressedData.length() % 8) % 8;
		int cb = 0;
		if (!cbRedundant)
			cb = data.sCompressedData.length() / 8;
		else
		{
			cb = data.sCompressedData.length() / 8 + 1; // 1 more to not lose data
		}
		fout.write((char*)&cbRedundant, sizeof(cbRedundant));

		// adding this redundant bytes
		std::string sActualDataToWrite = data.sCompressedData;
		for (int i = 0; i < cbRedundant; i++)
			sActualDataToWrite += '0';

		/////////////////
		// Map writing //
		/////////////////

		// at first, number of elements
		size_t size = data.mapTable.size();
		fout.write((char*)&size, sizeof(size));

		// then elements themself
		for (auto el : data.mapTable)
		{
			VALUE uValue = el.first;
			int nLenght = el.second.length();
			char szCode[100] = "";
			strcpy_s(szCode, 100, el.second.c_str());
			szCode[nLenght + 1] = '\0';
			fout.write((char*)&uValue, sizeof(uValue));
			fout.write((char*)&szCode, nLenght + 1); // + 1 for \0
		}

		//////////////////
		// Writing data //
		//////////////////

		for (int i = 0; i < cb - 1; i++)
		{
			std::string sByte{ sActualDataToWrite.begin() + i * 8, sActualDataToWrite.begin() + i * 8 + 8 };

			char nByte = 0;
			for (int i = 0; i < 8; i++)
			{
				nByte <<= 1;
				nByte |= (sByte[i] == '1') ? 0b1 : 0b0;
			}
			fout.write((char*)&nByte, sizeof(nByte));
		}
	}

	SCompressedData CompressedDataFromFile(const std::string& sFilePath)
	{
		SCompressedData cd;

		////////////////////////////////////
		// Read number of redundant bytes //
		////////////////////////////////////

		std::ifstream fin(sFilePath, std::ios::binary | std::ios::in);
		int cbRedundant = 0;
		fin.read((char*)&cbRedundant, sizeof(cbRedundant));

		/////////////////
		// Map reading //
		/////////////////

		size_t size;
		fin.read((char*)&size, sizeof(size));

		for (int i = 0; i < size; i++)
		{
			VALUE nValue;
			fin.read((char*)&nValue, sizeof(nValue));

			CODE sCode;
			char ch;
			while (true)
			{
				fin.read(&ch, 1);
				if (ch == '\0')
					break;
				sCode += ch;
			}
			cd.mapTable[nValue] = sCode;
		}

		//////////////////
		// Reading data //
		//////////////////

		while (!fin.eof())
		{
			char nByte;
			fin.read(&nByte, 1);
			std::string sByte;
			sByte.resize(8, '0');
			for (int i = 0; i < 8; i++)
			{
				char cBit = (nByte & 0b1) ? '1' : '0';
				sByte[7 - i] = cBit;
				nByte >>= 1;
			}
			cd.sCompressedData += sByte;
		}

		cd.sCompressedData.erase(cd.sCompressedData.end() - cbRedundant, cd.sCompressedData.end());
		return cd;
	}

	/***************/

}