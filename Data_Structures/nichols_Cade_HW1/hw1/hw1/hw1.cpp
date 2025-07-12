// Rectangle Comparison program by Cade Nichols
#include <iostream>
#include <string>
#include <vector>
#include "Comparator.h"
using namespace std;

// Variables and Vectors
vector<Rectangle> rectangles;
Rectangle bigRectangleArea;
Rectangle bigRectanglePerimeter;
AreaComparator area;
PerimeterComparator perimeter;

//Template Class
template<typename Object, typename Comparator>
const Object& findMax(const vector<Object>& rectangles, Comparator cmp)
{
	int MAX = 0;

	for (int i = 1; i < rectangles.size(); i++)
	{
		if (cmp.isLessThan(rectangles[MAX], rectangles[i]))
		{
			MAX = i;
		}
	}
	return rectangles[MAX];
}

int main()
{
	//Declaring Variables
	int num;
	int arrayLength[10];
	int arrayWidth[10];

	//Letting user input number of rectangles to help save time with grading
	cout << "How many rectangles?(Max 10): ";
	cin >> num;

	// Getting and writing all rectangles to arrays
	for (int i = 0; i < num; i++)
	{
		cout << "Rectangle " << i + 1 << " Length: ";
		cin >> arrayLength[i];
		cout << "Rectangle " << i + 1 << " Width: ";
		cin >> arrayWidth[i];
		Rectangle rect(arrayLength[i], arrayWidth[i]);
		rectangles.push_back(rect);
	}

	//Displaying rectangles
	cout << endl << "Your list of rectangles are: " << endl;
	for (int i = 0; i < num; i++)
	{
		cout << "Rectangle " << i + 1 << " Length of rectangle " << i + 1 << ": " << arrayLength[i] << " Width of rectangle " << i + 1 << ": " << arrayWidth[i] << endl;
	}

	//Calculating maximum sizes of both types
	bigRectanglePerimeter = findMax(rectangles, (PerimeterComparator) perimeter);
	bigRectangleArea = findMax(rectangles, (AreaComparator)area);

	// Displaying Results
	cout << "The largest rectangle by perimeter is: " << bigRectanglePerimeter.getPerimeter() << " units." << endl;
	cout << "The largest rectangle by area is: " << bigRectangleArea.getArea() << " units." << endl;

	return 0;
}