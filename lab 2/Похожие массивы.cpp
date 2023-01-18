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
	int num1;
	scanf("%d", &num1);
	int* arr1 = malloc(num1 * sizeof(int));
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &arr1[i]);
	}
	int num2;
	scanf("%d", &num2);
	int* arr2 = malloc(num2 * sizeof(int));
	for (int j = 0; j < num2;j++)
	{
		scanf("%d", &arr2[j]);
	}
	quick_sort(arr1, num1);
	quick_sort(arr2, num2);
	int count1=0,count2=0, max,i1=0,j1=0,i2=0,j2=0;
	while (i1 < num1 && j1 < num2)
	{
		if (arr1[i1] == arr2[j1])
		{
			count1++;
			i1++;
		}
		else
			j1++;
	}
	while (i2 < num1 && j2 < num2)
	{
		if (arr2[j2] == arr1[i2])
		{
			count2++;
			j2++;
		}
		else
			i2++;
	}
	if (count1 == num1 && count2==num2)
		printf("YES");
	else
		printf("NO");
}
