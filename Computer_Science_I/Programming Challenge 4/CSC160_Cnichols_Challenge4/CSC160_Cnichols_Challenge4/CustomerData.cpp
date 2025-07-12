#pragma once
#include "CustomerData.h"
#include "PersonData.h"
#include <string>
using namespace std;

// Creating constructors
CustomerData::CustomerData(string first, string last, string address, string phone, 
	int number, bool mail) : firstName(first), lastName(last), personAddress(address)
	, phoneNumber(phone), customerNumber(number), mailingList(mail)
{
	cout << "Constructing " << getPersonInfo() << endl;
}

CustomerData::CustomerData(string first, string last, int number, bool mail) : 
	firstName(first), lastName(last)
{
	cout << "Constructing " << getFullName() << endl;
}

CustomerData::CustomerData(string first, string last, string address, 
	string phone, int number, bool mail, string city, string state, string zip)
	: firstName(first), lastName(last), personAddress(address), 
	phoneNumber(phone), personCity(city), personState(state), zipCode(zip)
{
	cout << "Constructing " << getAllPersonInfo() << endl;
}

CustomerData::~CustomerData()
{
	cout << "Not yet implemented";
}
