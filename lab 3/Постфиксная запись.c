#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Nodes
{
	int value;
	struct Nodes* next;
	struct Nodes* prev;

}Node;
Node* creat_head()
{
	Node* temp = malloc(sizeof(Node));
	temp->next = temp;
	temp->prev = temp;
	return temp;
}

Node* creat_node(int value)
{
	Node* temp = malloc(sizeof(Node));
	temp->next = temp;
	temp->prev = temp;
	temp->value = value;
	return temp;
}
void add_after(Node* cur, Node* elem)
{
	elem->prev = cur;
	elem->next = cur->next;
	cur->next->prev = elem;
	cur->next = elem;
}
void add_befor(Node* cur, Node* elem)
{
	elem->next = cur;
	elem->prev = cur->prev;
	cur->prev->next = elem;
	cur->prev = elem;
}
int delet(Node* elem)
{
	elem->next->prev = elem->prev;
	elem->prev->next = elem->next;
	int temp;
	temp = elem->value;
	free(elem);
	return temp;
}
int main()
{
	char* str[11];
	Node* temp = creat_head();
	while (scanf("%s", str) != -1)
	{
		if (str[0] == '+')
		{
			int elem2 = delet(temp->next);
			int elem1 = delet(temp->next);
			add_after(temp, creat_node(elem1 + elem2));

		}
		else if (str[0] == '-')
		{
			int elem2 = delet(temp->next);
			int elem1 = delet(temp->next);
			add_after(temp, creat_node(elem1 - elem2));

		}
		else if (str[0] == '*')
		{
			int elem2 = delet(temp->next);
			int elem1 = delet(temp->next);
			add_after(temp, creat_node(elem1 * elem2));

		}
		else
		{
			int number = atoi(str);
			add_after(temp, creat_node(number));
		}
	}
	printf("%d", temp->next->value);
}
