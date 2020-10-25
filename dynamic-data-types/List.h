#pragma once

#include <iostream>
#include <assert.h>

template <class T>
class List
{
private:
	template <class T>
	class Tnode
	{
	public:
		T field = T();
		Tnode<T>* next = nullptr;
	};

	size_t size = 0;

	Tnode<T>* head = nullptr;		
	Tnode<T>* R = nullptr;

	T get_field();

public:
	List();
	~List()
	{
		this->clear();
	}
	size_t get_size();
	int lenght();
	void print_list();
	void pop_front();
	T peek_front();
	void push_back(T data);
	void insert(int pos, T data);
	void del(int pos);
	bool is_empty();
	void clear();


	T& operator[](const int i);
};

template<class T>
inline T List<T>::get_field()
{
	return this->field;
}

template<class T>
inline List<T>::List()
{
	head = nullptr;
}

template<class T>
inline size_t List<T>::get_size()
{
	return this->size;
}


template<class T>
inline int List<T>::lenght()
{
	Tnode<T>* q = this->head;
	int _lenght = 0;
	while (q != nullptr)
	{
		_lenght++;
		q = q->next;
	}
	return _lenght;
}

template<class T>
inline void List<T>::print_list()
{
	//if (!this->is_empty())
	//{
		Tnode<T>* q = this->head;
		while (q != nullptr)
		{
			std::cout << q->field << "\n";
			q = q->next;
		//}
	}
}

template<class T>
inline void List<T>::pop_front()
{
	Tnode<T>* q = this->head;
	this->head = this->head->next;
	delete q;
	this->size--;
}

template<class T>
inline T List<T>::peek_front()
{
	return this->head->field;
}

template<class T>
inline void List<T>::push_back(T data)
{
	Tnode<T>* q = new Tnode<T>;																															
	q->field = data;															
	q->next = nullptr;															
	if (this->head == nullptr)															
	{
		this->head = q;																
		this->R = q;
	}
	else {
		this->R->next = q;
		this->R = q;																
	}
	this->size++;
}

template<class T>
inline void List<T>::insert(int pos, T data)
{
	Tnode<T>* q = this->head;
	Tnode<T>* tmp = new Tnode<T>;
	tmp->field = data;
	if (pos == 0)
	{
		tmp->next = this->head;
		this->head = tmp;
	}
	else if (pos == size)
	{
		int _i = 0;

		while (_i != pos - 1)
		{
			q = q->next;
			_i++;
		}
		this->R->next = tmp;
		this->R = tmp;
	}
	else
	{
		int _i = 0;

		while (_i != pos - 1)
		{
			q = q->next;
			_i++;
		}
		tmp->next = q->next;
		q->next = tmp;
	}
	this->size++;
}

template<class T>
inline void List<T>::del(int pos)
{
	Tnode<T>* q = this->head;
	Tnode<T>* _tmp = this->head;
	assert(pos >= 0);
	assert(pos < this->lenght());
	if (q != nullptr && (pos < this->lenght() - 1) && (pos >= 0))
	{
		for (int i = 0; i < pos; i++)
		{
			_tmp = q;
			q = q->next;
		}
		if (q == this->head)
		{
			this->head = q->next;
		}
		else
		{
			_tmp->next = _tmp->next->next;
		}
		delete q;
	}
	else if (q != nullptr &&  (pos == this->lenght()))
	{
		this->R->next = q;
		this->R = q;
		_tmp->next = q->next;
		delete q;
	}
	this->size--;
}

template<class T>
inline bool List<T>::is_empty()
{
	if (this->head == nullptr)
		return true;
	return false;
}

template<class T>
inline void List<T>::clear()
{
	while (size)
	{
		this->pop_front();
	}
}

template<class T>
T& List<T>::operator[](const int i)
{
	assert(this->head == nullptr);
	assert(i < this->size);
	int counter = 0;
	Tnode<T>* q = this->head;
	while (q != nullptr)
	{
		if (counter == i)
			return q->field;
		q = q->next;
		counter++;
	}
}

