# pragma once
#include <string>
#include "Status.h"

using namespace std;
//Creating class student
class Student 
{
private:
	// Declaring private variables
	string studentID;
	string firstName;
	string lastName;
	string studentStatus;
public:
	//Constructor and descructor
	Student(string first, string last, string status);
	~Student();
	string getStudentInfo();
	string getStudentID() const {return studentID;}
	void setStudentID(string ID) { studentID = ID; }
	string getFirstName() const {return firstName;}
	void setFirstName(string first) { firstName = first; }
	string getLastName() const {return lastName;}
	void setLastName(string last) { lastName = last; }
	string getStatus() const {return studentStatus;}
	void setStatus(string status) { studentStatus = status; }
};
