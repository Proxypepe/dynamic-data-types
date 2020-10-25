#include <iostream>
#include "List.h"
#include "Hashmap.h"
#include <string>
#include "Policy.h"
#include "Tree.h"
//
//typedef struct Policy
//{
//	int key;
//	std::string surname;
//
//} Policy_t;
//
//void init(Policy_t& pol, int key, std::string surname)
//{
//	pol.key = key;
//	pol.surname = surname;
//	//return pol;
//}
//
//void print_policy(Policy_t pol)
//{
//	std::cout << "Key: " << pol.key << "Surname: " << pol.surname << "\n";
//}
//int main()
//{
//	Policy policy;
//	Hashmap<Policy> map(5);
//
//	for (int i = 0; i < 4; i++)
//	{
//		int key;
//		std::string company, surname;
//		std::cin >> key >> company >> surname;
//		policy.init(key, company, surname);
//		map.add_element(policy, policy.getNumber());
//	}
//	map.print_map();
//
//
//
//	return 0;
//}




int main()
{
	Tree<char>* tree = nullptr;
	std::string str;
	std::cin >> str;

	tree->build_arithmetic_tree(tree, str);
	tree->bfs(tree);
	tree->print_arithmetic_tree(tree);


	//delete tree;
	return 0;
}

