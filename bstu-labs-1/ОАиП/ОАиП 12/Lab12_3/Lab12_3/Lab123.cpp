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
void writeToFile(const char*, const char*, int);
int numOfLines(char*);
void inverseCase(char*);
int main()
{
	setlocale(LC_ALL, "rus");
	while (1)
	{
		int numOfLines;
		char ** text = readFromFile("text.txt", numOfLines);
		writeToFile("text.txt", "", 0);
		for (int i = 0; i < numOfLines; i++)
		{
			inverseCase(text[i]);
			writeToFile("text.txt", text[i], 1);
			writeToFile("text.txt", "\n", 1);
		}
		for (int i = 0; i < numOfLines; i++)
			cout << text[i] << endl;
		int input; bool br = false;
		while (1)
		{
			input = _getch();
			if (input == 32)
				break;
			else if (input == 27)
			{
				br = true;
				break;
			}
		}
		if (br)
			break;
		system("cls");
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
	for(; getline(fcin, s); i++)
		strcpy_s(lines[i], sizeof(s), s.c_str());
	return lines;
}
void error(const char* content, int timer)
{
	system("cls");
	cout << content << endl;
	Sleep(timer);
	system("cls");
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
void inverseCase(char* str)
{
	char lower[] = "àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
	char upper[] = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß";
	int size = sizeof(lower) / sizeof(*lower);
	int i = 0; 
	while (str[i] != '\0')
	{
		int j = 0;
		while (str[i] != upper[j] && j != size)
			j++;
		if (j == size)
		{
			j = 0;
			while (str[i] != lower[j] && j != size)
				j++;
			if (j != size)
				str[i] = upper[j];
		}
		else
		{
			str[i] = lower[j];
		}
		i++;
	}
}