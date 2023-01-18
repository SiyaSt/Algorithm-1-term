#include<iostream>
using namespace std;

int main()
{
	int arr[1000], num, buf;
	cin >> num;
	if (num >= 1 && num <= 1000)
	{
		for (int i = 0;i < num;i++)
		{
			cin >> arr[i];
		}
		for (int i = 1;i < num; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				int j = i;

				while (j >= 1 && arr[j] < arr[j - 1])
				{
					buf = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = buf;
					j--;
				}
			}
		}
		for (int i = 0;i < num; i++)
		{
			cout << arr[i]; cout << " ";
		}

	}
}
