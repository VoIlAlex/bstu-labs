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
list * M(list*, int);
int main()
{
	list * l = init(1);
	for (int i = 2; i < 6; i++)
		addElement(l, i);
	outList(l);
	list * listM = M(l, 1);
	outList(listM);
	listM = M(l, 2);
	outList(listM);
	listM = M(l, 3);
	outList(listM);
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
	while(l->next != NULL)
	{
		l = l->next;
		cout << l->content << " ";
	}
	cout << endl;
}
list * M(list* M1, int minContent)
{
	list * M = new list;
	int i = 0;
	while (1)
	{
		if (M1->content > minContent)
		{
			if (i == 0) M = init(M1->content);
			else addElement(M, M1->content);
			i++;
		}
		if (M1->next == NULL) break;
		M1 = M1->next;
	}
	return M;
}