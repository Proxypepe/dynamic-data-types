#pragma once
#include "List.h"
#include "ListIterater.h"


template <class T>
class Tnode
{
public:

	friend class List;
	friend class ListIterator;


	T field = T();
	Tnode<T>* next = nullptr;
};

