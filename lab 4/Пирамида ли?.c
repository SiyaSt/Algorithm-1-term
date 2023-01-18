#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int num;
	scanf("%d", &num);
	int *arr = malloc(num * sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	int f = 0;
	for (int i = 0; i < num; i++)
	{
		if ((2 * i + 1 < num) && (arr[i] > arr[2 * i + 1]))
		{	
			f = 1;
			break;
		}
		if (2 * i + 2 < num && (arr[i] > arr[2 * i + 2]))
		{
			f = 1;
			break;
		}
	}
	if (f == 1)
		printf("NO\n");
	else
		printf("YES\n");
}
