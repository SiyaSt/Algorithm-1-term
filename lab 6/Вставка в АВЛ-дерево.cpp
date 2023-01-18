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

Node* add(Node** tree, int** array, int index)
{
	Node* node = creation(array[index][0]);
	if (array[index][2] != 0)
	{
		node->right = add(tree, array, array[index][2]);
	}
	if (array[index][1] != 0)
	{
		node->left = add(tree, array, array[index][1]);
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
	node->height = ((hight_left > hight_right) ? hight_left : hight_right) + 1;
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
		if (node->right->balanc < 0)
		{
			node->right = rotate_right(node->right);
		}
		return rotate_left(node);
	}
	if (node->balanc == -2)
	{
		if (node->left->balanc > 0)
		{
			node->left = rotate_left(node->left);
		}
		return rotate_right(node);
	}
	return node;
}

//int hight(Node* node)
//{
//	return node ? node->height : 0;
//}
//
//int balanc(Node* node)
//{
//	if (node == NULL)
//	{
//		return 0;
//	}
//	return (node->right != NULL ? node->right->height : 0) -
//		(node->left != NULL ? node->left->height : 0);
//}
//
//int hightl(Node* node)
//{
//	return node->left == NULL ? 0 : node->left->height;
//}
//
//int hightr(Node* node)
//{
//	return node->right == NULL ? 0 : node->right->height;
//}
//
//void fix(Node* node)
//{
//	node->height = maximum(hightl(node), hightr(node)) + 1;
//}
//
//Node* rotate_right(Node* node)
//{
//	Node* temp = node->left;
//	node->left = temp->right;
//	temp->right = node;
//	fix(node);
//	fix(temp);
//	return temp;
//}
//
//Node* rotate_left(Node* node)
//{
//	Node* temp = node->right;
//	node->right = temp->left;
//	temp->left = node;
//	fix(node);
//	fix(temp);
//	return temp;
//}
//
//Node* balance(Node* node)
//{
//	fix(node);
//	if (balanc(node) == 2)
//	{
//		if (balanc(node->right) < 0)
//		{
//			node->right = rotate_right(node->right);
//		}
//		return rotate_left(node);
//	}
//	if (balanc(node) == -2)
//	{
//		if (balanc(node->left) > 0)
//		{
//			node->left = rotate_left(node->left);
//		}
//		return rotate_right(node);
//	}
//	return node;
//}

Node* insert(Node* node, int value)
{
	if (node == NULL) {
		return creation(value);
	}
	else if (value < node->value)
	{
		node->left = insert(node->left, value);
	}
	else
	{
		node->right = insert(node->right, value);
	}

	return balance(node);
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
				left = i++;
			}
			if (node->right)
			{
				right = i++;
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
	int insert_value;
	cin >> number;
	if (number == 0)
	{
		cout << 1 << "\n";
		cin >> insert_value;
		cout << insert_value <<" " << 0 << " " << 0;
		return 0;
	}
	int** array = new int* [number + 2];
	for (int i = 0; i < number + 2; i++)
	{
		array[i] = new int[3];
	}

	for (int i = 1; i < number+1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> array[i][j];
		}
	}
	
	cin >> insert_value;
	Node** tree = new Node * [number + 1];
	Node* node = add(tree, array, 1);
	node = insert(node, insert_value);
	int h = hight(node);

	cout << number+1 << "\n";

	for (int i = 0; i < h; i++)
	{
		printTree(node, i);
	}
	return 0;
}
