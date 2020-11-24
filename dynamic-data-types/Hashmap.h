#pragma once
#include <iostream>
#include "Forword_List.h"

template <class T>
class Hashmap
{
private:
	size_t size = 0;
	size_t k = 0;
	Forword_list<T>* hashList;
	double loadedFactor = 0;
	
	int to_hash(int key);
	bool is_loaded();
	Forword_list<T>* rehash();
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
inline Forword_list<T>* Hashmap<T>::rehash()
{	
	int _index;
	this->size *= 2;
	Forword_list<T>* temp = new Forword_list<T>[this->size];												
	for (int i = 0; i < this->size / 2; i++)
	{
		while (!this->hashList[i].is_empty())
		{
			T _data = this->hashList[i].peek_front();
			this->hashList[i].pop_front();
			_index = this->to_hash(_data.getNumber());
			temp[_index].push_back(_data);
		}
	}
	delete[] this->hashList;

	return  temp;
}
 

template<class T>
inline Hashmap<T>::Hashmap(size_t N)
{
	this->size = N;
	hashList = new Forword_list<T>[this->size];
}

template<class T>
inline Hashmap<T>::~Hashmap()
{
	delete[] hashList;
}

template<class T>
inline void Hashmap<T>::print_map()
{
	for (int i = 0; i < this->size; i++)
	{
		if (!this->hashList[i].is_empty())
		{
			std::cout << "\n";
			std::cout << "Forword_list # " << i << "\n";
			this->hashList[i].print_list();
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
		hashList[index].push_back(data);
	}
	else
	{
		this->hashList = this->rehash();
		this->add_element(data, key);
	}
}

