#include<iostream>
#include <string>
using namespace std;


int main()
{
	struct Fridge
	{
		char prname[50];
		char unitname[10];
		float amount;
	}fr[4];
	fr[1] = { "Milk","l",3 };
	fr[2] = { "Meat","kg",1.5};
	fr[3] = { "Cheese","pieces",5 };
	fr[4] = { "Pickles","jars",10 };

	fr[1].amount = fr[1].amount - 1.5;
	fr[3].amount = fr[3].amount - 3.5;
	fr[4].amount = fr[4].amount - 4;
}
