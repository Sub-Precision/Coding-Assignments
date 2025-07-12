// Created by Cade Nichols
#include <iostream>
#include <string>

using namespace std;

int sorter(int array[], int);
double average(int array[], int);

int main()
{
	//Declaring variables
	const int SIZE = 10;
	int scores[SIZE];
	string names[SIZE];
	int num = 0;
	int lowest = 11;
	string name;
	double averageScore;

	//Allocating test scores into the array
	
	for (int i = 0; i < SIZE; ++i)
	{
		cout << "Enter student's name and test score: ";
		cin >> name >> num;

		//validation
		while (num < 0)
		{
			cout << "Number cannot be less than 0, please re-enter number: ";
			cin >> num;
			
		}
		//inserting student's name and validated number into 2 arrays
		scores[i] = num;
		names[i] = name;
	}

	//Sorting function (incomplete)
	//sortedScores[SIZE] = sorter(scores, SIZE);
	
	num = scores[0];
	// Finding the lowest number in the array
	for (int i = 0; i < SIZE; ++i)
	{
		
		if (scores[i] < num)
		{
			num = scores[i];
			lowest = i;
		}
	}
	// reducing the lowest score to zero
	scores[lowest] = 0;

	// Displaying menu
	averageScore = average(scores, SIZE);
	cout << "Student's Name ----- Student's Score" << endl;

	// printing results
	for (int i = 0; i < SIZE; i++)
	{
		cout << names[i] << endl << "                     " << scores[i] << endl;
	}
	cout << endl << "Class average (with lowest dropped): " << averageScore << endl << endl;


	system("pause");
	return 0;
}

int sorter(int array[], int SIZE)
{
	//I wouldnt even know how to explain how to do this within 50 lines on a doc, let alone in code
	int num;
	int newArray[10];
	for (int i = 0; i < SIZE; ++i)
	{
		if (array[i] > array[i + 1])
		{
			newArray[i] = array[i + 1];
		}
		else
			newArray[i] = array[i];
	}
	return newArray[SIZE];
}

double average(int array[], int SIZE)
{
	double num = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		num = num + array[i];
	}
	// (Size minus 1) is because the lowest score was "dropped" so the size of the array has been 
	// theoretically lowered
	num = num / (SIZE - 1);
	return num;
}


