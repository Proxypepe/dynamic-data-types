#pragma once

#include <iostream>
#include "BST.h"
#include <assert.h>
#include "MyException.h"

template <class T>
class  ListIterator;

template <class T>
class Forword_list;
// Node class
template <class T>
class Tnode
{
private:
	T field = T();
	Tnode<T>* next = nullptr;
	friend class Forword_list<T>;
	friend class ListIterator<T>;
	explicit Tnode(T data) : field(data), next(nullptr) {}
	explicit Tnode()  :field(T()), next(nullptr){}
public:

};

// Forword_list Iterator class 
template <class T>
class  ListIterator
{
private:
	ListIterator(Tnode<T>* q) : _q(q) {};
	Tnode<T>* _q;
	friend class Forword_list<T>;

public:
	bool operator== (ListIterator i) const;
	bool operator!= (ListIterator i) const;
	void operator++ ();
	T& operator*  ();
};

// Forword_list class
template <class T>
class Forword_list
{
private:

	size_t size = 0;

	Tnode<T>* head = nullptr;		

	T get_field();
	void fix_size();
	void tree_into_list(BST<T>* v);

public:
	Forword_list();
	Forword_list(size_t count);
	Forword_list(size_t count, T value);
	Forword_list(const Forword_list<T>& x);
	Forword_list(Forword_list<T>&& x);

	~Forword_list()	{this->clear();}

	size_t get_size();

	void clear();

	void print_list();
	void print_list_();

	void push_front(T data);
	void pop_front();

	void push_back(T data);
	void pop_back();

	void insert(size_t pos, T data);
	void remove(size_t pos);

	void change_element(size_t pos, T data);

	void swap(Forword_list<T>& other);
	void splice(size_t pos, Forword_list<T>& other);
	void reverse();
	void resize(size_t n, T val = T());
	void unique();
	void sort();

	bool is_empty();

	T peek_front();

	T& operator[](const size_t i);
	Forword_list<T>& operator=(const Forword_list<T>& other);

	friend std::ostream& operator<<(std::ostream& out, Forword_list<T>& Forword_list)
	{
		for (auto& i : Forword_list)
			out << " " << i;
		return out;
	}

	ListIterator<T> begin();
	ListIterator<T> end();
};

template<class T>
inline T Forword_list<T>::get_field()
{
	return this->field;
}

template<class T>
inline void Forword_list<T>::fix_size()
{
	if (this->head == nullptr)
		this->size = 0;
	else
	{
		Tnode<T>* q = this->head;
		this->size;
		while (q != nullptr)
		{
			this->size++;
			q = q->next;
		}
		this->size--;
	}
}

template<class T>
inline void Forword_list<T>::tree_into_list(BST<T>* v)
{
	if (v == nullptr)
		return;
	tree_into_list(v->get_left());
	this->push_back(v->get_data());
	tree_into_list(v->get_right());
}

template<class T>
inline Forword_list<T>::Forword_list()
{
	this->head = nullptr;
}

template<class T>
inline Forword_list<T>::Forword_list(size_t count)
{
	for (size_t i = 0; i < count; i++)
		this->push_back(0);
}

template<class T>
inline Forword_list<T>::Forword_list(size_t count, T value)
{
	for (size_t i = 0; i < count; i++)
		this->push_back(value);
}

template<class T>
inline Forword_list<T>::Forword_list(const Forword_list<T>& x)
{
	Tnode<T>* q = x.head;
	while (q != nullptr)
	{
		this->push_back(q->field);
		q = q->next;
	}
}

template<class T>
inline Forword_list<T>::Forword_list(Forword_list<T>&& x)
{
	this = std::move(x);
}

template<class T>
inline size_t Forword_list<T>::get_size()
{
	return this->size;
}

template<class T>
inline void Forword_list<T>::clear()
{
	while (size)
		this->pop_front();
}

template<class T>
inline void Forword_list<T>::print_list()
{
	Tnode<T>* q = this->head;
	while (q != nullptr)
	{ 
		std::cout << q->field << "\n";
		q = q->next;
	}
}

template<class T>
inline void Forword_list<T>::print_list_()
{
	Tnode<T>* q = this->head;
	while (q != nullptr)
	{
		q->field.print();
		std::cout << "\n";
		q = q->next;
	}
}

template<class T>
inline void Forword_list<T>::push_front(T data)
{
	Tnode<T>* q = new Tnode<T>;
	q->field = data;
	q->next = nullptr;
	if (this->head == nullptr)
		this->head = q;
	else
	{
		q->next = this->head;
		this->head = q;
	}
	this->size++;
}

template<class T>
inline void Forword_list<T>::pop_front()
{
	Tnode<T>* q = this->head;
	this->head = this->head->next;
	delete q;
	this->size--;
}

template<class T>
inline void Forword_list<T>::push_back(T data)
{
	Tnode<T>* q; 
														
	if (this->head == nullptr)															
	{
		q = new Tnode<T>;
		q->field = data;
		q->next = nullptr;
		this->head = q;
	}
	else {
		q = this->head;
		while (q->next != nullptr)
			q = q->next;
		q->next = new Tnode<T>;
		q->next->field = data;
		q->next->next = nullptr;
	}
	this->size++;
}

template<class T>
inline void Forword_list<T>::pop_back()
{
	if (this->head != nullptr)
	{
		Tnode<T>* q = this->head;

		if (this->size == 1)
		{
			this->head = this->head->next;
			delete q;
		}
		else {
			while (q->next->next != nullptr)
				q = q->next;
			delete q->next;
			q->next = nullptr;
		}
		this->size--;
	}
}

template<class T>
inline void Forword_list<T>::insert(size_t pos, T data)
{
	try
	{
		if (pos > this->size)
			throw MyException();
	}
	catch(MyException& e)
	{
		cout << e.out_of_range();
	}
	if (this->head != nullptr && pos <= this->size)
	{
		if (pos == 0)
			this->push_front(data);
		else if (pos == this->size)
			this->push_back(data);
		else
		{
			Tnode<T>* q = this->head;
			Tnode<T>* _insert = new Tnode<T>(data);
			size_t iterator = 0;
			while (iterator != pos - 1)
			{
				q = q->next;
				iterator++;
			}
			_insert->next = q->next;
			q->next = _insert;
			this->size++;
		}
	}
}

template<class T>
inline void Forword_list<T>::remove(size_t pos)
{
	if (this->head != nullptr && pos <= this->size)
	{
		if (pos == 0)
			this->pop_front();
		else if (pos == this->size)
			this->pop_back();
		else
		{
			Tnode<T>* q = this->head;
			Tnode<T>* _delete;
			for (size_t i = 0; i < pos - 1; i++)
			{
				q = q->next;
			}
			_delete = q->next;
			q->next = q->next->next;
			delete _delete;
			this->size--;
		}
	}
}

template<class T>
inline void Forword_list<T>::change_element(size_t pos, T data)
{
	Tnode<T>* q = this->head;
	for (size_t i = 0; i < pos; i++)
	{
		q = q->next;
	}
	q->field = data;
}

template<class T>
inline void Forword_list<T>::swap(Forword_list<T>& other)
{
	Tnode<T>* q = this->head;
	Tnode<T>* p = other.head;
	this->head = p;
	other.head = q;
	size_t _tmp_size = this->size;
	this->size = other.size;
	other.size = _tmp_size;
}

template<class T>
inline void Forword_list<T>::splice(size_t pos, Forword_list<T>& other)
{
	Tnode<T>* q = this->head;
	size_t  _add_len = this->size - pos;
	this->size = pos;
	for (size_t i = 0; i < pos - 1; i++)
		q = q->next;
	if (other.head == nullptr)
		other.head = q->next;
	else
	{
		Tnode<T>* p = other.head;
		while (p->next != nullptr)
			p = p->next;
		p->next = q->next; 
	}
	q->next = nullptr;
	other.size += _add_len;
}

template<class T>
inline void Forword_list<T>::reverse()
{
	if (this->head != nullptr && this->size > 1)
	{
		Tnode<T>* q = this->head;
		Tnode<T>* _q = this->head;
		while (q->next != nullptr)
			q = q->next;
		this->head = q;
		Tnode<T>* p = this->head;
		if (this->size > 2)
		{
			for (size_t i = 0; i < this->size - 1; i++)
			{
				q = _q;
				while (q->next->next != nullptr)
					q = q->next;
				p->next = q;
				p = p->next;
				q->next = nullptr;
			}
			p = _q;
		}
		else
		{
			_q->next = nullptr;
			p->next = _q;
		}
	}
}

template<class T>
inline void Forword_list<T>::resize(size_t n, T val)
{
	if (this->size > n)
	{
		n = this->size - n;
		for (size_t i = 0; i < n; i++)
			this->pop_back();
	}
	else
	{
		n = n - this->size;
		for (size_t i = 0; i < n; i++)
			this->push_back(val);
	}
}

template<class T>
inline void Forword_list<T>::unique()
{
	if (this->head != nullptr)
	{
		size_t _size = this->size;
		T* uni = new T[_size];
		for (size_t i = 0; i < _size; i++)
			uni[i] = T();
		Tnode<T>* q = this->head;
		size_t _counter = 0;
		bool flag = true;
		while (q != nullptr)
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (q->field == uni[i])
					flag = false;
			}
			if (flag)
				uni[_counter] = q->field;
			_counter++;
			flag = true;
			q = q->next;
		}
		this->clear();
		for (size_t i = 0; i < _size; i++)
		{
			if (uni[i] != T())
				this->push_back(uni[i]);
		}
		delete[] uni;
	}
}

template<class T>
inline void Forword_list<T>::sort()
{
	BST<T>* tree = nullptr;
	Tnode<T>* q = this->head;
	while (q != nullptr)
	{
		tree->add_node(tree, q->field);
		q = q->next;
	}
	this->clear();
	this->tree_into_list(tree);
}

template<class T>
inline bool Forword_list<T>::is_empty()
{
	if (this->head == nullptr)
		return true;
	return false;
}

template<class T>
inline T Forword_list<T>::peek_front()
{
	return this->head->field;
}

template<class T>
T& Forword_list<T>::operator[](const size_t i)
{
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

template<class T>
inline Forword_list<T>& Forword_list<T>::operator=(const Forword_list<T>& other)
{
	return  *this;
}

template<class T>
inline ListIterator<T> Forword_list<T>::begin()
{ 
	return head;
}

template<class T>
inline ListIterator<T> Forword_list<T>::end()
{
	return nullptr;
}

template<class T>
inline bool ListIterator<T>::operator==(ListIterator i) const
{
	return this->_q == i._q;
}

template<class T>
inline bool ListIterator<T>::operator!=(ListIterator i) const
{
	return this->_q != i._q;
}

template<class T>
inline void ListIterator<T>::operator++()
{	
	this->_q  = this->_q->next;
}

template<class T>
inline T& ListIterator<T>::operator*()
{
	return this->_q->field;
}
