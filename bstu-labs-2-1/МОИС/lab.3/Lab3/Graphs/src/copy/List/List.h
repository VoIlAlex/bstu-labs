#pragma once
#include <iostream>

template<typename Container_Type>
class List
{
	int list_size;

	template<typename Container_Type>
	struct Element
	{
		Container_Type container;
		Element* next;
		Element()
			: next(nullptr) {}
		Element(const Container_Type& other)
			: next(other.next), container(other.container) {}
	};

	Element<Container_Type> * container;

public:
	List()
		: list_size(0), container(new Element<Container_Type>) {};
	List(const List& obj)
		: list_size(obj.list_size), container(new Element<Container_Type>)
	{
		Element<Container_Type>* temp_container = container;
		Element<Container_Type>* temp_obj_container = obj.container;
		for (int i = 0; i < list_size; i++)
		{
			temp_container->container = temp_obj_container->container;
			temp_container->next = new Element<Container_Type>;
			temp_container = temp_container->next;
			temp_obj_container = temp_obj_container->next;
		}
	}
	~List()
	{
		Element<Container_Type> *temp_container = container;
		for (int i = 0; i < list_size; i++)
		{
			for (int j = 1; j < (list_size - i); j++)
			{
				temp_container = temp_container->next;
			}
			delete temp_container->next;
			temp_container = container;
		}
		delete container;
	}
	Container_Type operator[](const int id) const
	{
		try
		{
			if (id < 0)
				throw 1;
			if (id >= list_size)
				throw 2;
			Element<Container_Type> *temp_container = container;
			for (int i = 0; i < id; i++)
				temp_container = temp_container->next;
			return temp_container->container;
		}
		catch (int e)
		{
			// !
			exit(0);
		}
	}
	Container_Type& getAccess(const int id)
	{
		try
		{
			if (id < 0)
				throw 1;
			if (id >= list_size)
				throw 2;
			Element<Container_Type> *temp_container = container;
			for (int i = 0; i < id; i++)
				temp_container = temp_container->next;
			return temp_container->container;
		}
		catch (int e)
		{
			// !
			exit(0);
		}
	}
	List<Container_Type>& operator=(const List<Container_Type>& obj)
	{
		if (list_size != 0)
		{
			Element<Container_Type> *temp_container_for_deleting = container;
			for (int i = 0; i < list_size; i++)
			{
				for (int j = 1; j < (list_size - i); j++)
				{
					temp_container_for_deleting = temp_container_for_deleting->next;
				}
				delete temp_container_for_deleting->next;
				temp_container_for_deleting = container;
			}
			delete container;
			container = new Element<Container_Type>;
		}
		list_size = obj.list_size;
		Element<Container_Type>* temp_container = container;
		Element<Container_Type>* temp_obj_container = obj.container;
		for (int i = 0; i < list_size; i++)
		{
			temp_container->container = temp_obj_container->container;
			temp_container->next = new Element<Container_Type>;
			temp_container = temp_container->next;
			temp_obj_container = temp_obj_container->next;
		}
		return (*this);
	}
	void push_back(const Container_Type& el)
	{
		Element<Container_Type>* temp_container = container;
		for (int i = 0; i < list_size; i++)
			temp_container = temp_container->next;
		temp_container->Element::container = Container_Type(el);
		temp_container->next = new Element<Container_Type>;
		list_size++;
	}
	void push_forward(Container_Type el)
	{
		// ...
		Element<Container_Type>* newFirstElement = new Element<Container_Type>;
		newFirstElement->next = container;
		newFirstElement->container = el;
		container = newFirstElement;
		list_size++;
	}
	bool replace(const int id, const Container_Type& nElement)
	{
		try
		{
			if (id < 0)
				throw 1;
			if (id >= list_size)
				throw 2;
			Element<Container_Type> *temp_container = container;
			for (int i = 0; i < id; i++)
				temp_container = temp_container->next;
			temp_container->container = nElement;
			return true;
		}
		catch (int e)
		{
			std::cout << "List::replace(const int, Container_Type)\n"
				<< "Error - " << e << std::endl;
			return false;
		}
	}
	void remove(const int id)
	{
		try
		{
			if (id < 0)
				throw 1;
			if (id >= list_size)
				throw 2;
			if (list_size == 0)
				throw 3;
			if (list_size == 1)
			{
				delete container;
				container = new Element<Container_Type>;
				list_size = 0;
				return;
			}
			if (id == 0)
			{
				Element<Container_Type> * next = container->next;
				delete container;
				container = next;
				list_size--;
				return;
			}
			Element<Container_Type> * temp_container = container;
			for (int i = 1; i < id; i++)
			{
				temp_container = temp_container->next;
			}
			Element<Container_Type> * removedElement = temp_container->next;
			temp_container->next = removedElement->next;
			delete removedElement;
			list_size--;
			return;
		}
		catch (int e)
		{
			// !
			exit(0);
		}
	}
	int size() const
	{
		return list_size;
	}
};