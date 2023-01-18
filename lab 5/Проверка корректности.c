#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>


bool tree_cond(int** tree, int n_root, int a, int b)
{
	if (n_root == 0)
	{
		return true;
	}
	if (tree[n_root - 1][0] <= a || b <= tree[n_root - 1][0])
	{
		return false;
	}
	return (tree_cond(tree, tree[n_root - 1][1], a, tree[n_root - 1][0]) &&
		tree_cond(tree, tree[n_root - 1][2], tree[n_root - 1][0], b));
}
int main()
{
	int** array, n;
	int a = INT_MIN;
	int b = INT_MAX;
	scanf("%d", &n);

	array = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		array[i] = malloc (3*sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}

	printf((tree_cond(array, 1 && n, a, b)) ? "YES" : "NO");
}
