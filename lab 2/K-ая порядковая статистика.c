#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void swap(int* a, int* b)
{
	int buf = *a;
	*a = *b;
	*b = buf;
}

int partition(int* arr, int left, int right)
{
	int pivot = arr[(left + right) / 2];
	int i = left, j = right;
	while (i <= j)
	{
		while (arr[i] < pivot)
		i++;
		while (arr[j] > pivot)
			j--;
		if (i >= j)
		{
			break;
		}
		swap(&arr[i++], &arr[j--]);
	}
	return j;
}
int finderK(int* arr, int num, int k)
{
	int left = 0, right = num - 1;
	while (1)
	{
		int mid = partition(arr, left, right);
		if (left==right)
		{
			return arr[mid];
		}
		else if (k <= mid)
		{
			right = mid;
		}
		else 
		{
			left = mid + 1;
		}

	}
}

int main()
{
	int num, k;
	scanf("%d %d", &num, &k);
	if (k > num)
		return;
	int* arr = malloc(num * sizeof(int));
	int A, B, C;
	scanf("%d %d %d %d %d", &A, &B, &C, &arr[0], &arr[1]);
	for (int i = 2; i < num; i++)
	{
		arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
	}
	int ans = finderK(arr, num, k-1);

	printf("%d", ans);
}
