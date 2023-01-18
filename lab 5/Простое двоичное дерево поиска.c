#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* left;
	struct Node* right;

};

struct Node* creation(int value)
{
	struct Node* temp = malloc(sizeof(struct Node));
	temp->value = value;
	temp->right = temp->left = NULL;
	return temp;
}

struct Node* insert(struct Node* node, int value)
{
	if (node == NULL)
	{
		struct Node* temp = creation(value);
		return temp;
	}
	else if (value < node->value)
	{
		node->left = insert(node->left, value);
	}
	else if (value > node->value)
	{
		node->right = insert(node->right, value);
	}
	return node;
}

int exist(struct Node* node, int value)
{
	if (node == NULL)
		return 0;
	if (value == node->value)
		return 1;
	if (value > node->value)
	{
		return exist(node->right, value);
	}
	else
		return exist(node->left, value);
}


struct Node *next(struct Node* node, int value)
{
	struct Node* current = node;
	struct Node* successsor = NULL;
	while (current != NULL)
	{
		if (current->value > value)
		{
			successsor = current;
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return successsor;
}

struct Node *prev(struct Node* node, int value)
{
	struct Node* current = node;
	struct Node* successsor = NULL;
	while (current != NULL)
	{
		if (current->value < value)
		{
			successsor = current;
			current = current->right;
		}
		else
		{
			current = current->left;
		}
	}
	return successsor;
}


struct Node* deletNode(struct Node* node, int value)
{
	if (node == NULL)
	{
		return node;
	}
	if (value == node->value)
	{
		struct Node* temp = malloc(sizeof(struct Node));
		if (node->right == NULL)
		{
			temp = node->left;
		}
		else
		{
			struct Node* temp1 = node->right;
			if (temp1->left == NULL)
			{
				temp1->left = node->left;
				temp = temp1;
			}
			else
			{
				struct Node* minimum = temp1->left;
				while (minimum->left != NULL)
				{
					temp1 = minimum;
					minimum = temp1->left;
				}
				temp1->left = minimum->right;
				minimum->left = node->left;
				minimum->right = node->right;
				temp = minimum;
			}
		}
		free(node);
		return temp;
	}
	else if (value < node->value)
	{
		node->left = deletNode(node->left, value);
	}
	else
	{
		node->right = deletNode(node->right, value);
	}
	return node;
}

int main()
{
	char* str[10];
	int number;
	struct Node* node= malloc(sizeof(struct Node));
	struct Node* node1 = malloc(sizeof(struct Node));
	node = NULL;
	while (scanf("%s", str) != -1)
	{
		if ((char)str[0] == 'i')
		{
			scanf("%d", &number);
			node = insert(node, number);
		}
		if ((char)str[0] == 'e')
		{
			scanf("%d", &number);
			if (exist(node, number) == 1)
			{
				printf("true\n");
			}
			else
			{
				printf("false\n");
			}
		}
		if ((char)str[0] == 'n')
		{
			scanf("%d", &number);
			
			if (next(node, number) == NULL)
			{
				printf("none\n");
			}
			else
				printf("%d\n", next(node, number)->value);
		}
		if ((char)str[0] == 'p')
		{
			scanf("%d", &number);
			if (prev(node, number) == NULL)
			{
				printf("none\n");
			}
			else
				printf("%d\n", prev(node, number)->value);
		}
		if ((char)str[0] == 'd')
		{
			scanf("%d", &number);
			node = deletNode(node, number);
		}
	}
}
