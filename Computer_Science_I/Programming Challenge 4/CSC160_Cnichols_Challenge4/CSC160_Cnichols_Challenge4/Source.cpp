// Program Created by Cade Nichols
#include <string>
#include <iostream>
#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

int main()
{
	// Declaring variables
	string firstName;
	string lastName;
	string address;
	string phone;
	int number;
	char choice;
	bool mail;

	// Getting info from user
	cout << "Enter first name: ";
	cin >> firstName;
	cout << endl << "Enter last name: ";
	cin >> lastName;
	cout << endl << "Enter address: ";
	cin >> address;
	cout << endl << "Enter phone number: ";
	cin >> phone;
	cout << endl << "Enter customer number: ";
	cin >> number;

	// Determining mailing list variable
	cout << endl << "Would you like to be on the waiting list?(y or n): ";
	cin >> choice;

	// Using answer to set bool
	if (choice = 'n')
	{
		mail = false;
	}
	else if (choice = 'y')
	{
		mail = true;
	}

	// Creating object using user info
	CustomerData(firstName, lastName, address, phone, number, mail);


	system("pause");
	return 0;
}