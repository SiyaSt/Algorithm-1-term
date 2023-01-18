#include <iostream>

struct Node
{
	int value;
	Node* left;
	Node* right;
	int height, balanc;
	Node() :value(1), left(NULL), right(NULL), height(1), balanc(0) {}
	~Node()
	{
		delete left; delete right;
	}
};


Node* creation(int value)
{
	Node* temp = new Node;
	temp->value = value;
	temp->right = temp->left = NULL;
	return temp;
}

Node* insert(Node** tree, int** array, int index)
{
	Node* node = creation(array[index][0]);
	if (array[index][2] != 0)
	{
		node->right = insert(tree, array, array[index][2]);
	}
	if (array[index][1] != 0)
	{
		node->left = insert(tree, array, array[index][1]);
	}

	tree[index] = node;
	return node;
}

 int maximum(int a, int b)
{
	return (a < b) ? b : a;
}

int hight(Node* node)
{
	int hight_left, hight_right;
	hight_left = hight_right = 0;

	if (node->right)
	{
		hight_right = hight(node->right);
	}
	if (node->left)
	{
		hight_left = hight(node->left);
	}
	node->height = ((hight_left> hight_right)? hight_left : hight_right) + 1;
	int h = node->height;
	node->balanc = hight_right - hight_left;
	return h;
}



Node* rotate_left(Node* node)
{
	Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}

Node* rotate_right(Node* node)
{
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

Node* balance(Node* node)
{
	hight(node);
	if (node->balanc == 2)
	{
		if (node->right->balanc< 0)
		{
			node->right = rotate_right(node->right);
		}
		return rotate_left(node);
	}
	return node;
}

int i = 2;

void printTree(Node* node, int index)
{
	int right, left;
	right = left = 0;

	if (node == NULL)
	{
		return;
	}
	else
	{
		printTree(node->left, index - 1);
		if (index == 0)
		{
			if (node->left)
			{
				left = i ++;
			}
			if (node->right)
			{
				right = i ++;
			}
			
			std::cout << node->value << " " << left << " " << right << "\n";
		}
	}
	printTree(node->right, index - 1);
}

int main()
{
	using namespace std;

	int number;
	cin >> number;

	int** array = new int* [number + 1];
	for (int i = 0; i < number+1; i++)
	{
		array[i] = new int [3];
	}

	for (int i = 1; i < number+1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin  >> array[i][j];
		}
	}

	Node** tree = new Node * [number + 1];
	Node* node = insert(tree, array, 1);
	node = balance(node);
	int h = hight(node);

	cout << number << "\n";

	for (int i = 0; i < h; i++)
	{
		printTree(node, i);
	}
	return 0;
}
