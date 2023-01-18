#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

double garland(int num, double hight);

int main()
{
	int number;
	double hight1;
	scanf("%d %lf", &number, &hight1);
	double hight2= garland(number, hight1);
	if (hight2 > -1)
		printf("%.2f", hight2);
	return 0;
}

double garland(int num, double hight)
{
	double left = 0;
	double right = hight;
	double result = -1;
	while (true)
	{
		double mid = (left + right) / 2;
		if (mid == left || mid == right)
			break;
		double previous = hight;
		double current = mid;
		bool Ground = current > 0;
		for (int i = 3; i <= num; i++)
		{
			double next = 2 * current - previous + 2;
			Ground &= next > 0;
			previous = current;
			current = next;
		}
		if (Ground)
		{
			right = mid;
			result = current;
		}
		else
			left = mid;
	}
		return result;
}
