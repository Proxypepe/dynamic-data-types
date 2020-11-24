#pragma once

template <class T1, class T2>
class Vertex
{
private:
	T1 connection; 
	T2 wieght;

public:
	Vertex(T1 connection, T2 wieght);

	void set_connection(T1 connection);
	void set_wieght(T2 wieght);

	T1 get_connection();
	T2 get_wieght();
};

template<class T1, class T2>
inline Vertex<T1, T2>::Vertex(T1 connection, T2 wieght)
{
	this->connection = connection;
	this->wieght = wieght;
}
template<class T1, class T2>
inline void Vertex<T1, T2>::set_connection(T1 connection)
{
	this->connection = connection;
}

template<class T1, class T2>
inline void Vertex<T1, T2>::set_wieght(T2 wieght)
{
	this->wieght = wieght;
}

template<class T1, class T2>
inline T1 Vertex<T1, T2>::get_connection()
{
	return this->connection;
}

template<class T1, class T2>
inline T2 Vertex<T1, T2>::get_wieght()
{
	return this->wieght;
}
