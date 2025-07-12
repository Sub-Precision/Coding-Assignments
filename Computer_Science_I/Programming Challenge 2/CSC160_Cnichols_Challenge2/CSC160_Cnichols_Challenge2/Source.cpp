//Created by Cade Nichols

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//Declare variables
	int choice;
	int numCreditHours;
	int difficulty;
	double tuition000;
	double tuition100;
	double tuition200;
	double finalTuition;
	double subTuition;

	// Reading data from a file
	ifstream infile;
	infile.open("tuitionAmounts.txt");
	infile >> tuition000 >> tuition100 >> tuition200;
	infile.close();

	//Getting info from user
	cout << "How many credit hours?: ";
	cin >> numCreditHours;
	cout << endl;
	
	while (true)
	{	
		//Display menu 
		cout << endl;
		cout << "1. 000 Level Courses - $178.25 / hour" << endl;
		cout << "2. 100 Level Courses - $232.42 / hour" << endl;
		cout << "3. 200 Level Courses - $274.41 / hour" << endl;
		cout << "4. Exit program" << endl;
		cout << endl << "Make your selection(1, 2, 3 or 4): ";
		cin >> choice;
		cout << endl;

		//Evaluate Choice
		switch (choice)
		{
		//Difficulty 000
		case 1:
			cout << "Tuition is $" << tuition000 << " per hour" << endl;
			cout << endl;
			finalTuition = tuition000;
			difficulty = 000;
			break;
		//Difficulty 100
		case 2:
			cout << "Tuition is $" << tuition100 << " per hour" << endl;
			cout << endl;
			finalTuition = tuition100;
			difficulty = 100;
			break;
		//Difficulty 200
		case 3:
			cout << "Tuition is $" << tuition200 << " per hour" << endl;
			cout << endl;
			finalTuition = tuition200;
			difficulty = 200;
			break;

		//Exit command
		case 4:
			cout << "Thanks for using the program!" << endl;
			cout << "The program will now exit." << endl;
			system("pause");
			return 0;

		//Loops menu if invalid choice was made
		default:
			cout << "You have made an incorrect selection!" << endl;
			cout << endl;
			continue;
		}

		// Writing data to a file
		ofstream outfile; // creating a file object
		outfile.open("TuitionReportResults.txt");

		//Putting first year tuition in the file
		outfile << finalTuition * numCreditHours * 2 << endl;

		//Displaying yearly Tuition report
		cout << setprecision(2) << fixed;
		cout << "Community College of Aurora Tuition Report" << endl;
		cout << "           Level " << difficulty << endl;
		cout << "------------------------------------------" << endl;
		cout << "Year                  Tuition" << endl;
		cout << "-----                 -------" << endl;
		cout << "Year 1                $" << finalTuition * numCreditHours * 2 << endl;

		//Looping following 5 years
		for (int i = 2; i < 7; ++i) //year starts at 2 and goes to 6 to display years 2 - 6
		{
			//Math
			//Multiplicative hopefully
			finalTuition = finalTuition * 1.02;
			//Uses new variable so finalTuition doesn't get messed with when doing more math to it
			subTuition = finalTuition - 0;
			//Yearly tuition
			subTuition = subTuition * numCreditHours * 2;
			//Displaying each year in a format like the first
			cout << "Year " << i << "                $" << subTuition << endl;
			//Writing the results to the file
			outfile << subTuition << endl;
		}
		outfile.close();
	}

		system("pause");
		return 0;
}
