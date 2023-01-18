#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int num, buf;
	scanf("%d", &num);
	int* arr = malloc(num * sizeof(int));
	for (int j = 0;j < num;j++)
	{
		arr[j] = j + 1;
	}
	for (int j = 2; j < num;j++) 
	{
		buf = arr[j];
		arr[j] = arr[j / 2];
		arr[j/2] = buf;
	}
	for (int j = 0;j < num;j++)
	{
		printf("%d", arr[j]); printf(" ");
	}
}
