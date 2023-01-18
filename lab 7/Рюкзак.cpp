#include<iostream>

int maximum(int a, int b)
{
	return (a < b) ? b : a;
}

int find_answer(int* price, int* weight, int capacity, int number)
{
	int** array;
	array = new int* [number+1];
	for (int i = 0; i < number+1; i++)
	{
		array[i] = new int[capacity+1];
	}

	for (int i = 0; i <= capacity; i++)
	{
		array[0][i] = 0;
	}
	for (int k = 1; k <= number; k++)
	{
		for (int s = 0; s <= capacity; s++)
		{
			if (s < weight[k-1])
			{
				array[k][s] = array[k - 1][s];
				
			}
			else
			{
				array[k][s] = maximum(array[k - 1][s], array[k - 1][s - weight[k-1]] + price[k-1]);
			}
		}
	}
	return array[number][capacity];
}

int main()
{
	using namespace std;

	int capacity, number;
	cin >> capacity >> number;

	int* weight = new int[number];
	int* price = new int[number];
	for (int i = 0; i < number; i++)
	{
		cin >> weight[i];
		price[i] = weight[i];
	}

	cout << find_answer(price, weight, capacity, number);

	
}
