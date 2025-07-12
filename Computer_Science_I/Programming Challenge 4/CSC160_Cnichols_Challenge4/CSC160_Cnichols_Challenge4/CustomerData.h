#pragma once
#include "PersonData.h"

// Creating class CustomerData
class CustomerData :
	// Inheriting from PersonData class
	public PersonData
{
private:
	// Declaring private variables
	int customerNumber;
	bool mailingList;
public:
	// Constructors and destructor
	CustomerData(string first, string last, string address, string phone, int number, bool mail);
	CustomerData(string first, string last, int number, bool mail);
	CustomerData(string first, string last, string address, string phone, int number, bool mail, 
		string city, string state, string zip);
	~CustomerData();

	// Getters and setters
	int getCustomerNumber() const { return customerNumber; }
	void setCustomerNumber(int number) { customerNumber = number; }
	bool getMailingList() const { return mailingList; }
	void setMailingList(bool mail) { mailingList = mail; }
};

