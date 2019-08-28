#pragma once
#include <iostream>

template<typename Container_Type>
class List
{
	int list_size;
	struct Element
	{
		Container_Type container;
		Element* next;
		Element()
			: next(nullptr) {}
		Element(const Container_Type& other)
			: next(other.next), container(other.container) {}
	} *firstElement;
public:
	List()
		: list_size(0), firstElement(new Element) {};
	List(const List& obj)
		: list_size(obj.list_size), firstElement(new Element)
	{
		Element* temp_element = firstElement;
		Element* temp_obj_element = obj.firstElement;
		for (int i = 0; i < list_size; i++)
		{
			temp_element->container = temp_obj_element->container;
			temp_element->next = new Element;
			temp_element = temp_element->next;
			temp_obj_element = temp_obj_element->next;
		}
	}
	~List()
	{
		Element *temp_element = firstElement;
		for (int i = 0; i < list_size; i++)
		{
			for (int j = 1; j < (list_size - i); j++)
			{
				temp_element = temp_element->next;
			}
			delete temp_element->next;
			temp_element = firstElement;
		}
		delete firstElement;
	}
	Container_Type operator[](const int id) const
	{
		try
		{
			if (id < 0)
				throw 1;
			if (id >= list_size)
				throw 2;
			Element *temp_element = firstElement;
			for (int i = 0; i < id; i++)
				temp_element = temp_element->next;
			return temp_element->container;
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
			Element *temp_element = firstElement;
			for (int i = 0; i < id; i++)
				temp_element = temp_element->next;
			return temp_element->container;
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
			Element *temp_element_for_deleting = firstElement;
			for (int i = 0; i < list_size; i++)
			{
				for (int j = 1; j < (list_size - i); j++)
				{
					temp_element_for_deleting = temp_element_for_deleting->next;
				}
				delete temp_element_for_deleting->next;
				temp_element_for_deleting = firstElement;
			}
			delete firstElement;
			firstElement = new Element;
		}
		list_size = obj.list_size;
		Element* temp_element = firstElement;
		Element* temp_obj_element = obj.firstElement;
		for (int i = 0; i < list_size; i++)
		{
			temp_element->container = temp_obj_element->container;
			temp_element->next = new Element;
			temp_element = temp_element->next;
			temp_obj_element = temp_obj_element->next;
		}
		return (*this);
	}
	void push_back(const Container_Type& el)
	{
		Element* temp_element = firstElement;
		for (int i = 0; i < list_size; i++)
			temp_element = temp_element->next;
		temp_element->Element::container = Container_Type(el);
		temp_element->next = new Element;
		list_size++;
	}
	void push_forward(Container_Type el)
	{
		// ...
		Element* newFirstElement = new Element;
		newFirstElement->next = firstElement;
		newFirstElement->container = el;
		firstElement = newFirstElement;
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
			Element *temp_element = firstElement;
			for (int i = 0; i < id; i++)
				temp_element = temp_element->next;
			temp_element->container = nElement;
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
				delete firstElement;
				firstElement = new Element;
				list_size = 0;
				return;
			}
			if (id == 0)
			{
				Element * next = firstElement->next;
				delete firstElement;
				firstElement = next;
				list_size--;
				return;
			}
			Element * temp_element = firstElement;
			for (int i = 1; i < id; i++)
			{
				temp_element = temp_element->next;
			}
			Element * removedElement = temp_element->next;
			temp_element->next = removedElement->next;
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
	int find(const Container_Type& el)
	{
		int res = -1;
		for (int i = 0; i < list_size; i++)
			if (getAccess(i) == el)
			{
				res = i;
				break;
			}
		return res;
	}
};