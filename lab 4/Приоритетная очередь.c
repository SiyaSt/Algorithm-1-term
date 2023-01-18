#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
struct pair
{
    int number;
    int i;
};
struct pair* init(int number, int i)
{
    struct pair* buf = malloc(sizeof(struct pair));
    buf->number = number;
    buf->i = i;
    return buf;
}
void swap(struct pair** a, struct pair** b)
{
    struct pair* buf = *b;
    *b = *a;
    *a = buf;

    int buf2 = (*b)->i;
    (*b)->i = (*a)->i;
    (*a)->i = buf2;
}
struct dimArray
{
    struct pair** array;
    int maximum;
    int lenght;
};
struct dimArray* build()
{
    struct dimArray* Array = malloc(sizeof(struct dimArray));
    Array->array = malloc(2 * sizeof(struct pair));
    Array->maximum = 2;
    Array->lenght = 0;
    return Array;
}
void add(struct pair* number, struct dimArray* Array)
{
    if (Array->lenght == Array->maximum)
    {
        Array->array = realloc(Array->array, 2 * Array->maximum * sizeof(struct pair));
        Array->maximum = Array->maximum * 2;
    }
    Array->array[Array->lenght] = number;
    Array->lenght = Array->lenght + 1;
}
struct pair* delet(struct dimArray* Array)
{

    return Array->array[--Array->lenght];
}
void up(struct dimArray* Array, int i)
{
    int new_i = (int)((i - 1) / 2);
    while (i > 0)

    {
        if (Array->array[i]->number < Array->array[new_i]->number)
        {
            swap(&Array->array[i], &Array->array[new_i]);
            i = new_i;
            new_i = (int)((new_i - 1) / 2);
        }
        else
            break;
    }
}
void down(struct dimArray* Array, int i)
{
    int new_i = 2 * i + 1;
    while (Array->lenght > new_i)
    {
        if (Array->lenght > new_i + 1)
        {
            if (Array->array[new_i]->number > Array->array[new_i + 1]->number)
            {
                new_i = new_i + 1;
            }
        }
        if (Array->array[i]->number > Array->array[new_i]->number)
        {
            swap(&Array->array[i], &Array->array[new_i]);
            i = new_i;
            new_i = 2 * i + 1;
        }
        else break;
    }
}
void push(struct dimArray* Array, struct pair* number)
{
    add(number, Array);
    up(Array, Array->lenght - 1);
}
struct pair* exmin(struct dimArray* Array)
{
    if (Array->lenght == 0)
    {
        return NULL;
    }
    else
    {
        swap(&Array->array[0], &Array->array[Array->lenght - 1]);
        struct pair* a = delet(Array);
        down(Array, 0);
        return a;
    }
}
int main()
{
    char* str[10];
    int x, y;
    struct dimArray* Arrays = build();
    struct dimArray* Arrayheap = build();
    struct dimArray* arr = build();
    while (scanf("%s", str) != -1)
    {
        if ((char)str[0] == 'p')
        {
            scanf("%d", &x);
            struct pair* newpar = init(x, Arrayheap->lenght);
            push(Arrayheap, newpar);
            add(newpar, Arrays);

        }
        if ((char)str[0] == 'e')
        {
            add(init(-1, Arrays->lenght), Arrays);
            struct pair* res = exmin(Arrayheap);
             if (res == NULL)
            {
                printf("*\n");
            }
            else
                printf("%d\n", res->number);
        }
        if ((char)str[0] == 'd')
        {
            scanf("%d %d", &x, &y);
            add(init(-1, Arrays->lenght), Arrays);
            int decrease = Arrays->array[x - 1]->i;
            Arrayheap->array[decrease]->number = y;
            up(Arrayheap, decrease);
        }
    }
  
}
