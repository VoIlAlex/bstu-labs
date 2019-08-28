#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

void error(const char*, int);
char ** readFromFile(char*, int&);
int numOfLines(char*);
template<typename T>
T* increase(T*, int&);
void writeToFile(const char*, const char*, int);
void encrypStr(char *, char*);
int isChInStr(char, char* );

int main()
{
	setlocale(LC_ALL, "rus");
	char nums[] = "0123456789";
	int numOfLines;
	char ** text = readFromFile("text.txt", numOfLines);
	writeToFile("text.txt", "", 0);
	for (int i = 0; i < numOfLines; i++)
	{
		encrypStr(text[i], nums);
		writeToFile("text.txt", text[i], 1);
		writeToFile("text.txt", "\n", 1);
	}

	system("pause");
	return 0;
}

void encrypStr(char * str, char* nums)
{
	char lowerCase[] = "àáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
	char upperCase[] = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß";
	int size = sizeof(lowerCase) / sizeof(*lowerCase);
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		int isLCase = isChInStr(str[i], lowerCase);
		int isUCase = isChInStr(str[i], upperCase);
		bool isInAlphabet = (isLCase + 1) || (isUCase + 1);
		if (!isInAlphabet)
			continue;
		if (isLCase + 1)
		{
			str[i] = upperCase[(nums[(j % 10)] % size)];
			j++;
		}
		if (isUCase + 1)
		{
			str[i] = lowerCase[(nums[(j % 10)] % size)];
			j++;
		}
	}
}

int isChInStr(char ch, char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ch)
			return i;
	return -1;
}

char ** readFromFile(char* nameOfFile, int& numOfL)
{
	ifstream fcin;
	fcin.open(nameOfFile);
	if (!fcin)
	{
		error("Cannot open the file!", 1000);
		char ** error = new char*;
		return error;
	}
	numOfL = numOfLines(nameOfFile);
	char ** lines = new char*[numOfL];
	for (int i = 0; i < numOfL; i++)
		lines[i] = new char[100];
	int i = 0;
	string s;
	for (; getline(fcin, s); i++)
		strcpy_s(lines[i], sizeof(s), s.c_str());
	return lines;
}

int numOfLines(char* nameOfFile)
{
	ifstream fcin(nameOfFile);
	int numOfLines = 0;
	string s;
	while (getline(fcin, s))
		numOfLines++;
	return numOfLines;
}

void error(const char* content, int timer)
{
	system("cls");
	cout << content << endl;
	Sleep(timer);
	system("cls");
}

void writeToFile(const char* nameOfFile, const char* content, int toTheEnd)
{
	ofstream fout;
	if (toTheEnd)
		fout.open(nameOfFile, ios::out | ios::app);
	else
		fout.open(nameOfFile, ios::out);
	if (!fout)
	{
		error("Cannot open the file!", 500);
		return;
	}
	fout << content;
	fout.close();
}

template<typename T>
T* increase(T* arr, int &size)
{
	size++;
	int sizeVar = size;
	T* arrRes = new T[sizeVar];
	for (int i = 0; i < sizeVar - 1; i++)
		arrRes[i] = arr[i];
	return arrRes;
}
