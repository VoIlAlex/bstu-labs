//Lab6 МОИС
#include "pch.h"
#include <iostream>
#include "lab6_src.h"

int main()
{
	typedef int Type;
	Lab6::BTree<Type> bt;
	bt.add(0);
	bt.add(1);
	bt.add(2);
	bt.add(3);
	bt.add(4);
	bt.add(5);
	bt.add(6);
	bt.add(7);
	bt.add(8);
	bt.add(9);
	bt.add(10);
	bt.add(11);
	bt.add(12);
	bt.add(13);

	bt.view();
	std::cout << std::endl;
	
	auto code = bt.getCode();
	auto valueList = bt.getValueList();
	auto root = bt.getRoot();

	Lab6::BTree<Type> bt_copy(code, valueList, root);
	bt_copy.view();
	std::cin.get();
}
