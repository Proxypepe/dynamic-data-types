#pragma once
#include <iostream>

using std::cout;
using std::endl;

template <class T>
class BST
{
private:
	T data;
	BST<T>* left = nullptr;
	BST<T>* right = nullptr;

	BST<T>* make_node(T data);
	void _clear();

public:
	BST();
	BST(T data);
	~BST()
	{
		this->_clear();
	}
	BST<T>* clear(BST<T>*& v);
	void print_inoder();
	void print_postorder();

	BST<T>* add_node(BST<T>*& v, T data = T());
	BST<T>* min_node(BST<T>*& v);
	BST<T>* remove_node(BST<T>*& v, T key);

	BST<T>* get_left() { return this->left; };
	BST<T>* get_right() { return this->right; };

	T get_data();

};

template<class T>
inline BST<T>* BST<T>::make_node(T data)
{
	BST<T>* v = new BST<T>;
	v->data = data;
	v->left = nullptr;
	v->right = nullptr;
	return v;
}

template<class T>
inline void BST<T>::_clear()
{
	if (this == nullptr)
		return;
	this->left->_clear();
	this->right->_clear();
	//cout << "deleted: " << this->data;
	delete this;
}

template<class T>
inline BST<T>::BST()
{
	this->left = nullptr;
	this->right = nullptr;
	this->data = T();
}

template<class T>
inline BST<T>::BST(T data)
{
	this->left = nullptr;
	this->right = nullptr;
	this->data = data;
}

template<class T>
inline BST<T>* BST<T>::clear(BST<T>*& v)
{
	v->_clear();
	v = nullptr;
	return v;
}

template<class T>
inline void BST<T>::print_inoder()
{
	if (this == nullptr)
		return;
	this->left->print_inoder();
	cout << this->data << "  ";
	this->right->print_inoder();
}

template<class T>
inline void BST<T>::print_postorder()
{
	if (this == nullptr)
		return;
	this->left->print_inoder();
	this->right->print_inoder();
	cout << this->data << "  ";
}

template<class T>
inline BST<T>* BST<T>::add_node(BST<T>*& v, T data)
{
	if (v == nullptr)
	{
		v = new BST<T>(data);
		return v;
	}
	else if (v->data > data)
	{
		v->left = add_node(v->left, data);
	}
	else
	{
		v->right = add_node(v->right, data);
	}
	return v;
}

template<class T>
inline BST<T>* BST<T>::min_node(BST<T>*& v)
{
	if (v->left == nullptr)
		return v;
	v->min_node(v->left);
}

template<class T>
inline BST<T>* BST<T>::remove_node(BST<T>*& v, T key)
{
	if (v == nullptr)
		return nullptr;
	if (key > v->data)
		remove_node(v->right, key);
	else if (key < v->key)
		remove_node(v->left, key);
	else if (key == v->data)
	{
		if (v->left == nullptr && v->right == nullptr)
		{
			delete v;
			v = nullptr;
		}
		else if ((v->left == nullptr && v->right != nullptr) || (v->left != nullptr && v->right == nullptr))
		{
			if (v->right != nullptr)
			{
				BST<T>* _tmp = v->right;
				delete v;
				v = nullptr;
				v = _tmp;
			}
			else if (v->left != nullptr)
			{
				BST<T>* _tmp = v->left;
				delete v;
				v = _tmp;
			}
		}
		else if (v->left != nullptr && v->right != nullptr)
		{
			if (v->right->left == nullptr)
			{
				BST<T>* _tmp = v;
				v = v->right;
				v->left = _tmp->left;
				delete _tmp;
			}
			else
			{
				BST<T>* _tmp = min_node(v->right);
				v->data = _tmp->data;
				delete _tmp;
			}
		}
	}
}

template<class T>
inline T BST<T>::get_data()
{
	return this->data;
}
