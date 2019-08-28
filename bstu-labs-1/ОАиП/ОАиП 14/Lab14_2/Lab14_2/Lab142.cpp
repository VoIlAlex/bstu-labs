#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>

using namespace std;

struct list
{
	int size;
	int * arr;
	list * next = NULL;
};
list * init();
void addElement(list *);
void outList(list *);
void deleteNegNumsFromList(list *);
int * deleteFromArrNeg(int*, int &);
int main()
{
	list * list = init();
	for(int i = 0; i < 4; i++)
		addElement(list);
	outList(list);
	cout << endl;
	deleteNegNumsFromList(list);
	outList(list);
	cout << endl;
	system("pause");
    return 0;
}

list * init()
{
	list * newList = new list;
	int sizeOfContentArr = rand() % 10 + 2;
	newList->size = sizeOfContentArr;
	newList->arr = new int[sizeOfContentArr];
	for (int i = 0; i < sizeOfContentArr; i++)
		newList->arr[i] = (rand() % 50) * ((rand()%2)?(-1):(1));
	return newList;
}
void addElement(list * l)
{
	while (l->next != NULL)
		l = l->next;
	list * newEl = new list;
	int sizeOfContentArr = rand() % 10 + 1;
	newEl->size = sizeOfContentArr;
	newEl->arr = new int[sizeOfContentArr];
	for (int i = 0; i < sizeOfContentArr; i++)
		newEl->arr[i] = (rand() % 50) * ((rand() % 2) ? (-1) : (1));
	l->next = newEl;
}
void outList(list * l)
{
	for (int i = 0; i < l->size; i++)
		cout << l->arr[i] << " ";
	cout << endl;
	while (l->next != NULL)
	{
		l = l->next;
		for (int i = 0; i < l->size; i++)
			cout << l->arr[i] << " ";
		cout << endl;
	}
}
void deleteNegNumsFromList(list * l)
{
	l->arr = deleteFromArrNeg(l->arr, l->size);
	while (l->next != NULL)
	{
		l = l->next;
		l->arr = deleteFromArrNeg(l->arr, l->size);
	}
}
int * deleteFromArrNeg(int* arr, int &size)
{
	int * tempArr = new int[size];
	int tempSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
			continue;
		tempArr[tempSize] = arr[i];
		tempSize++;
	}
	size = tempSize;
	return tempArr;
}