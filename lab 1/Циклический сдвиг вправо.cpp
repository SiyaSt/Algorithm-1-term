#include<iostream>
using namespace std;
int main()
{
	int n,i;
	int a[35];
	cin >> n;
	if (n >= 1 && n <= 35)
	{
		for (i = 0;i < n; i++)
			cin >> a[i]; cout << " ";
		int k, b;
		k = a[0];
		a[0] = a[n-1];
		cout << a[0];
		for (i = 1;i < n; i++)
		{
			b = a[i];
			a[i] = k;
			k = b;
			cout <<" "<< a[i];
		}
	}
	else return 0;
}
