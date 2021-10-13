#pragma once

template <class T>
class Stack;

template <class T>
class StackNode
{
public:
	T data = T();
	StackNode<T>* next = nullptr;
	friend class Stack<T>;
	StackNode(T data) : data(data) { next = nullptr; };
	StackNode() { data = T(); next = nullptr; }
}; 

template <class T>
class Stack
{
private:

	using value_type = T;
	using size_type = size_t;

	StackNode<value_type>* head;
	size_type _size = 0;
	size_type max_size;

public:
	explicit Stack(size_type max_size) : max_size(max_size), head(nullptr) {};
	Stack(const Stack& other);

	~Stack();

	bool empty() const;
	size_t size() const;

	void push(const value_type& value);
	void pop();
	void clear();
	//void print_stack();

	StackNode<T>* top();

};

template<class T>
inline Stack<T>::Stack(const Stack& other)
{
	StackNode<T>* q = this->head;
}

template<class T>
inline Stack<T>::~Stack()
{
	this->clear();
}

/*
*Checks whether the underlying container is empty
*@param none
*@return true if the underlying container is empty, false otherwise
*/
template<class T>
inline bool Stack<T>::empty() const
{
	if (this->head == nullptr)
		return true;
	return false;
}

/*
*Returns the number of elements in the underlying container
*@param none
*@return the number of elements in the container
*/
template<class T>
inline size_t Stack<T>::size() const
{
	return this->_size;
}

/*
*Pushes the given element value to the top of the stack
*@param value - the value of the element to push
*@return none
*/
template<class T>
inline void Stack<T>::push(const value_type& value)
{
	if (this->_size <= this->max_size)
	{
		if (this->empty())
			this->head = new StackNode<T>(value);
		else
		{
			StackNode<T>* q = this->head;
			while (q->next != nullptr)
			{
				q = q->next;
			}
			q->next = new StackNode<T>(value);
		}
		this->_size++;
	}
}

/*
*Removes the top element from the stack
*@param none
*@return none
*/
template<class T>
inline void Stack<T>::pop()
{
	if (this->head != nullptr)
	{
		StackNode<T>* q = this->head;

		if (this->_size == 1)
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
		this->_size--;
	}
}

/*
*Removes all elements from the stack
*@param none
*@return none
*/
template<class T>
inline void Stack<T>::clear()
{
	while (this->_size)
		this->pop();
}

//template<class T>
//inline void Stack<T>::print_stack()
//{
//	if (this->empty())
//		cout << "Stack is empty";
//	else {
//		StackNode<T>* q = this->head;
//		while (q != nullptr)
//		{
//			cout << q->data << "  ";
//			q = q->next;
//		}
//	}
//}

/*
*Returns a reference to the top of the stack
*@param none
*@return a reference to the top of the stack
*/
template<class T>
inline StackNode<T>* Stack<T>::top()
{
	if (this->empty())
		return nullptr;
	else
	{
		StackNode<T>* q = this->head;
		while (q->next != nullptr)
			q = q->next;
		return q;
	}
}
