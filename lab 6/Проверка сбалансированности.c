#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

int maximum(int a, int b)
{
	return (a < b) ? b : a;
}

int h(int** tree, int n_root, int* answer)
{
	int left = 0, right = 0;
	if (tree[n_root - 1][1] != 0)
	{
		left = h(tree, tree[n_root - 1][1], answer) + 1;

	}
	if (tree[n_root - 1][2] != 0)
	{
		right = h(tree, tree[n_root - 1][2], answer) + 1;
	}
	
	answer[n_root-1] = right - left;
	return maximum(left, right);

}


int main()
{

	int number, left, right;
	scanf("%d", &number);
	int* answer = malloc(number*sizeof(int));
	int** array = malloc(number*sizeof(int*));
	for (int i = 0; i < number; i++)
	{
		array[i] = malloc(3*sizeof(int));
	}

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	
	h(array, 1, answer);
	
	for (int i = 0; i < number; i++)
	{
		printf("%d\n", answer[i]);

	}
	return 0;
}
