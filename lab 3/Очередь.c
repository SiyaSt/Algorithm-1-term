#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Node 
{
    int data; 
    Node* next; 
};
struct Queue 
{
    Node* first; 
    Node* last; 
};
void Creation(Queue* Q) 
{
    Q->first = new Node;
    Q->first->next = NULL;
    Q->last = Q->first;
}
bool Full(Queue* Q) 
{
    if (Q->first == Q->last) return true;
    else return false;
}

void Add(Queue* Q, int value) 
{
    Q->last->next = new Node;
    Q->last = Q->last->next;
    Q->last->data = value; 
    Q->last->next = NULL; 
}
int Delete(Queue* Q) 
{
    int val = Q->first->next->data;
    Q->first = Q->first->next; 
    return val;
}

int main()
{
    char command;
    int a = 0, number = 0, j=0;
    Queue Q;
    Creation(&Q);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a;
    int result;
    for (int i = 0; i < a; ++i) 
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> command;
        if (command == '+')
        {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cin >> number;
            Add(&Q, number);
            
        }
        else if (command == '-')
        {
            result = Delete(&Q);
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout << result << '\n';
           
        }
       
    }
}
