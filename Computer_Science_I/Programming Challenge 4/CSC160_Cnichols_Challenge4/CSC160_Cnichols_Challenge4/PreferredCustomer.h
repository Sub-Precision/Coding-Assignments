#pragma once
#include "CustomerData.h"

// Creating PreferredCustomer class
class PreferredCustomer :
	// Inheriting from CustomerData class
	public CustomerData
{
private:
	// Declaring private variables
	double purchasesAmount;
	double discountLevel;
public:
	// Constructors and Destructors
	PreferredCustomer();
	~PreferredCustomer();
};

