#pragma once
#include <string>
using namespace std;

//Creating class person
class PersonData
{
private:
	//Declaring private variables
	string firstName;
	string lastName;
	string personAddress;
	string phoneNumber;
	string personCity;
	string personState;
	string zipCode;
public:
	//Constructor and destructor
	PersonData(string first, string last, string address, string phone);
	PersonData(string first, string last);
	PersonData(string first, string last, string address, string phone, 
		string city, string state, string zip);
	~PersonData();

	// Functions to return strings of various amounts of information
	string getPersonInfo();
	string getFullName();
	string getAllPersonInfo();

	// Getters and setters
	string getFirstName() const { return firstName; }
	void setFirstName(string first) { firstName = first; }
	string getLastName() const { return lastName; }
	void setLastName(string last) { lastName = last; }
	string getAddress() const { return personAddress; }
	void setAddress(string address) { personAddress = address; }
	string getPhoneNumber() const { return phoneNumber; }
	void setPhoneNumber(string phone) { phoneNumber = phone; }
	string getCity() const { return personCity; }
	void setCity(string city) { personCity = city; }
	string getState() const { return personState; }
	void setState(string state) { personState = state; }
	string getZipCode() const { return zipCode; }
	void setZipCode(string zip) { zipCode = zip; }
};