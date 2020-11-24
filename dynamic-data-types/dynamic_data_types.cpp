#include <iostream>
#include <chrono>
#include "List.h"

using std::cout;
using std::endl;
using namespace std::chrono;

int main()
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
	return 0;
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
