#pragma once
#include <iostream>
#include ""

class Graph
{
private:
	List<int>* graph;
	size_t size;

public:
	Graph(size_t size);
	~Graph();

	void add_edge(int v, int u);

	void print_graph();
};
