#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void build(int arr[], int tree[], int value, int tree_left, int tree_right)
{
	if (tree_left == tree_right)
	{
		tree[value] = arr[tree_left];
	}
	else
	{
		int temp = (tree_left + tree_right) / 2;
		build(arr, tree, value * 2, tree_left, temp);
		build(arr, tree, value * 2 + 1, temp + 1, tree_right);
		tree[value] = tree[value * 2] + tree[value * 2 + 1];
	}
}

int sumator(int tree[], int value, int left, int right, int tree_left, int tree_right)
{
	if (left <= tree_left && tree_right <= right)
	{
		return tree[value];
	}

	if (right < tree_left || tree_right < left)
	{
		return 0;
	}

	int temp = (tree_left + tree_right) / 2;
	return sumator(tree, value * 2, left, right, tree_left, temp) +
		sumator(tree, value * 2 + 1, left, right, temp + 1, tree_right);

}

void update(int arr[], int tree[], int key, int newvalue, int value, int tree_left, int tree_right)
{
	if (key <= tree_left && tree_right <= key)
	{
		arr[key] = newvalue;
		tree[value] = newvalue;
		return;
	}
	if (tree_right < key || key < tree_left)
	{
		return;
	}

	int temp = (tree_left + tree_right) / 2;
	update(arr, tree, key, newvalue, value * 2, tree_left, temp);
	update(arr, tree, key, newvalue, value * 2 + 1, temp + 1, tree_right);
	tree[value] = tree[value * 2] + tree[value * 2 + 1];
}

int main()
{
	int among_of_cats, number;

	scanf("%d %d", &among_of_cats, &number);

	int* arr = calloc(among_of_cats+1, sizeof(int));
	int* tree = calloc(4*among_of_cats, sizeof(int));
	//build(arr, tree, 1, 0, among_of_cats - 1);
	char* str = malloc(sizeof(char));
	int key, value;
	for (int i = 0; i < number; i++)
	{
		scanf("%s %d %d", str, &key, &value);
		if ((char)str[0] == '+')
		{
			int temp = arr[key - 1] + value;
			update(arr, tree, key - 1, temp, 1, 0, among_of_cats - 1);
		}
		if ((char)str[0] == '-')
		{
			int temp = arr[key - 1] - value;
			if (temp <= 0)
			{
				update(arr, tree, key - 1, 0, 1, 0, among_of_cats - 1);
			}
			else
			{
				update(arr, tree, key - 1, temp, 1, 0, among_of_cats - 1);
			}

		}
		if ((char)str[0] == '?')
		{
			int a = sumator(tree, 1, key - 1, value - 1, 0, among_of_cats - 1);
			printf("%d\n", a);
		}
	}
	return 0;
}
