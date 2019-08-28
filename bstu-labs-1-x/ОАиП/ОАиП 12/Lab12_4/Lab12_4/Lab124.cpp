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
char ** getWords(char*, int&);
template<typename T>
T* increase(T*, int&);
void writeToFile(const char*, const char*, int);
int main()
{
	setlocale(LC_ALL, "rus");
	char C = 'à';

	int numOfLines;
	char ** text = readFromFile("initial.txt", numOfLines);
	writeToFile("result.txt", "", 0);
	for (int i = 0; i < numOfLines; i++)
	{
		int numOfWords;
		char ** words = getWords(text[i], numOfWords);
		for (int j = 0; j < numOfWords; j++)
			if (words[j][0] == C)
			{
				writeToFile("result.txt", words[j], 1);
				writeToFile("result.txt", " ", 1);
			}
	}
	system("pause");
    return 0;
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
char ** getWords(char* text, int& numOfWords)
{
	numOfWords = 0;
	char ** words = new char*;
	char wordNow[1024] = "";
	int i = 0, chInWord = 0;
	while (text[i] != '\0')
	{
		if (text[i] == ' ')
		{
			if (chInWord != 0)
			{
				wordNow[chInWord] = '\0';
				words = increase(words, numOfWords);
				words[numOfWords - 1] = new char[1024];
				strcpy_s(words[numOfWords - 1], sizeof(char) * 100, wordNow);
				strcpy_s(wordNow, sizeof(char) * 100, "");
				chInWord = 0;
				continue;
			}
		}
		else
		{
			wordNow[chInWord] = text[i];
			chInWord++;
		}
		i++;
		if (text[i] == '\0')
			if (chInWord != 0)
			{
				wordNow[chInWord] = '\0';
				words = increase(words, numOfWords);
				words[numOfWords - 1] = new char[1024];
				strcpy_s(words[numOfWords - 1], sizeof(char) * 100, wordNow);
				strcpy_s(wordNow, sizeof(char) * 100, "");
				chInWord = 0;
				continue;
			}
	}
	return words;
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
