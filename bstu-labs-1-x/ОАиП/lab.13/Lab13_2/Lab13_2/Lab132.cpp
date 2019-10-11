#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

bool isSym(int **, int);
int main()
{
	int numOfMatrix;
	cout << "Number of matrix: "; cin >> numOfMatrix;
	system("cls");
	int n;
	cout << "(matrix NxN) \nN: ";  cin >> n;
	system("cls");
	ofstream fout("initial.txt", ios::out);
	fout << "";
	fout.close();
	fout.open("initial.txt", ios::out | ios::app | ios::binary);
	for (int i = 0; i < numOfMatrix; i++)
	{
		int ** matrix = new int*[n];
		for (int j = 0; j < n; j++)
		{
			matrix[j] = new int[n];
			for (int z = 0; z < n; z++)
			{
				matrix[j][z] = rand() % 10;
				fout.write((char*)&matrix[j][z], sizeof(int));
			}
		}
	}
	fout.close();
	ofstream res1("res1.txt", ios::out);
	res1 << "";
	res1.close();
	res1.open("res1.txt", ios::out | ios::app | ios::binary);
	ofstream res2("res2.txt", ios::out);
	res2 << "";
	res2.close();
	res2.open("res2.txt", ios::out | ios::app | ios::binary);
	ifstream fin("initial.txt", ios::binary);
	int num1 = 0, num2 = 0;
	for (int i = 0; i < numOfMatrix; i++)
	{
		int ** matrix = new int*[n];
		for (int j = 0; j < n; j++)
		{
			matrix[j] = new int[n];
			for (int z = 0; z < n; z++)
				fin.read((char*)&matrix[j][z], sizeof(int));
		}
		for (int j = 0; j < n; j++)
		{
			for (int z = 0; z < n; z++)
				cout << matrix[j][z] << " ";
			cout << endl;
		}
		cout << endl;
		if (isSym(matrix, n))
		{
			for (int j = 0; j < n; j++)
				for (int z = 0; z < n; z++)
					res1.write((char*)&matrix[j][z], sizeof(int));
			num1++;
		}
		else
		{
			for (int j = 0; j < n; j++)
				for (int z = 0; z < n; z++)
					res2.write((char*)&matrix[j][z], sizeof(int));
			num2++;
		}
	}
	res2.close();
	res1.close();
	ifstream res1in("res1.txt", ios::binary); 
	ifstream res2in("res2.txt", ios::binary);
	cout << "Not sym: " << endl;
	for (int i = 0; i < num2; i++)
	{
		int ** matrix = new int*[n];
		for (int j = 0; j < n; j++)
		{
			matrix[j] = new int[n];
			for (int z = 0; z < n; z++)
				res2in.read((char*)&matrix[j][z], sizeof(int));
		}
		for (int j = 0; j < n; j++)
		{
			for (int z = 0; z < n; z++)
				cout << matrix[j][z] << " ";
			cout << endl;
		}
		cout << endl;
	}
	cout << "Sym: " << endl;
	for (int i = 0; i < num1; i++)
	{
		int ** matrix = new int*[n];
		for (int j = 0; j < n; j++)
		{
			matrix[j] = new int[n];
			for (int z = 0; z < n; z++)
				res1in.read((char*)&matrix[j][z], sizeof(int));
		}
		for (int j = 0; j < n; j++)
		{
			for (int z = 0; z < n; z++)
				cout << matrix[j][z] << " ";
			cout << endl;
		}
		cout << endl;
	}
	system("pause");
    return 0;
}
bool isSym(int ** matrix, int size) 
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matrix[i][j] != matrix[j][i])
				return false;
	return true;
}