#pragma once
#include "Student.h"
#include <string>
#include <iostream>
#include "Status.h"

// Creating constructor
Student::Student(string ID, string first, string last) : 
	firstName(first), lastName(last), studentID(ID)
{
	cout << "Constucting " << getStudentInfo() << endl;
}

//Creating destructor
Student::~Student()
{
	cout << "destructing " << getStudentInfo() << endl;
}

//Creating function to call and display object information
string Student::getStudentInfo()
{
	return firstName + " " + lastName + " " + studentStatus;
}
//string Student::getStudentID() const
//{
//	return studentID;
//}
//
//string Student::getFirstName() const
//{
//	return firstName;
//}
//
//string Student::getLastName() const
//{
//	return lastName;
//}
//
//string Student::getStatus() const
//{
//	return studentStatus;
//}

