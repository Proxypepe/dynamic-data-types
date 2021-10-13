#pragma once
#include "BST.h"
#include <assert.h>
//list.remove_if([](auto i) {return  i < 5; });

template <class T>
class List;

template <class T>
class  ListIterator;

template <class T>
class ListNode
{
private:
	friend class List<T>;
	friend class ListIterator<T>;
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;
	ListNode()		 : data(T()),  next(nullptr), prev(nullptr) {}
	ListNode(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <class T>
class  ListIterator
{
private:
	ListIterator(ListNode<T>* q) : _q(q) {};
	ListNode<T>* _q;
	friend class List <T>;

public:
	bool operator== (ListIterator i) const;
	bool operator!= (ListIterator i) const;
	void operator++ ();
	void operator--();
	T& operator*  ();
};

template <class T>
class List
{
private: 
	using value_type = T;
	using size_type = size_t;

	ListNode<T>* head;
	ListNode<T>* tail;

	size_type _size = 0;

	template<class H, class... Args>
	void push_back(H h, Args... args) { this->push_back(h); this->push_back(args...); }
	template<class H, class... Args>
	void push_front(H h, Args... args) { this->push_front(h); this->push_front(args...); }
	template<class H, class... Args>
	void insert(size_type pos, H h, Args... args) { this->insert(pos, h); this->insert(pos, args...); }

	void tree_into_list(BST<T>* v);

public:
	List() : head(nullptr), tail(nullptr) {}
	explicit List(std::initializer_list<value_type>);
	explicit List(size_type count, const value_type& value = 0);
	List(List<T>& other);
	List(List<T>&& other);

	~List() { this->clear(); }

	[[nodiscard]] bool empty() const noexcept;
	size_type size() const noexcept;

	void clear();
	void insert(size_type pos, const value_type& value);
	void insert(size_type pos, size_type count, const value_type& value);

	void erase(size_type pos);
	void erase(size_type first, size_type last);

	template<class... Args>
	void emplace(size_type pos, Args... args);

	void push_back(const value_type& value);
	void pop_back();
	template<class... Args>
	void emplace_back( Args... args);

	void push_front(const value_type& value);
	void pop_front();
	template<class... Args>
	void emplace_front(Args... args);

	void resize(size_type count, const value_type& value = 0);
	size_t remove(const value_type& value);
	template<class UnaryPredicate>
	size_t remove_if(UnaryPredicate p);
	void swap(List& other) noexcept;
	void reverse();
	void sort();
	void unique();

	List<T>*& front();
	List<T>*& back();
	T& operator[](const size_t i);
	friend std::ostream& operator<<(std::ostream& out, List<T>& List)
	{
		for (auto& i : List)
			out << i << " ";
		return out;
	}

	ListIterator<T> begin();
	ListIterator<T> end();
};

template<class T>
inline void List<T>::tree_into_list(BST<T>* v)
{
	if (v == nullptr)
		return;
	tree_into_list(v->get_left());
	this->push_back(v->get_data());
	tree_into_list(v->get_right());
}

template<class T>
inline List<T>::List(std::initializer_list<value_type> l)
{
	for (auto it = l.begin(); it != l.end(); it++)
		this->push_back(*it);
}

template<class T>
inline List<T>::List(size_type count, const value_type& value)
{
	for (size_t i = 0; i < count; i++)
		this->push_back(value);
}

template<class T>
inline List<T>::List(List<T>& other)
{
	ListNode<T>* q = other.head;
	while (q != nullptr)
	{
		this->push_back(q->data);
		q = q->next;
	}
}

template<class T>
inline List<T>::List(List<T>&& other)
{
	this = std::move(other);
}

template<class T>
inline bool List<T>::empty() const noexcept
{
	if (this->head == nullptr && this->tail == nullptr)
		return true;
	return false;
}

/*
* Returns the number of elements in the container
*@param none
*@return The number of elements in the container
*/
template<class T>
inline size_t List<T>::size() const noexcept
{
	return this->_size;
}

template<class T>
inline void List<T>::clear()
{
	while (this->_size)
		this->pop_front();
	this->tail = nullptr;
}

/*
* Inserts elements at the specified location in the container
* inserts value before pos
*@param pos - before which the content will be inserted
*@param value - element value to insert
*@return none
*/
template<class T>
inline void List<T>::insert(size_type pos, const value_type& value)
{
	if (!this->empty() && pos <= this->_size)
	{
		if (pos == 0)
			this->push_front(value);
		else if (pos == this->_size)
			this->push_back(value);
		else
		{
			ListNode<T>* q = this->head;
			ListNode<T>* _tmp = new ListNode<T>(value);
			for (size_t i = 0; i < pos - 1; i++)
				q = q->next;
			_tmp->next = q->next;
			_tmp->prev = q->next->prev;
			q->next->prev = _tmp;
			q->next = _tmp;
			this->_size++;
		}
	}
}

template<class T>
inline void List<T>::insert(size_type pos, size_type count, const value_type& value)
{
	if (!this->empty() && pos <= this->_size)
	{
		if (pos == 0)
			for (size_t i = 0; i < count; i++)
				this->push_front(value);
		else if (pos == this->_size)
			for (size_t i = 0; i < count; i++)
				this->push_back(value);
		else
			for (size_t i = 0; i < count; i++)
				this->insert(pos, value);
	}
}

template<class T>
inline void List<T>::erase(size_type pos)
{
	if (!this->empty() && pos <= this->_size)
	{
		if (pos == 0)
			this->pop_front();
		else if (pos == this->_size - 1)
			this->pop_back();
		else {
			ListNode<T>* q = this->head;
			for (size_t i = 0; i < pos ; i++)
				q = q->next;
			q->prev->next = q->next;
			q->next->prev = q->prev;
			delete q;
			this->_size--;
		}
	}
}

template<class T>
inline void List<T>::erase(size_type first, size_type last)
{
	if (!this->empty() && last <= this->_size && this->_size - first > last - first)
	{
		size_type _tmp = last - first;
		if (first == 0)
			for (size_type i = 0; i < _tmp; i++)
				this->pop_front();
		else if (first == this->_size - 1)
			for (size_type i = 0; i < _tmp; i++)
				this->pop_back();
		else
		{
			for (size_type i = 0; i < _tmp; i++)
				this->erase(first + i);
		}
	}
}

template<class T>
template<class ...Args>
inline void List<T>::emplace(size_type pos, Args ...args)
{
	this->insert(pos, args...);
}

/*
* Appends the given element value to the end of the container.
*@param value - the value of the element to append
*@return none
*/
template<class T>
inline void List<T>::push_back(const value_type& value)
{
	if (this->empty())
	{
		this->head = this->tail = new ListNode<T>(value);
	}
	else
	{
		ListNode<T>* q = new ListNode<T>(value);
		q->prev = this->tail;
		this->tail->next = q;
		this->tail = q;
	}
	this->_size++;
}

/*
* Removes the last element of the container
*@param none
*@return none
*/
template<class T>
inline void List<T>::pop_back()
{
	if (!this->empty()) {
		this->_size--;
		ListNode<T>* q = this->tail;
		this->tail = this->tail->prev;
		delete q;
		if (this->_size != 0)
			this->tail->next = nullptr;
		else
			this->head = nullptr;
	}
}

template<class T>
template<class ...Args>
inline void List<T>::emplace_back(Args ...args)
{
	this->push_back(args...);
}

/*
* Prepends the given element value to the beginning of the container.
* @param value - the value of the element to prepend
* @return none
*/
template<class T>
inline void List<T>::push_front(const value_type& value)
{
	if (this->empty())
		this->head = this->tail = new ListNode<T>(value);
	else
	{
		ListNode<T>* q = new ListNode<T>(value);
		q->next = this->head;
		this->head->prev = q;
		this->head = q;
	}
	this->_size++;
}

/*
* Removes the first element of the container
*@param none
*@return none
*/
template<class T>
inline void List<T>::pop_front()
{
	if (!this->empty())
	{
		this->_size--;
		ListNode<T>* q = this->head;
		this->head = this->head->next;
		delete q;
		if (this->_size != 0)
			this->head->prev = nullptr;
		else
			this->tail = nullptr;
	}
}

template<class T>
template<class ...Args>
inline void List<T>::emplace_front(Args ...args)
{
	this->push_front(args...);
}

template<class T>
inline void List<T>::resize(size_type count, const value_type& value)
{
	if (!this->empty())
	{
		if (this->_size > count)
			while (this->_size != count)
				this->pop_back();
		else if (this->_size < count)
			while (this->_size != count)
				this->push_back(value);
	}
	else
	{
		for (size_t i = 0; i < count; i++)
		{
			this->push_back(value);
		}
	}
}

/*
*Removes all elements satisfying specific criteria
*@param value - value of the elements to remove
*@return none
*/
template<class T>
inline size_t List<T>::remove(const value_type& value)
{
	size_t counter, removed, start_size;
	counter = removed = 1;
	start_size = this->_size;
	ListNode<T>* q = this->head;
	while (q != nullptr)
	{
		if (q->data == value)
		{
			if (q->prev == nullptr)
			{
				q = q->next;
				this->pop_front();
			}
			else if (q->next == nullptr)
			{
				this->pop_back();
				break;
			}
			else
			{
				ListNode<T>* _tmp;
				q->prev->next = q->next;
				q->next->prev = q->prev;
				_tmp = q;
				q = q->next;
				delete _tmp;
				this->_size--;
				removed++;
			}
		}
		else
			q = q->next;
		counter++;
	}
	return removed;
}

template<class T>
inline void List<T>::swap(List& other) noexcept
{
	ListNode<T>* q = this->head;
	ListNode<T>* p = other.head;
	this->head = p;
	other.head = q;
	size_t _tmp_size = this->_size;
	this->_size = other._size;
	other._size = _tmp_size;
}

template<class T>
inline void List<T>::reverse()
{
	if (!this->empty() && this->_size > 1)
	{
		ListNode<T>* q = this->head;
		ListNode<T>* _q = this->head;
		while (q->next != nullptr)
			q = q->next;
		this->head = q;
		ListNode<T>* p = this->head;
		if (this->_size > 2)
		{
			for (size_t i = 0; i < this->_size - 1; i++)
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
inline void List<T>::sort()
{
	BST<T>* tree = nullptr;
	ListNode<T>* q = this->head;
	while (q != nullptr)
	{
		tree->add_node(tree, q->data);
		q = q->next;
	}
	this->clear();
	this->tree_into_list(tree);
}

template<class T>
inline void List<T>::unique()
{
	if (!this->empty())
	{
		size_t _size_ = this->_size;
		T* uni = new T[_size_];
		for (size_t i = 0; i < _size_; i++)
			uni[i] = T();
		ListNode<T>* q = this->head;
		size_t _counter = 0;
		bool flag = true;
		while (q != nullptr)
		{
			for (size_t i = 0; i < _size_; i++)
			{
				if (q->data == uni[i])
					flag = false;
			}
			if (flag)
				uni[_counter] = q->data;
			_counter++;
			flag = true;
			q = q->next;
		}
		this->clear();
		for (size_t i = 0; i < _size_; i++)
		{
			if (uni[i] != T())
				this->push_back(uni[i]);
		}
		delete[] uni;
	}
}

template<class T>
template<class UnaryPredicate>
inline size_t List<T>::remove_if(UnaryPredicate p)
{
	size_t counter, removed, start_size;
	counter = removed = 0;
	start_size = this->_size;
	ListNode<T>* q = this->head;
	while (q != nullptr)
	{
		if (p(q->data))
		{
			if (q->prev == nullptr)
			{
				q = q->next;
				this->pop_front();
			}
			else if (q->next == nullptr)
			{
				this->pop_back();
				break;
			}
			else
			{
				ListNode<T>* _tmp;
				q->prev->next = q->next;
				q->next->prev = q->prev;
				_tmp = q;
				q = q->next;
				delete _tmp;
				this->_size--;
			}
		}
		else
			q = q->next;
		counter++;
	}
	return removed;
}

template<class T>
T& List<T>::operator[](const size_t i)
{
	assert(i < this->_size);
	int counter = 0;
	ListNode<T>* q = this->head;
	while (q != nullptr)
	{
		if (counter == i)
			return q->data;
		q = q->next;
		counter++;
	}
}

template<class T>
inline List<T>*& List<T>::front()
{
	return this->head;
}

template<class T>
inline List<T>*& List<T>::back()
{
	return this->tail;
}

template<class T>
inline ListIterator<T> List<T>::begin()
{
	return this->head;
}

template<class T>
inline ListIterator<T> List<T>::end()
{
	return this->tail;
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
	this->_q = this->_q->next;
}

template<class T>
inline void ListIterator<T>::operator--()
{
	this->_q = this->_q->prev;
}

template<class T>
inline T& ListIterator<T>::operator*()
{
	return this->_q->data;
}
