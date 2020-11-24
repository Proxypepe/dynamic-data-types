#pragma once
#include <iostream>
#include "Forword_list.h"
#include "Vertex.h"

using std::cout;
using std::cin;
using std::endl;

template <class c, class w>
class Graph
{
private:
	Forword_list<Vertex<c, w>>* graph;
	size_t size;
	int inf = 1001;
	w** d;

public:
	Graph(size_t size);
	~Graph();

	void add_edge(c v, c u, int wieght = 0);
	void add_edge_oriented(c v, c u, int wieght = 0);
	void print_graph();
	void Floyd();
	void ways(size_t v, size_t u);
	void enter_graph();

};

template<class c, class w>
inline Graph<c, w>::Graph(size_t size)
{
	this->graph = new Forword_list<Vertex<c, w>>[size];
	this->size = size;
	this->d = new w * [this->size];
	for (size_t i = 0; i < this->size; i++)
		this->d[i] = new w[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = 0; j < this->size; j++)
		{
			if (i != j)
				this->d[i][j] = inf;
			else
				this->d[i][j] = w();
		}
	}
}

template<class c, class w>
inline Graph<c, w>::~Graph()
{
	delete[] graph;
	for (size_t i = 0; i < this->size; i++) {
		delete[] d[i];
	}
	delete[] d;
}

template<class c, class w>
inline void Graph<c, w>::add_edge(c v, c u, int wieght)
{

	v--; u--;
	this->graph[v].push_back(Vertex<c, w>(u, wieght));
	this->graph[u].push_back(Vertex<c, w>(v, wieght));
}

template<class c, class w>
inline void Graph<c, w>::add_edge_oriented(c v, c u, int wieght)
{
	v--; u--;
	this->graph[v].push_back(Vertex<c, w>(u, wieght));
}

template<class c, class w>
inline void Graph<c, w>::print_graph()
{
	for (size_t i = 0; i < this->size; i++)
	{
		cout << "Vertex #" << i + 1 << endl;
		this->graph[i].print_list_();
		cout << endl;
	}
}

template<class c, class w>
inline void Graph<c, w>::Floyd()
{
	for (size_t i = 0; i < this->size; i++)
	{
		for (auto& vectex : graph[i])
		{
			c _con = vectex.get_connection();
			w _wieght = vectex.get_wieght();
			cout << "\ncon: " << _con + 1 << "wieght: " << _wieght;
			d[i][_con] = _wieght;
		}
	}
	cout << endl << "Before " << endl;
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = 0; j < this->size; j++)
		{
			cout << d[i][j] << "  ";
		}
		cout << "\n";
	}

	for (size_t k = 0; k < this->size; ++k)
		for (size_t i = 0; i < this->size; ++i)
			for (size_t j = 0; j < this->size; ++j)
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);

	cout << endl << "End :" << endl;
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = 0; j < this->size; j++)
		{
			cout << d[i][j] << "  ";
		}
		cout << "\n";
	}

}

template<class c, class w>
inline void Graph<c, w>::ways(size_t v, size_t u)
{
	v--; u--;
	if (this->d[v][u] != inf)
		cout << " Way: " << this->d[v][u] << " ";
	else
		cout << " No way";
}

template<class c, class w>
inline void Graph<c, w>::enter_graph()
{
	size_t num, v, u;
	int wieght;
	char choice;
	cout << "Enter number of vertex: ";
	cin >> num;
	for (size_t i = 0; i < num; i++)
	{
		cout << "From ";
		cin >> v;
		cout << "to ";
		cin >> u;
		cout << "Wieght ";
		cin >> wieght;
		cout << "Oriented?: [Y/N]";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
			this->add_edge_oriented(v, u, wieght);
		else if (choice == 'N' || choice == 'n')
			this->add_edge(v, u, wieght);
	}
}
