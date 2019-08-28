#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>

using namespace std;

struct list
{
	int content;
	list * next = NULL;
};
list * init(int);
void addElement(list*, int);
void outList(list*);
void deleteEl(list*, int);
list * deleteFirst(list*);
int main()
{
	list * l = init(1);
	for (int i = 2; i < 6; i++)
		addElement(l, i);
	outList(l);
	int N; cin >> N;
	if (N == 1)
		l = deleteFirst(l);
	else
		deleteEl(l, N);
	outList(l);
	system("pause");
    return 0;
}
list * init(int content)
{
	list * newList = new list;
	newList->content = content;
	return newList;
}
void addElement(list* l, int content)
{
	list * newEl = new list;
	newEl->content = content;
	while (l->next != NULL)
		l = l->next;
	l->next = newEl;
}
void outList(list* l)
{
	cout << l->content << " ";
	while (l->next != NULL)
	{
		l = l->next;
		cout << l->content << " ";
	}
	cout << endl;
}
void deleteEl(list* l, int num)
{
	int id = num - 1;
	for (int i = 1; l->next != NULL; i++)
	{
		if (i == id)
			if (l->next->next == NULL)
			{
				l->next = NULL;
				continue;
			}
			else l->next = l->next->next;
		l = l->next;
	}
}
list * deleteFirst(list* l)
{
	list * lNew = l->next;
	return lNew;
}