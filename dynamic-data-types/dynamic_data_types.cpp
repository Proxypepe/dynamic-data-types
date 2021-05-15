#include <iostream>
#include <chrono>
#include "List.h"
#include "Avl.h"
#include "Array.h"


using std::cout;
using std::endl;
using namespace std::chrono;

void alv_test();
void list_test();
template<class Arg>
void eprint(Arg arg)
{
	cout << arg;

}

template<class... Args>
void argss(Args&& ... args)
{

}


int main()
{
	//Array<int> a;
	//Array<int> b(a);
	Array<int> a { 1, 2, 3 };
	//a.push_back(10);
	//a.push_back(20);
	//a.push_back(30);
	//a.push_back(40);

	//b.push_back(19);
	for (size_t i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	for (auto it = a.begin(); it != a.end(); it++)
		cout << *it << "  ";

	//for (size_t i = 0; i < b.size(); i++)
	//	cout << b[i] << " ";
	//cout << endl;
	//for (size_t i = 0; i < a.size(); i++)
	//	cout << a[i] << " ";

	//cout << endl << b.at(0);

	argss(1, 2, 3);


	return 0;
}


void alv_test()
{
	Avl<int>* root = nullptr;
	root->insert(root, 10);
	root->insert(root, 20);
	root->insert(root, 5);
	root->insert(root, 30);
	root->insert(root, 2);
	root->insert(root, 40);

	root->printInOder();
}

void list_test()
{
	List<int> list;
	list.push_back(3);
	list.push_back(2);
	list.push_back(4);
	list.push_back(1);
	list.push_back(1);
	list.push_back(4);
	list.sort();
	//list.unique();
	list.push_back(4);

	for (auto& i : list)
		cout << i << "  ";

}


//cout << "list 1: " << endl;
//for (auto& i : list)
//cout << i << "  ";
//cout << "\nlist 2: " << endl;
//for (auto& i : l)
//cout << i << "  ";

//template<class T>
//void out(T t) { cout << t << endl; }
//
//template<class H, class... T>
//void out(H h, T... t) { cout << h << "  "; out(t...); }
//
//template<class... Args>
//void plus1(size_t pos, Args... args) { cout << pos << "  "; out(++args...); }
//
//
//void foo(bool(*bar)(int n))
//{
//	int d = 0;
//	if (bar(d))
//		cout << "yes";
//	else
//		cout << "no";
//}
