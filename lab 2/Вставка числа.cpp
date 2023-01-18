#include<iostream>
using namespace std;

int main()
{
	int arr[1000],num;
	cin >> num;
	for (int i = 1; i < num+1; i++)
		cin >> arr[i];
	int number, place;
	cin >> number; cout << " "; cin >> place;
	int buf1,buf2;
	buf1 = arr[place];
	arr[place] = number;
	for (int i = place + 1;i < num+2;i++) 
	{
		buf2 = arr[i];
		arr[i] = buf1;
		buf1 = buf2;
	}
	for (int i = 1;i < num+2;i++)
	{
		cout << arr[i]; cout << " ";
	}
}
