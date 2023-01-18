#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Nodes
{
	char value;
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

Node* creat_node(char value)
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
char delet(Node* elem)
{
	elem->next->prev = elem->prev;
	elem->prev->next = elem->next;
	char temp;
	temp = elem->value;
	free(elem);
	return temp;
}
void cleanList(Node* elem)
{
    while (elem->next != elem)
    {
        delet(elem->next);
    }
}
char left(char brace)
{
    return (brace == '(' || brace == '[');
}
char right(char brace)
{
    return(brace == ')' || brace == ']');
}
char get_pair(char brace)
{
    if (brace == ')')
        return '(';
    else if (brace == ']')
        return '[';
}
void checker()
{
    char brace;
    int f = 1;
    Node *temp=creat_head();
    while (scanf("%c", &brace) != -1)
    {
        if (isspace(brace))
        {
            if (f == 1 && temp->next==temp)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
                
            }
            cleanList(temp);
            f = 1;
            continue;
        }
        if (brace=='(' || brace=='[')
        {
            add_after(temp, creat_node(brace));
        }
        
            if (brace == ')')
            {
                if (temp->next == temp)
                {
                    f = 0;
                }
                else
                {
                    char pair = delet(temp->next);
                    if (pair != '(')
                    {
                        f = 0;
                    }
                }
            }
            if (brace == ']')
            {
                if (temp->next == temp)
                {
                    f = 0;
                }
                else
                {
                    char pair = delet(temp->next);
                    if (pair != '[')
                    {
                        f = 0;
                    }
                }

            }

    }
    if (f == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");

    }

}
int main()
{
    checker();
    return 0;
}
