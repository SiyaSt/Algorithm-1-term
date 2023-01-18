#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>


int binsearch1(int arr1[], int arr[], int n, int i);
int binsearch2(int arr1[], int arr[], int n, int i);

    int main()
 {
     int n, coul;
     scanf("%d", &n);
     int* arr;
     arr = (int*)malloc(n * sizeof(int));
     for (int i = 0;i < n;i++)
         scanf("%d", &arr[i]);
     scanf("%d", &coul);
     int* arr1 = malloc(coul * sizeof(int));
	 for (int i = 0; i < coul;i++)
		 scanf("%d", &arr1[i]);
	 for(int i=0;i<coul;i++)
		{ 
		 int id1 = binsearch1(arr1, arr, n, i);
		 int id2 = binsearch2(arr1, arr, n, i);
		 if (id1 != -1 && id2 != -1)
			 printf("%d %d\n", id1+1, id2+1);
		 else
			 printf("-1 -1\n");
		}

 }
    
 int binsearch1(int arr1[], int arr[], int n, int i)
  {
	int left = 0;
	int right = n ;
	int mid;
	int result = -1;
		while (left <= right)
		{
			mid = (right + left) / 2;
			if (arr1[i] == arr[mid])
			{
				result = mid;
				right = mid - 1;
				
			}
			else if (arr1[i] < arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return result;
}
	int binsearch2(int arr1[], int arr[], int n, int i)
	{
		int left = 0;
		int right = n;
		int mid;
		int result = -1;
		while (left <= right)
		{
			mid = (right + left) / 2;
			if (arr1[i] == arr[mid])
			{
				result = mid;
				left = mid + 1;
			}
			else if (arr1[i] < arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return result;
 }
