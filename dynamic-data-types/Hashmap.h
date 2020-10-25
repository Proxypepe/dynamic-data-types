#pragma once
#include <iostream>
#include "List.h"

template <class T>
class Hashmap
{
private:
	size_t size = 0;
	size_t k = 0;
	List<T>* list;
	double loadedFactor = 0;
	
	int to_hash(int key);
	bool is_loaded();
	List<T>* rehash();
public:
	Hashmap(size_t N);
	~Hashmap();
	void print_map();
	void add_element(T data, int key);
};


template<class T>
inline int Hashmap<T>::to_hash(int key)
{
	return  key % size;
}

template<class T>
inline bool Hashmap<T>::is_loaded()
{
	this->loadedFactor = (double)this->k / (double)this->size;
	if (this->loadedFactor > 0.75)
		return true;
	return false;
}

template<class T>
inline List<T>* Hashmap<T>::rehash()
{	
	int _index;
	this->size *= 2;
	List<T>* temp = new List<T>[this->size];												
	for (int i = 0; i < this->size / 2; i++)
	{
		while (!this->list[i].is_empty())
		{
			T _data = this->list[i].peek_front();
			this->list[i].pop_front();
			_index = this->to_hash(_data.getNumber());
			temp[_index].push_back(_data);
		}
	}
	delete[] this->list;

	return  temp;
}
 

template<class T>
inline Hashmap<T>::Hashmap(size_t N)
{
	this->size = N;
	list = new List<T>[this->size];
}

template<class T>
inline Hashmap<T>::~Hashmap()
{
	delete[] list;
}

template<class T>
inline void Hashmap<T>::print_map()
{
	for (int i = 0; i < this->size; i++)
	{
		if (!this->list[i].is_empty())
		{
			std::cout << "\n";
			std::cout << "List # " << i << "\n";
			this->list[i].print_list();
		}
	}
}

template<class T>
inline void Hashmap<T>::add_element(T data, int key)
{
	this->k++;
	if (!is_loaded())
	{
		int index;
		index = this->to_hash(key);
		assert(index < size);
		list[index].push_back(data);
	}
	else
	{
		this->list = this->rehash();
		this->add_element(data, key);
	}
}

