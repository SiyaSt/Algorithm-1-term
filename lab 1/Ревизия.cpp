#include<iostream>
using namespace std;

int main()
{
	int n, i, b;
	int min1, min2;
	cin >> n;
	i = 0;
	if (n >= 2 && n <= 1000)
		do
		{
			cin >> b; cout << " ";
			if (abs(b) < (2000000000))
			{
				if (i == 0)
					min1 = b;
				 if (i == 1)
					if (min1 >= b)
					{
						min2 = min1;
						min1 = b;
					}
					else
						min2 = b;
				if (i>1)
				if (min1 >= b)
				{
					min2 = min1;
					min1 = b;
				}
				else
					if (min1<b && min2>b)
						min2 = b;
				i++;
			}
			else cout << "Error number" ;
		} while (i < n); cout << min1 << " " << min2;
}
