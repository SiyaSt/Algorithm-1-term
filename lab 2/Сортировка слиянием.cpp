#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int* arr0, int* arr1, int n0, int n1, int* ans)
{
	int i = 0;
	int j = 0;
	while (i < n0 && j < n1)
	{
		if (arr0[i] < arr1[j])
		{
			ans[i + j] = arr0[i];
			i++;
		}
		else 
		{
			ans[i + j] = arr1[j];
			j++;
		}
	}
	while (i <n0)
	{
		ans[i+j] = arr0[i];
		i++;
	}
	while (j <n1)
	{
		ans[j+i] = arr1[j];
		j++;
	}
}
void merge_sort(int* arr, int num)
{
	if (num <= 1) return;
	int* arr0 = arr;
	int* arr1 = arr + num / 2;
	int n0, n1;
	n0 = num / 2;
	n1 = num - n0;
	merge_sort(arr0, n0);
	merge_sort(arr1, n1);
	int* ans = malloc(num * sizeof(int));
	merge(arr0, arr1, n0, n1, ans);
	for (int i = 0; i < num; i++)
	{
		arr[i] = ans[i];
	}
	free(ans);
}

int main() 
{
	int num,elem;
	scanf("%d", &num);
	int* arr = malloc(num * sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &elem);
		arr[i] = elem;
	}
	merge_sort(arr, num);
	for (int i = 0; i < num;i++) 
	{
		printf("%d ", arr[i]);
	}
}
