#include <iostream>
#include "classes.h"

int main()
{
	OnlineGame dota2;
	Game * ptr_dota2 = &dota2;
	ptr_dota2->setName("Dota 2");
	ptr_dota2->setOwner("Valve");
	ptr_dota2->setEngine("Source 2");
	ptr_dota2->setPrice(0);
	ptr_dota2->setRelYear(2013);
	showInfo(*ptr_dota2);
	dota2.setName("Dota 2 update");
	dota2.setOwner("Valve update");
	dota2.setEngine("Source 2 update");
	dota2.setPrice(0);
	dota2.setRelYear(2018);
	showInfo(dota2);
	Human human("Ilya");
	User user(human, "Ilya2000");
	dota2 << user;
	dota2.start();
	dota2 << user;
	dota2.showOnlineList();
	dota2.shutDown();
	dota2.showOnlineList();
	system("pause");
}