#pragma once

#include <iostream>
#include <assert.h>

template <class T>
class  ListIterator;

template <class T>
class List;
// Node class
template <class T>
class Tnode
{
private:
	T field = T();
	Tnode<T>* next = nullptr;
	friend class List<T>;
	friend class ListIterator<T>;
public:
	Tnode(T data) : field(data) { next = nullptr; };
	Tnode(){ field = T(); next = nullptr;}
};

// List Iterator class 
template <class T>
class  ListIterator
{
private:
	ListIterator(Tnode<T>* q) : _q(q) {};
	Tnode<T>* _q;
	friend class List<T>;

public:
	bool operator== (ListIterator i) const;
	bool operator!= (ListIterator i) const;
	void operator++ ();
	T& operator*  ();
};


// List class
template <class T>
class List
{
private:

	size_t size = 0;

	Tnode<T>* head = nullptr;		

	T get_field();

public:
	List();
	~List()	{this->clear();}

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

	void swap(List<T>& other);

	bool is_empty();


	T peek_front();

	T& operator[](const size_t i);
	List<T>& operator=(const List<T>& other);

	ListIterator<T> begin();
	ListIterator<T> end();

};

template<class T>
inline T List<T>::get_field()
{
	return this->field;
}

template<class T>
inline List<T>::List()
{
	this->head = nullptr;
}

template<class T>
inline size_t List<T>::get_size()
{
	return this->size;
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
inline void List<T>::print_list()
{
	Tnode<T>* q = this->head;
	while (q != nullptr)
	{
		std::cout << q->field << "\n";
		q = q->next;
	}
}

template<class T>
inline void List<T>::print_list_()
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
inline void List<T>::push_front(T data)
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
inline void List<T>::pop_front()
{
	Tnode<T>* q = this->head;
	this->head = this->head->next;
	delete q;
	this->size--;
}

template<class T>
inline void List<T>::push_back(T data)
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
inline void List<T>::pop_back()
{
	if (this->head != nullptr)
	{
		Tnode<T>* q = this->head;

		while (q->next->next != nullptr)
			q = q->next;
		delete q->next;
		q->next = nullptr;
		this->size--;
	}
}

template<class T>
inline void List<T>::insert(size_t pos, T data)
{
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
inline void List<T>::remove(size_t pos)
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
inline void List<T>::swap(List<T>& other)
{
	//pass


}

template<class T>
inline bool List<T>::is_empty()
{
	if (this->head == nullptr)
		return true;
	return false;
}

template<class T>
inline T List<T>::peek_front()
{
	return this->head->field;
}

template<class T>
T& List<T>::operator[](const size_t i)
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
inline List<T>& List<T>::operator=(const List<T>& other)
{
	return  *this;
}

template<class T>
inline ListIterator<T> List<T>::begin()
{ 
	return head;
}

template<class T>
inline ListIterator<T> List<T>::end()
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
