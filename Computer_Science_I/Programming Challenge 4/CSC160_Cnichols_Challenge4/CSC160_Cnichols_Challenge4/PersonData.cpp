#pragma once

#include <string>
#include <iostream>
#include "PersonData.h"


// Creating constructors
PersonData::PersonData(string first, string last, string address, string phone): 
	firstName(first), lastName(last), personAddress(address), phoneNumber(phone)
{
	cout << "Constructing " << getPersonInfo() << endl;
}

PersonData::PersonData(string first, string last) : firstName(first), lastName(last)
{
	cout << "Constructing " << getFullName() << endl;
}

PersonData::PersonData(string first, string last, string address, string phone,
	string city, string state, string zip) : firstName(first), lastName(last),
	personAddress(address), phoneNumber(phone), personCity(city),
	personState(state), zipCode(zip)
{
	cout << "Constructing " << getAllPersonInfo() << endl;
}

// Creating destructor
PersonData::~PersonData()
{
	cout << "destructing " << getPersonInfo() << endl;
}
// Creating function to call and display object information
string PersonData::getPersonInfo()
{
	return firstName + " " + lastName + " " + personAddress + " " + phoneNumber;
}

string PersonData::getFullName()
{
	return firstName + " " + lastName;
}

string PersonData::getAllPersonInfo()
{
	return firstName + " " + lastName + " " + personAddress + " " + phoneNumber
		+ " " + personCity + " "+ personState + " " + zipCode;
}