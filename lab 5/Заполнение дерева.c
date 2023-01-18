#include <iostream>
int recur_filling(int**, int, int);


int main()
{
	using namespace std;
	int** matrix, n;

	cin >> n;

	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[3];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 3; j++) {
			cin >> matrix[i][j];
		}
	}

	recur_filling(matrix, 1 && n, n);
	for (int i = 0; i < n; i++) {
		cout << matrix[i][0] << ' ';
	}
}

int recur_filling(int** tree, int n_root, int n)
{
	if (n_root == 0) {
		return n;
	}
	int left = tree[n_root - 1][1],
		right = tree[n_root - 1][2];
	n = recur_filling(tree, right, n);

	tree[n_root - 1][0] = n;

	return recur_filling(tree, left, n - 1);
}
