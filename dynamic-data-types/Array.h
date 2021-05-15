#pragma once


template<class T>
class Array
{
	class Iterator;
	using value_type	  = T;
	using size_type	 	  = size_t;
	using reference       = value_type&;
	using const_reference = const value_type&;
	using const_iterator  = const Iterator;

private:
	value_type* arr		  = nullptr;
	size_type _size		  = 0;
	size_type _capacity   = 0; // ?

public:
	Array() : _size(0), _capacity(0) {}
	explicit Array(size_type);
	Array(size_type, const value_type& = value_type());
	explicit Array(const Array&);
	explicit Array(Array&&);
	explicit Array(std::initializer_list<T> init);

	~Array() { delete[] arr; }

	bool isEmpty();

	void clear();
	void push_back(const_reference);

	void resize(size_type);

	size_type size() const;
	size_type capacity() const;

	const_reference at(size_type) const;
	const_reference front() const;
	const_reference back() const;

	reference		operator[](const size_type&);
	const_reference operator[](const size_type&) const;

	Iterator begin() { return arr; };
	Iterator end() { return arr + _size; };
	

private:
	class Iterator
	{
	private:
		value_type* current;

	public:
		Iterator(value_type* elem) : current(elem) {};

		reference operator+ (size_type n) { return *(current + n); }
		reference operator- (size_type n) { return *(current - n); }

		reference operator++ (int) { return *current++;  }
		reference operator-- (int) { return *current--; }
		reference operator++ () { return *++current; }
		reference operator-- () { return *--current; }

		bool operator!=(const_iterator& it) { return current != it.current; }
		bool operator==(const_iterator& it) { return current == it.current; }

		reference operator* () { return *current; }
	};
};

template<class T>
inline Array<T>::Array(size_type size) : _size(size)
{
	if (size != 0) {
		arr = new value_type[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = value_type();
		}
	}
}

template<class T>
inline Array<T>::Array(size_type size, const value_type& value) : _size(size)
{
	if (size != 0) {
		arr = new value_type[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = value;
		}
	}
}

template<class T>
inline Array<T>::Array(const Array& other)
{
	_size = other.size();
	arr = new value_type[_size];
	for (size_type i = 0; i < _size; i++)
		arr[i] = other[i];
}

template<class T>
inline Array<T>::Array(Array&&)
{
	// TODO std::move()
}

template<class T>
inline Array<T>::Array(std::initializer_list<T> init)
{
	_size = init.size();
	_capacity = _size;
	arr = new value_type[_size];
	size_type i = 0;
	for (auto it = init.begin(); it != init.end(); ++it) {
		arr[i] = *it;
		i++;
	}
}

template<class T>
inline bool Array<T>::isEmpty()
{
	if (_size != 0)
		return true;
	return false;
}

template<class T>
inline void Array<T>::clear()
{
	delete[] arr;
	_size = 0;
}

template<class T>
inline void Array<T>::push_back(const_reference value)
{
	if (arr == nullptr)
	{
		arr = new value_type[1];
		arr[0] = value;
		_size = 1;
	}
	else
	{
		value_type* new_array = new value_type[_size + 1];
		for (size_t i = 0; i < _size; i++)
			new_array[i] = arr[i];
		new_array[_size] = value;
		delete[] arr;
		arr = new_array;
		_size++;
	}
}

template<class T>
inline void Array<T>::resize(size_type size)
{
	value_type* new_array = new value_type[size];
	for (size_type i = 0; i < size; i++)
		new_array[i] = arr[i];
	delete[] arr;
	arr = new_array;
}

template<class T>
inline size_t Array<T>::size() const
{
	return _size;
}

template<class T>
inline size_t Array<T>::capacity() const
{
	return _capacity;
}

template<class T>
inline const T& Array<T>::at(size_type pos) const
{
	if (_size != 0 and pos < _size)
		return arr[pos];
}

template<class T>
inline const T& Array<T>::front() const
{
	if (_size != 0)
		return arr[0];
}

template<class T>
inline const T& Array<T>::back() const
{
	if (_size != 0)
		return arr[_size - 1];
}

template<class T>
inline T& Array<T>::operator[](const size_type& index)
{
	return arr[index];
}

template<class T>
inline const T& Array<T>::operator[](const size_type& index) const
{
	return arr[index];
}
