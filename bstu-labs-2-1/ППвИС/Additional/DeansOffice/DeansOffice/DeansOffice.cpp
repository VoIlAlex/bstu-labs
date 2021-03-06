#include "pch.h"
#include <iostream>
#include "List.h"
#include <fstream>

const int N = 2;



class Student
{
	std::string name;
	std::string group;
public:
	Student()
		: name("noname") {}
	Student(std::string name)
		: name(name) {}

	std::string getName() const
	{
		return name;
	}
	void setName(std::string name)
	{
		this->name = name;
	}
	friend class Group;
};

class Group
{
	std::string groupName;
	List<Student> studList;
	unsigned int headman;
public:
	Group()
		: groupName("noname"), headman(-1) {}
	Group(std::string groupName)
		: groupName("noname"), headman(-1) {}
	bool setHead(const int id)
	{
		try
		{
			if (id < 0 || id >= studList.size())
				throw 1;
			headman = id;
			return true;
		}
		catch (...)
		{
			return false;
		}
	}
	Student& getHead()
	{
		try
		{
 			if (headman ==  -1)
				throw 1;
			return studList.getAccess(headman);
		}
		catch (...)
		{
			std::cout << "Error!" << std::endl;
			system("pause");
			exit(0);
		}
	}
	void addStudent(const Student& newStud)
	{
		studList.push_back(newStud);
		studList.getAccess(studList.size() - 1).group = groupName;
	}
	Student& operator[](const int id)
	{
		try
		{
			if (id < 0 || id >= studList.size())
				throw 1;
			return studList.getAccess(id);
		}
		catch (...)
		{
			std::cout << "Error!" << std::endl;
			system("pause");
			exit(0);
		}
	}
	int sizeOfStudList() const
	{
		return studList.size();
	}
	std::string name() const
	{
		return groupName;
	}
	void setName(std::string name)
	{
		groupName = name;
	}
};

class DeansOffice
{
	Group groups[N];
public:
	DeansOffice()
	{}
	Group& operator[](const int id)
	{
		try
		{
			if (id < 0 || id >= N)
				throw 1;
			return groups[id];
		}
		catch (...)
		{
			std::cout << "Error!" << std::endl;
			system("pause");
			exit(0);
		}
	}
};


/*void toFile(Group& gr, std::string fileName)
{
	std::ofstream stream(fileName, std::ios::out | std::ios::ate);
	for (int i = 0; i < N; i++)
	{
		stream << 
	}
}

Group fromFile()
{

}*/

int main()
{
	DeansOffice doff;
	doff[0].setName("ИИ");
	doff[1].setName("ПО");
	Student s1("II_student");
	Student s2("PO_student");
	doff[0].addStudent(s1);
	doff[1].addStudent(s2);
	doff[0].setHead(0);
	doff[1].setHead(0);

	std::cout << doff[0].getHead().getName().c_str() << std::endl;
	std::cout << doff[1].getHead().getName().c_str() << std::endl;
	std::cin.get();
}