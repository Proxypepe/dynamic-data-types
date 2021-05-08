#pragma once
#include <iostream>

template <class T>
class Avl
{
	using pAvl = Avl<T>*;
	using tAvl = Avl<T>;
	using value_type = T;
	using cr_value_type = const value_type&;

private:
	pAvl		_left = nullptr;
	pAvl		_right = nullptr;
	value_type	_field = value_type();
	int	_height = 1;


private:
	void printInOder_(pAvl);
	int max(const int&, const int&);
	pAvl leftRotate(pAvl);
	pAvl rightRotate(pAvl);
	int height(pAvl);
	int getBalanceIndex(pAvl);

public:
	Avl() {}
	Avl(cr_value_type value) : _field(value), _left(nullptr), _right(nullptr), _height(1) {}
	pAvl instert(pAvl&, cr_value_type); //TODO decide problem with ref
	void printInOder() { printInOder_(this); }
};

template<class T>
inline void Avl<T>::printInOder_(pAvl v)
{
	if (v == nullptr)
		return;
	printInOder_(v->_left);
	std::cout << "field: " << v->_field << "\n";
	printInOder_(v->_right);
}

template<class T>
inline int Avl<T>::max(const int& a, const int& b)
{
	return (a > b) ? a : b;
}

template<class T>
inline Avl<T>* Avl<T>::instert(pAvl& v, cr_value_type value)
{
	if (v == nullptr)
	{
		v = new tAvl(value);
		return v;
	}
	if (v->_field > value)
		v->_left = instert(v->_left, value);
	else if (v->_field < value)
		v->_right = instert(v->_right, value);
	else 
		return v;

	v->_height = 1 + max(height(v->_left),
		height(v->_right));

	int balance = getBalanceIndex(v);

	if (balance > 1 && value < v->_left->_field)
		return rightRotate(v);

	if (balance < -1 && value > v->_right->_field)
		return leftRotate(v);

	if (balance > 1 && value > v->_left->_field)
	{
		v->_left = leftRotate(v->_left);
		return rightRotate(v);
	}

	if (balance < -1 && value < v->_right->_field)
	{
		v->_right = rightRotate(v->_right);
		return leftRotate(v);
	}

	return v;
}

template<class T>
inline Avl<T>* Avl<T>::leftRotate(pAvl x)
{
	pAvl y = x->_right;
	pAvl T2 = y->_left;
	y->_left = x;
	x->_right = T2;

	x->_height = max(height(x->_left), height(x->_right)) + 1;
	y->_height = max(height(y->_left), height(y->_right)) + 1;

	return y;
}

template<class T>
inline Avl<T>* Avl<T>::rightRotate(pAvl y)
{
	pAvl x = y->_left;
	pAvl T2 = x->_right;
	x->_right = y;
	y->_left = T2;

	y->_height = max(height(y->_left), height(y->_right)) + 1;
	x->_height = max(height(x->_left), height(x->_right)) + 1;
	return x;
}

template<class T>
inline int Avl<T>::height(pAvl v)
{
	if (v == nullptr)
		return 0;
	return v->_height;
}

template<class T>
inline int Avl<T>::getBalanceIndex(pAvl v)
{
	if (v == nullptr)
		return 0;
	return height(v->_left) - height(v->_right);
}
