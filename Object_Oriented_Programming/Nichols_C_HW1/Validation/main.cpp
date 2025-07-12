#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//Declaring variables
	double choice;
	double heat(double);
	int forecast[7];
	int initialInventory;
	
	//Asking the user for input
	cout << "How many plants are for sale tomorrow? ";
	cin >> choice;
	initialInventory = choice;

	//Populating array
	for (int i = 0; i < 7; i++)
	{
		cout << "How hot will it be on day " << i + 1 << "?: ";
		cin >> forecast[i];
		choice = heat(forecast[i]) * choice;
		choice = ceil(choice);
	}

	//Printing results
	cout << "Estimated total sale is " << initialInventory - choice << " plants." << endl;
	
	system("pause");
	return 0;
}

//Function to provide respective numbers
double heat(double x)
{
	if (x < 40)
	{ return 0.9; }
	if (x >= 40 && x <=60)
	{ return 0.7; }
	if (x >= 60 && x < 70)
	{ return 0.5; }
	if (x >= 70 && x < 80)
	{ return 0.4; }
	else
	{ return 0.6; }
}