#include <iostream>

int maximum(int a, int b)
{
	return (a < b) ? b : a;
}
int h(int** tree, int n_root)
{
	if (n_root == 0) 
	{
		return 0;
	}
	else
	{
		
		return maximum (h(tree, tree[n_root - 1][1]) + 1,
			h(tree, tree[n_root - 1][2]) + 1);
	}
	
	
}


int main()
{
	using namespace std;
	int** array;
	int n;

	cin >> n;

	array = new int* [n];
	for (int i = 0; i < n; i++) 
	{
		array[i] = new int[3];
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			cin >> array[i][j];
		}
	}
	cout << h(array, 1 && n);
}
