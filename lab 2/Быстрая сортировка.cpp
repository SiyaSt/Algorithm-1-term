#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int partition(int* arr, int number, int pivot) {
	char flag = 0;
	int i = 0, j = number - 1;
	int* new_arr = malloc(number * sizeof(int));
	for (int a = 0; a < number; a++)
	{
		if (arr[a] < pivot)
		{
			new_arr[i] = arr[a];
			i++;
		}
		else if (arr[a] > pivot)
		{
			new_arr[j] = arr[a];
			j--;
		}
		else
		{
			if (flag) {
				new_arr[i] = arr[a];
				i++;
				flag = 0;
			}
			else {
				new_arr[j] = arr[a];
				j--;
				flag = 1;
			}
		}
	}
	for (int a = 0; a < number; a++)
	{
		arr[a] = new_arr[a];
	}
	free(new_arr);
	return j + 1;
}
void quick_sort(int* arr, int number)
{
	if (number <= 1)
	{
		return;
	}
	int random_elem = (int)rand() % number;
	int result = partition(arr, number, arr[random_elem]);
	quick_sort(arr, result);
	quick_sort(arr + result, number - result);
	return;
}

int main()
{
	int num, elements;
	scanf("%d", &num);
	int* arr = malloc(num * sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &elements);
		arr[i] = elements;
	}
	quick_sort(arr, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d", arr[i]); printf(" ");
	}
}
