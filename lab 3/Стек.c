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
	temp=elem->value;
	free(elem);
	return temp;
}
int main()
{
	int N, number;
	char command;
	scanf("%d", &N);
	Node *temp = creat_head();
	for (int i = 0; i < N; i++)
	{
		scanf(" %c",&command);
		if (command == '+')
		{
			scanf("%d", &number);
			add_befor(temp, creat_node(number));
		}
		else if (command == '-')
		{
			 printf("%d\n", delet(temp->prev));
		}
	}
	return 0;
}
