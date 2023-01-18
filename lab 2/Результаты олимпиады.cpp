#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct pars 
{
	int score;
	int id;
};

int partition_pars(struct pars* arr, int number, struct pars pivot) {
	char flag = 0;
	int i = 0, j = number - 1;
	struct pars* new_arr = malloc(number * sizeof(struct pars));
	for (int a = 0; a < number; a++)
	{
		if (arr[a].score > pivot.score)
		{
			new_arr[i].score = arr[a].score;
			new_arr[i].id = arr[a].id;
			i++;
		}
		else if (arr[a].score < pivot.score)
		{
			new_arr[j].score = arr[a].score;
			new_arr[j].id = arr[a].id;
			j--;
		}
		else if (arr[a].id < pivot.id)
		{
			new_arr[i].id = arr[a].id;
			new_arr[i].score = arr[a].score;
			i++;
		}
		else if (arr[a].id > pivot.id)
		{
			new_arr[j].id = arr[a].id;
			new_arr[j].score = arr[a].score;
			j--;
		}
		else
		{
			if (flag) {
				new_arr[i].score = arr[a].score;
				new_arr[i].id = arr[a].id;
				i++;
				flag = 0;
			}
			else {
				new_arr[j].id = arr[a].id;
				new_arr[j].score = arr[a].score;
				j--;
				flag = 1;
			}
		}
	}
	for (int a = 0; a < number; a++)
	{
		arr[a].id = new_arr[a].id;
		arr[a].score = new_arr[a].score;
	}
	free(new_arr);
	return j + 1;
}
void quick_sort_pars(struct pars* arr, int number)
{
	if (number <= 1)
	{
		return;
	}
	int random_elem = (int)rand() % number;
	int result = partition_pars(arr, number, arr[random_elem]);
	quick_sort_pars(arr, result);
	quick_sort_pars(arr + result, number - result);
	return;
}
int main()
{
	int people;
	scanf("%d", &people);
	struct pars* arr = malloc(people * sizeof(struct pars));
	for (int i = 0;i < people; i++)
	{
		scanf("%d %d", &arr[i].id, &arr[i].score);
	}
	quick_sort_pars(arr, people);
	for (int i = 0; i < people; i++)
	{
		printf("%d %d\n", arr[i].id, arr[i].score);
	}
}
