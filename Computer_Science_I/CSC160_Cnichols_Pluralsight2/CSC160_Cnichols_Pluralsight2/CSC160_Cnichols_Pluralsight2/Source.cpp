// Created by Cade Nichols
#pragma once
#include "Student.h"
#include <iostream>
#include <string>
#include "Status.h"
#include "Accum.h"
using namespace std;
int getNumStudents(int);
void displayStudents(string[], int);
Student updateStudent(Student);

int main()
{
	//Declaring variables
	string first;
	string last;
	string ID;
	int numStudents = 35;
	string students[32];
	Accum<string> strings("");

	//Pluralsight 3 stuff
	numStudents = getNumStudents(numStudents);
	//cout << numStudents;

	for (int i = 0; i < numStudents; ++i)
		{//Getting data from user
		cout << "First name: ";
		cin >> first;
		strings += first;
		cout << endl << "Last name: ";
		cin >> last;
		strings += " " + last;
		cout << endl << "Student ID number: ";
		cin >> ID;
		strings += " " + ID + "\n";
		cout << strings.GetTotal() << " has been added!" << endl;

		//Creating Object
		
		Student s1 = Student(ID, first, last);

		//Asking user if they want to update the student's information
		char choice;
		cout << "Would you like to update any of this information? (y or n): ";
		cin >> choice;
		string update;
		if (choice == 'y')
		{
			Student* pNew = &s1;
			s1 = updateStudent(*pNew);


		}
		else if (choice == 'n')
		{
			students[i] = first + " " + last + " " + ID;
		}
		
	}
	displayStudents(students, numStudents);


	//Bool for choice when determining status
	//bool choice;

	//

	////Creating object
	//Student a1(ID, first, last);
	//


	////Determining status
	//cout << "Is this student currently attending school?(yes/no): ";
	//cin >> choice;
	//if (choice = "no")
	//{
	//	cout << "Was a degree obtained?(yes/no): ";
	//	cin >> choice;
	//	if (choice = "no")
	//		studentStatus s = Graduated;
	//	else
	//		studentStatus s = NonAttending;

	//}
	//else
	//	studentStatus s = Attending;

	////Printing out student information
	//string name = a1.getStudentInfo();
	//cout << name;

	system("pause");
	return 0;
}
int getNumStudents(int numStudents)
{
	while (true)
	{
		cout << "Enter number of students: ";
		cin >> numStudents;
		cout << endl;
		if (numStudents <= 32 && numStudents >= 0)
		{
			return numStudents;
		}
		else
			cout << "Enter a number between 0 and 32" << endl;
			continue;
	}
	return numStudents;
}
void displayStudents(string students[], int numStudents)
{
	for (int i = 0; i < numStudents; ++i)
	{
		cout << students[i] << endl;
	}
}

Student updateStudent(Student newStudent)
{
	int choice;
	string first;
	string last;
	string ID;
	cout << "Change first name, last name, or ID#? (1,2, or 3): ";
	cin >> choice;
	if (choice == 1)
	{
		cout << "What is new first name?: ";
		cin >> first;
		newStudent.setFirstName(first);
	}
	else if (choice == 2)
	{
		cout << "What is new last name?: ";
		cin >> last;
		newStudent.setLastName(last);
	}
	else if (choice == 3)
	{
		cout << "What is new ID?: ";
		cin >> ID;
		newStudent.setStatus(ID);
	}
	return newStudent;
}