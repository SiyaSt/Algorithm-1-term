#include<iostream>
using namespace std;
int main()
{
	int n, i; 
	int a[1000] ;
	int k;
	k = 0;
	i = 0;
	cin >> n; 
	if (n >= 1 && n <= 1000)
	{
		for (i = 0;i < n; i++)
			cin >> a[i]; cout << " ";
	}
	for (i = 1; i < n-1; i++) 
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			k++;
	}
	cout << k;

}
