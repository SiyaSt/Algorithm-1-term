#include <iostream>

struct Node;
int Recursive_input(Node*, int, int, int&);
void PreOrderOutput(Node*);
void PostOrderOutput(Node*);

struct Node
{
	int value;
	Node* left;
	Node* right;
	Node() :value(0), left(NULL), right(NULL) {}
	~Node()
	{
		delete left; delete right;
	}
};
Node* CreateNode(int value)
{
	Node* new_node = new Node;
	new_node->value = value;
	return new_node;
}

int main()
{
	using namespace std;
	int n, val; Node* root = NULL;
	cin >> n;
	if (n) {
		cin >> val;
		root = CreateNode(val);
	}
	Recursive_input(root, INT_MIN, INT_MAX, n);
	PostOrderOutput(root);
}

int Recursive_input(Node* node, int lbound, int ubound, int& n)
{
	if (n <= 1) {
		return 0;
	}
	int val;
	std::cin >> val;
	if (val < node->value && val > lbound) {
		{
			node->left = CreateNode(val); n--;
		}
		val = Recursive_input(node->left, lbound, node->value, n);
	}
	if (val > node->value && val < ubound) {
		{
			node->right = CreateNode(val); n--;
		}
		val = Recursive_input(node->right, node->value, ubound, n);
	}
	return val;
}
void PreOrderOutput(Node* node)
{
	if (node != NULL) {
		std::cout << node->value << ' ';
		PreOrderOutput(node->left);
		PreOrderOutput(node->right);
	}
}
void PostOrderOutput(Node* node)
{
	if (node != NULL) {
		PostOrderOutput(node->left);
		PostOrderOutput(node->right);
		std::cout << node->value << ' ';
	}
}
