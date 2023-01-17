#include<iostream>
using namespace std;
int main()
{
	int n, i;
	int a[1000];
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cin >> a[i]; cout << " ";
		if (abs(a[i]) > 1000)
		{
			i--;
			cout << "Error";
		}
	}
	int x,y,rmin;
	cin >> x;
	if (abs(x) > 1000)
		cout << "Error";
	rmin = x - a[0];
	y = a[0];
	for (i = 1; i < n;i++)
	{
		if (abs(rmin) >= abs(x - a[i]))
		{
			rmin = x - a[i];
			y = a[i];
		}
	}
	cout << y;
}
