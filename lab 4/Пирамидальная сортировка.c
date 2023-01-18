#include<iostream>
using namespace std;

void Heapify(int array[], int number, int i)
{
	int bigdick = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<number && array[left]>array[bigdick])
	{
		bigdick = left;
	}
	if (right<number && array[right]>array[bigdick])
	{
		bigdick = right;
	}
	if (bigdick != i)
	{
		swap(array[i], array[bigdick]);
		Heapify(array, number, bigdick);
	}
}
void HeapSort(int array[], int number)
{
	for (int i = number / 2 - 1; i >= 0; i--)
	{
		Heapify(array, number, i);
	}
	for (int i = number - 1; i >= 0; i--)
	{
		swap(array[0], array[i]);
		Heapify(array, i, 0);
	}
}
int main()
{
	int number;
	cin >> number;
	int* array = new int[number];
	for (int i = 0; i < number; i++)
	{
		cin >> array[i];
	}
	HeapSort(array, number);
	for (int i = 0; i < number;i++)
	{
		cout << array[i] << " ";
	}
}
