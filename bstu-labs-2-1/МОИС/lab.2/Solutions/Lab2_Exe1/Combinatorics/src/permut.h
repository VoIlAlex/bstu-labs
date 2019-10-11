// permut.h
// Permutations

#pragma once
#include <iostream>

namespace MySpace
{
	int fact(int n);
	template<typename T>
	void swap(T &first, T &second)
	{
		T temp = first;
		first = second;
		second = temp;
	}
}

template<typename T>
class Permut
{
private:
	T *arr;
	int size;
	T *copy_arr;
	// temp_ is prefix of function elements
	// current permutation number 
	int temp_currentId;
	bool temp_break;
	int temp_currentEl;
	void get(int id, int k)
	{
		if (this->temp_break == true)
			return;
		if (this->temp_currentId == id)
		{
			this->temp_break = true;
			return;
		}
		if (this->temp_currentEl >= k)
		{
			this->temp_currentEl--;
			return;
		}

		for (int i = this->temp_currentEl; i < this->size; i++)
		{
			MySpace::swap(this->copy_arr[this->temp_currentEl], this->copy_arr[i]);
			if (i != this->temp_currentEl)
				this->temp_currentId++;
			this->temp_currentEl++;
			this->get(id, k);
			if (this->temp_break == true)
				return;
			MySpace::swap(this->copy_arr[this->temp_currentEl], this->copy_arr[i]);

		}
		this->temp_currentEl--;
	}
public:
	Permut() 
	{
		this->arr = nullptr;
		this->copy_arr = nullptr;
		this->size = 0;
	}
	Permut(T *arr, int size)
	{
		this->size = size;
		this->arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = arr[i];
		this->copy_arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
			this->copy_arr[i] = arr[i];
	}
	Permut(const Permut& obj)
	{
		this->size = obj.size;
		this->arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = obj.arr[i];
		this->copy_arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
			this->copy_arr[i] = obj.arr[i];
	}
	~Permut()
	{
		if (size != 0)
		{
			delete[] arr;
			delete[] copy_arr;
		}
	}

	void setArr(T* arr, int size)
	{
		if (size != 0)
		{
			delete[] this->arr;
			delete[] this->copy_arr;
		}
		this->size = size;
		this->arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = arr[i];
		this->copy_arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
			this->copy_arr[i] = arr[i];
	}
	void get(int id, int k, T*&arr)
	{
		try
		{
			if (id < 0)
				throw 1;
			if (id > this->number(k))
				throw 2;
			if (k < 0)
				throw 3;
			if (k == 0)
			{
				arr = nullptr;
				return;
			}
			if (k > this->size)
				throw 4;
			for (int i = 0; i < this->size; i++)
				this->copy_arr[i] = this->arr[i];
			this->temp_currentId = 0;
			this->temp_currentEl = 0;
			this->temp_break = false;
			this->get(id, k);
			this->temp_currentId = 0;
			this->temp_currentEl = 0;
			this->temp_break = false;
			arr = new T[this->size];
			for (int i = 0; i < this->size; i++)
				arr[i] = this->copy_arr[i];
		}
		catch (int e)
		{
			std::cout << "template<typename T>\nT Permut<T>::operator[](int)\t Error - " << e << std::endl;
			system("pause");
			exit(1);
		}
	}
	int number(int k)
	{
		return MySpace::fact(this->size) / MySpace::fact(this->size - k);
	}
};