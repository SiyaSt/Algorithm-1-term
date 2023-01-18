#include <iostream>
#include <vector>
using std::vector;


void increasing_subsequence(vector<int> &array)
{
	int size = array.size();

	vector<vector<int>> subsequence(size, vector<int>{});
	subsequence[0].push_back(array[0]);

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[i]> array[j] && subsequence[i].size()< subsequence[j].size())
			{
				subsequence[i] = subsequence[j];
			}
		}
		subsequence[i].push_back(array[i]);
	}

	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (subsequence[index].size() < subsequence[i].size())
		{
			index = i;
		}
	}
	std::cout << subsequence[index].size() << "\n";
	for (int i : subsequence[index])
	{
		std::cout << i << " ";
	}


}

int main()
{
	using namespace std;
	int number;
	cin >> number;

	vector<int> array;
	vector<int> answer;
	for (int i = 0; i < number; i++)
	{
		int* arr = new int[number];
		cin >> arr[i];
		array.push_back(arr[i]);
	}
	increasing_subsequence(array);

}
