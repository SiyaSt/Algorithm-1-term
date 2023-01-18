#include<iostream>
using namespace std;

int main()
{
	int arr[100], k, num, buf;
	cin >> num;
	if (num >= 1 && num <= 100)
	{
		for (int i = 0;i < num;i++)
		{
			cin >> arr[i];
			if (arr[i] > 10000000000)
				i--;
		}
		for (int i = 1;i < num;i++)
		{
			if (arr[i - 1] <= arr[i])
				continue;
			else
			{
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
						for (k = 0;k < num; k++)
						{
							cout << arr[k]; cout << " ";
						}
						cout << endl;
					}
				}
			}
		}
	}
}
