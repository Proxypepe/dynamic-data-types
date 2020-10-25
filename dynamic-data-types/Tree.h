#pragma once
#include <iostream>
#include <string>
#include <queue>

template <class T>
class Tree
{
private:
	T field;
	Tree<T>* left = nullptr;
	Tree<T>* right = nullptr;

	Tree<T>* make_node(T data);
	int arithmetic(Tree<T>* v);
	void del(Tree<T>* v);

public:
	void print_tree_inorder(Tree<T>* v);
	void print_tree_preorder(Tree<T>* v);
	void print_tree_postorder(Tree<T>* v);
	void print_arithmetic_tree(Tree<T>* v);
	void bfs(Tree<T>* v);
	void average(Tree<T>* v);
	void delete_tree(Tree<T>*& v);

	int count(Tree<T>* v, int n = 0);
	int is_mult(Tree<T>* v);
	int is_arithmetic(Tree<T>* v);
	int level_counter_left(Tree<T>* v);
	int level_counter_right(Tree<T>* v);
	int level_tree(Tree<T>* v);
	
	T sum(Tree<T>* v, T N = T());
	T max();
	T min();

	Tree<T>* build_arithmetic_tree(Tree<T>*& v, std::string str, int k = -1);
	Tree<T>* add_node(Tree<T>*& v, T data);
	Tree<T>* build_balanced_tree(Tree<T>*& v, int k);
};

template<class T>
inline Tree<T>* Tree<T>::make_node(T data)
{
	Tree<T>* v = new Tree<T>;
	v->field = data;
	v->left = nullptr;
	v->right = nullptr;
	return v;
}

template<class T>
inline int Tree<T>::arithmetic(Tree<T>* v)
{
	static int n = 0;
	if (v == nullptr)
	{
		return 0;
	}
	else if (v->right != nullptr and v->left != nullptr)
	{
		if (v->field == '+' or v->field == '-' or v->field == '*' or v->field == '/')
		{
			n++;
		}
	}
	else if (v->right == nullptr and v->left == nullptr)
	{
		if (v->field == '0' or v->field == '1' or v->field == '2' or v->field == '3' or v->field == '4' or v->field == '5' or v->field == '6' or v->field == '7' or v->field == '6' or v->field == '7')
		{
			n++;
		}
	}
	arithmetic(v->left);
	arithmetic(v->right);
	return n;
}

template<class T>
inline void Tree<T>::del(Tree<T>* v)
{
	if (v != nullptr)
	{
		del(v->left);
		del(v->right);
		delete v;
	}
}

template<class T>
void Tree<T>::print_tree_inorder(Tree<T>* v)
{
	static int n = 0;
	if (v == nullptr)
	{
		return;
	}
	n++;
	print_tree_inorder(v->left);
	std::cout << "Level " << n << " field: " << v->field << "\n";
	print_tree_inorder(v->right);
	n--;
}

template<class T>
inline void Tree<T>::print_tree_preorder(Tree<T>* v)
{
	static int n = 0;
	if (v == nullptr)
	{
		return;
	}
	n++;
	std::cout << "Level " << n << " field: " << v->field << "\n";
	print_tree_preorder(v->left);
	print_tree_preorder(v->right);
	n--;
}

template<class T>
inline void Tree<T>::print_tree_postorder(Tree<T>* v)
{
	static int n = 0;
	if (v == nullptr)
	{
		return;
	}
	n++;
	print_tree_postorder(v->left);
	print_tree_postorder(v->right);
	std::cout << "Level " << n << " field: " << v->field << "\n";
	n--;
}

template<class T>
inline void Tree<T>::print_arithmetic_tree(Tree<T>* v)
{
	if (v == nullptr)
	{
		return;
	}
	print_arithmetic_tree(v->right);
	std::cout << v->field << " ";
	print_arithmetic_tree(v->left);

}

template<class T>
inline void Tree<T>::bfs(Tree<T>* v)
{
	int level = 0;
	std::queue<Tree<T>*> tmp_queue;
	Tree<T>* node;

	if (v == nullptr)
	{
		return;
	}
	else
	{
		tmp_queue.push(v);
		while (!tmp_queue.empty())
		{
			node = tmp_queue.front();
			tmp_queue.pop();

			std::cout << "Level = " << level++ << " Field = " << node->field << std::endl;

			if (node->left)
			{
				tmp_queue.push(node->left);
			}
			if (node->right)
			{
				tmp_queue.push(node->right);
			}
		}
	}
}

template<class T>
inline void Tree<T>::average(Tree<T>* v)
{
	T sum_left = sum(v->left);
	T sum_right = sum(v->right);
	int count_left = v->count(v->left);
	int count_right = v->count(v->right);
	std::cout << "Average left: " << sum_left /  count_left;
	std::cout << "\n";
	std::cout << "Average right: " << sum_right / count_right;
}

template<class T>
inline void Tree<T>::delete_tree(Tree<T>*& v)
{
	v->del(v);
	v = nullptr;
}

template<class T>
inline int Tree<T>::count(Tree<T>* v, int n)
{
	if (!v)
		return 0;
	n++;
	return n + count(v->left) + count(v->right);
}

template<class T>
inline int Tree<T>::is_mult(Tree<T>* v)
{
	static int n = 0;
	if (!v)
		return 0;
	else if (v->field == '*' and n != 1)
	{
		n++;
	}
	is_mult(v->right);
	is_mult(v->left);
	return n;
}

template<class T>
inline int Tree<T>::is_arithmetic(Tree<T>* v)
{
	int left = arithmetic(v), right = count(v);
	if (left == right)
	{
		return 1;
	}
	return 0;
}

template<class T>
inline int Tree<T>::level_counter_left(Tree<T>* v)
{
	static int n = 0;
	if (v == nullptr)
	{
		return 0;
	}
	n++;
	level_counter_left(v->left);
	return n;
}

template<class T>
inline int Tree<T>::level_counter_right(Tree<T>* v)
{
	static int n = 0;
	if (v == nullptr)
	{
		return 0;
	}
	n++;
	level_counter_right(v->right);
	return n;
}

template<class T>
inline int Tree<T>::level_tree(Tree<T>* v)
{
	int left = level_counter_left(v);
	int right = level_counter_right(v);
	if (left > right)
	{
		return left;
	}
	return right;
}

template<class T>
inline T Tree<T>::sum(Tree<T>* v, T N)
{
	if (v == nullptr)
	{
		return T();
	}
	N += v->field;
	return N + sum(v->left) + sum(v->right);
}

template<class T>
inline T Tree<T>::max()
{
	std::queue<Tree<T>*> _tmp_queue;
	Tree<T>* _node;
	if (this == nullptr)
	{
		return T();
	}
	else
	{
		T _max = this->field;
		_tmp_queue.push(this);
		while (!_tmp_queue.empty())
		{
			_node = _tmp_queue.front();
			_tmp_queue.pop();

			if (_max < _node->field)
				_max = _node->field;

			if (_node->left)
			{
				_tmp_queue.push(_node->left);
			}
			if (_node->right)
			{
				_tmp_queue.push(_node->right);
			}
		}
		return _max;
	}
}

template<class T>
inline T Tree<T>::min()
{
	std::queue<Tree<T>*> _tmp_queue;
	Tree<T>* _node;
	if (this == nullptr)
	{
		return T();
	}
	else
	{
		T _min = this->field;
		_tmp_queue.push(this);
		while (!_tmp_queue.empty())
		{
			_node = _tmp_queue.front();
			_tmp_queue.pop();

			if (_min > _node->field)
				_min = _node->field;

			if (_node->left)
			{
				_tmp_queue.push(_node->left);
			}
			if (_node->right)
			{
				_tmp_queue.push(_node->right);
			}
		}
		return _min;
	}
}

template<class T>
Tree<T>* Tree<T>::build_arithmetic_tree(Tree<T>*& v, std::string str, int k)
{
	size_t N = str.length();
	if (N == 1)
	{
		v = make_node(str[0]);
		return v;
	}
	else
	{
		for (N; N >= 0; N--)
		{
			if (str[N] == '+' or str[N] == '-')
			{
				k = N;
				v = make_node(str[k]);
				v->left = build_arithmetic_tree(v->left, str.substr(k + 1), k);
				v->right = build_arithmetic_tree(v->right, str.substr(0, k), k);
				return v;
			}
		}
		int N = str.length();
		for (N; N >= 0; N--)
		{
			if (str[N] == '*' or str[N] == '/')
			{
				k = N;
				v = make_node(str[k]);
				v->left = build_arithmetic_tree(v->left, str.substr(k + 1), k);
				v->right = build_arithmetic_tree(v->right, str.substr(0, k), k);
				return v;
			}
		}
	}
}

template<class T>
inline Tree<T>* Tree<T>::add_node(Tree<T>*& v, T data)
{
	if (v == nullptr)
	{
		v = new Tree<T>;
		v->field = data;
		v->left = nullptr;
		v->right = nullptr;

	}
	else if (v->field > data)
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
inline Tree<T>* Tree<T>::build_balanced_tree(Tree<T>*& v, int k)
{
	T i = rand() % 100 + 10;
	int n1 = k / 2;
	int n2 = k - n1 - 1;
	if (v == nullptr and k > 0)
	{
		v = make_node(i);
		v->left = build_balanced_tree(v->left, n1);
		v->right = build_balanced_tree(v->right, n2);
	}
	return v;
}
