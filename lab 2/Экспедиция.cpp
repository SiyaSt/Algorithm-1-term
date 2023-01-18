#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int partition(int* arr, int number, int pivot) {
	char flag = 0;
	int i=0, j=number-1;
	int* new_arr = malloc(number * sizeof(int));
	for (int a = 0; a < number; a++) 
	{
		if (arr[a] < pivot)
		{
			new_arr[i] = arr[a];
			i++;
		}
		else if(arr[a]>pivot)
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


int main() {

	int temporary;
	int m, n;
	scanf("%d %d", &n, &m);
	int mn = m * n;
	int* arr_plot =malloc(mn*sizeof(int));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			scanf("%d", &temporary);
			arr_plot[i*m+j] = temporary;
		}
	}
	int num, peop;
	scanf("%d", &num);
	int* arr_people = malloc(num * sizeof(int));
	
	for (int k = 0; k < num; k++)
	{
		scanf("%d", &peop);
		arr_people[k] = peop;
	}
	quick_sort(arr_plot, mn);
	quick_sort(arr_people, num);
	
	int i = mn - 1, j = num - 1;
	int count=0;
	while (i >= 0 && j >= 0)
	{
		if (arr_people[j] <= arr_plot[i])
		{
			i--;
			j--;
			count++;
		}
		else
		{
			j--;
		}
	}
	printf("%d", count);

	return 0;
}
