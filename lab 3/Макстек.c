#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define max(a,b) (((a)>(b)) ? (a):(b))

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
	int number, N;
	scanf("%d", &N);
	Node* temp = creat_head();
	temp->value = INT_MIN;

	for (int i = 0; i < N;i++)
	{
		scanf("%s", str);
		if ((char)str[0] == '+')
		{
			scanf("%d", &number);
			int Local_max = max(number, temp->next->value);
			add_after(temp, creat_node(Local_max));
		}
		else if ((char)str[0] == '-')
		{
			int a =delet(temp->next);
		}
		else 
		{
			printf("%d\n", temp->next->value);
		}
	}
}
