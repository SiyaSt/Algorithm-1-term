#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool check(long long mid, int arr[], int num, int k)
{

	int counter = 0;

	long long sum = 0;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] > mid)
			return false;
		sum += arr[i];
		if (sum > mid)
		{
			counter++;
			sum = arr[i];
		}
	}
	counter++;
	if (counter <= k)
		return true;
	return false;
}
long long search(int *arr, int num, int k)
{
	long long start = 1;
	for (int i = 0; i < num; ++i) 
	{
		if (arr[i] > start)
		{ 
			start = arr[i];
		}
	}
	long long end = 0;
	for (int i = 0; i < num; i++)
	{
		end += arr[i];  
	}
	long long answer = 0;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		if (check(mid, arr, num, k))
		{
			answer = mid;
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return answer;
}
void split(int *ans, int *arr, int num, int k, long long minmax)
{
	int i = 0;
	while (i < k - 1)
	{
		int j = 0;
		while (j < num)
		{
			long long sum = arr[j];
			while (j < num - 1 && sum + arr[j + 1] <= minmax)
			{
				sum += arr[j + 1];
				j++;
			}
			j++;
			if (j != num)
			{
				ans[i] = j;
				i++;
			}
	
			if (i >= k - 1)
				break;
		}

		int count = 0;
		int a = i;
		for (int b = 1; i < k - 1; b++)
		{
			if (b != ans[count])
			{
				printf("%d ", b);
				i++;
			}
			else
			{
				printf("%d ", ans[count]);
				count++;
			}
		}
		for (int b = count; b < a; b++)
		{
			printf("%d ", ans[b]);
		}
	}
}
int main()
{
	int number, k; 
	long long minmax, i;
	scanf("%d %d", &number, &k);
	int *arr=malloc(number*sizeof(int));
	long long *ans = malloc(k * sizeof(long long));
	for (i = 0; i < number; i++) 
	{
		scanf("%d", &arr[i]);
	
	}
	minmax = search(arr, number, k);
	split(ans, arr, number, k, minmax);
	return 0;
}
