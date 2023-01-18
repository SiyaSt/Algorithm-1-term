#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
	int height;
};

int maximum(int a, int b)
{
	return (a < b) ? b : a;
}

struct Node* creation(int value)
{
	struct Node* temp = malloc(sizeof(struct Node));
	temp->value = value;
	temp->right = temp->left = NULL;
	temp->height = 1;
	return temp;
}

int hight(struct Node* node)
{
	return node ? node->height : 0;
}

int balanc(struct Node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return (node->right != NULL ? node->right->height : 0) -
		(node->left != NULL ? node->left->height : 0);
}

int hightl(struct Node* node)
{
	return node->left == NULL ? 0 : node->left->height;
}

int hightr(struct Node* node)
{
	return node->right == NULL ? 0 : node->right->height;
}

void fix(struct Node* node)
{
	node->height = maximum(hightl(node), hightr(node)) + 1;
}

struct Node* rotate_right(struct Node* node)
{
	struct Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	fix(node);
	fix(temp);
	return temp;
}

struct Node* rotate_left(struct Node* node)
{
	struct Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	fix(node);
	fix(temp);
	return temp;
}

struct Node* balance(struct Node* node)
{
	fix(node);
	if (balanc(node) == 2)
	{
		if (balanc(node->right) < 0)
		{
			node->right = rotate_right(node->right);
		}
		return rotate_left(node);
	}
	if (balanc(node) == -2)
	{
		if (balanc(node->left) > 0)
		{
			node->left = rotate_left(node->left);
		}
		return rotate_right(node);
	}
	return node;
}

struct Node* exist(struct Node* node, int value)
{
	if (node == NULL || value == node->value)
	{
		return node;
	}
	if (value > node->value)
	{
		return exist(node->right, value);
	}
	else
		return exist(node->left, value);
}

struct Node* insert(struct Node* node, int value)
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

struct Node* maximumNode(struct Node* node)
{
	return node->right ? maximumNode(node->right) : node;
}

struct Node* delet(struct Node* node, int value)
{
	if (node == NULL)
	{
		return NULL;
	}
	else if (value > node->value)
	{
		node->right = delet(node->right, value);
	}
	else if (value < node->value)
	{
		node->left = delet(node->left, value);
	}
	else
	{
		if (node->left == NULL && node->right == NULL)
		{
			return NULL;
		}
		if (node->left == NULL)
		{
			node = node->right;
			return balance(node);
		}
		struct Node* temp = maximumNode(node->left);
		node->value = temp->value;
		node->left = delet(node->left, temp->value);

	}
	return balance(node);
}


int main()
{

	int number;
	scanf("%d", &number);

	struct Node* node = malloc(sizeof(struct Node));
	node = NULL;
	for (int i = 0; i < number; i++)
	{
		char* str[10];
		int value;
		scanf("%s %d", str, &value);
		if ((char)str[0] == 'A')
		{
			if (exist(node, value) == NULL)
			{
				node = insert(node, value);
			}
			printf("%d\n", balanc(node));
		}
		if ((char)str[0] == 'D')
		{
			if (exist(node, value) != NULL)
			{
				node = delet(node, value);
			}
			printf("%d\n", balanc(node));
		}
		if ((char)str[0] == 'C')
		{
			printf((exist(node, value) != NULL) ? "Y\n" : "N\n");
		}
	}

}
