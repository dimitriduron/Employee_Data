//Files included
#include <iostream>
using namespace std;
#include "Employee.h"
#include "Owner.h"
#include "Chef.h"
#include "Waiter.h"

//Prototypes for driver
void editEarnings(int);
void prompt();

//public variables
long restEarnings = 6000;

int main()
{
	int x = 0;
	int input;
	//initial array to point to each member
	Employee *emp[6];
	//sets up each employee within the restaurant (1 owner, 2 chefs, 3 waiters)
	emp[0] = new Owner("John Doe", 1001, 'O', 15000, restEarnings);
	emp[1] = new Chef("Jeff Meff", 1010, 'C', 10000, restEarnings, "Italian");
	emp[2] = new Chef("Moot Loof", 1011, 'C', 10000, restEarnings, "French");
	emp[3] = new Waiter("Jessica Lam", 5321, 'W', 3000, restEarnings, 3, 1000);
	emp[4] = new Waiter("Matt Mattkins", 9182, 'W', 3000, restEarnings, 5, 1500);
	emp[5] = new Waiter("Peace Wozawski", 8888, 'W', 3000, restEarnings, 7, 1700);

	//outputs all employees in array of pointers
	for(int i = 0; i < 6; i++)
	{
		cout << *emp[i] << endl;
	}

	//run prompt for user
	while(x == 0)
	{
		prompt();
		cin >> input;
		if(input == 0)
		{
			x = 1;
			cout << "Enjoy!" << endl;
		}
		else if(input == 1)
		{
			cout << "Enter new tips for Waiter 1: $";
			cin >> input;
			emp[3]->bonus = input;
			emp[3]->total = emp[3]->bonus + 1000;
			cout << endl<< "Enter new tips for Waiter 2: $";
			cin >> input;
			emp[4]->bonus = input;
			emp[4]->total = emp[4]->bonus + 1500;
			cout << endl << "Enter new tips for Waiter 3: $";
			cin >> input;
			emp[5]->bonus = input;
			emp[5]->total = emp[5]->bonus + 1700;
			cout << endl;
			for(int i = 0; i < 6; i++)
			{
				cout << *emp[i] << endl;
			}
		}
		else if(input == 2)
		{
			cout << "New monthly earnings: $";
			cin >> input;
			editEarnings(input);
			for(int i = 0; i < 6; i++)
			{
				emp[i]->myRestEarnings = restEarnings;
				if(i == 0)
				{
					emp[i]->bonus = emp[i]->myRestEarnings * .6;
					emp[i]->total = emp[i]->bonus + 15000;
				}
				else if(i == 1 || i == 2)
				{
					emp[i]->bonus = emp[i]->myRestEarnings * .2;
					emp[i]->total = emp[i]->bonus + 10000;
				}
				cout << *emp[i] << endl;
			}
		}
		else
		{
			cerr << "Sorry! Wrong input :(" << endl;
		}
	}
	return 0;
}

void editEarnings(int input)
{
	restEarnings = input;
}


void prompt()
{
	cout << "Would you like to edit?" << endl
		 << "Press '2' to edit the restaurant's monthly income." << endl
		 << "Press '1' to edit the tips for all waiters." << endl
		 << "Press '0' to end the program." << endl << endl;
}
