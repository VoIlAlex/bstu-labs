#include "stdafx.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct ex
{
	bool content;
	ex * next = NULL;
};
bool boolExFromFile(const char *);
ex * exFromStr(char*);
void error(const char*, int);
void push(ex *, bool);
bool pop(ex *);
int main()
{
	cout << boolExFromFile("text.txt") << endl;
	system("pause");
	return 0;
}
bool boolExFromFile(const char * nameOfFile)
{
	ifstream fin(nameOfFile);
	if (!fin)
	{
		error("Cannot open file or it is empty!", 1000);
		return 0;
	}
	char str[1024];
	string s;
	getline(fin, s);
	strcpy_s(str, sizeof(str), s.c_str());
	bool res = false;
	ex * ex = exFromStr(str);
	while (ex->next!=NULL)
	{
		res |= pop(ex);
	}
	res |= pop(ex);
	return res;
}
ex * exFromStr(char* str)
{
	ex * exNow = new ex; int numOfEx = 0;
	bool conNow = true;
	int i = 0; int endOfLastCon = -1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ') { i++; continue; }
		if (!(str[i] - 48) || !(str[i] - 49))
			conNow = (int)str[i] - 48;
		if (str[i] == 'a')
		{
			i += 4;
			conNow &= (int)str[i] - 48;
			endOfLastCon = i;
		}
		if (str[i] == 'o')
		{
				if (!numOfEx) exNow->content = conNow;
				push(exNow, conNow);
				conNow = true;
				numOfEx++;
		}
		if (str[i + 1] == '\0')
		{
			if (!numOfEx) exNow->content = conNow;
			else exNow = push(exNow, conNow);
		}
		i++;
	}
	return exNow;
}
void push(ex * stack, bool content)
{
	ex * temp = new ex;
	temp->content = stack->content;
	temp->next = stack->next;
	stack->next = temp;
	stack->content = content;
}
bool pop(ex * stack) 
{
	if (stack->next == NULL)
		return stack->content;
	bool cont = stack->content;
	stack->content = stack->next->content;
	stack->next = stack->next->next;
	return cont;
}
void error(const char* content, int timer)
{
	system("cls");
	cout << content << endl;
	Sleep(timer);
	system("cls");
}