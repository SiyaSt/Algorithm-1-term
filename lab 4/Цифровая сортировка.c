#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void RadixSort(char** array, int number, int length, int phase)
{
	int start = 'a';
	int end = 'z';
	char** answer = malloc(number * sizeof(char*));
	int* a = calloc((end - start + 1), sizeof(int));
	/*for (i = 1; i < number;i++)
	{
		a[array[i][length]]++;
	}
	for (i = 1; i < 27; i++)
	{
		a[i] += a[i - 1];
	}
	for (i = number; i > 0; i--)
	{
		answer[a[array[i][length]]] = array[i];
		a[array[i][length]]--;
	}*/
	for (int j = length - 1; j >= length - phase; j--)
	{
		memset(a, 0, (end - start + 1) * sizeof(int));
		for (int i = 0; i < number; i++)
		{
			a[array[i][j] - start]++;
		}
		for (int i = 1; i < end - start + 1; i++)
		{
			a[i] += a[i - 1];
		}
		for (int i = number - 1;i >= 0;i--)
		{
			answer[--a[array[i][j] - start]] = array[i];
		}
		for (int i = 0; i < number; i++)
		{
			array[i] = answer[i];
		}
	}

}
int main()
{
	int number, lenght, phase;
	int i, j;
	scanf("%d %d %d", &number, &lenght, &phase);
	char** array = malloc(number * sizeof(char*));
	for (int i = 0; i < number;i++)
	{
		array[i] = malloc((lenght+1)*sizeof(char));
		scanf("%s", array[i]);
	}
	RadixSort(array, number, lenght, phase);
	for (int i = 0; i < number; i++)
	{
		printf("%s\n", array[i]);
	}
}
