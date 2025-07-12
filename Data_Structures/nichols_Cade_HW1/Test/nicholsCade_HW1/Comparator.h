// Comparator Class
// Author: Cade Nichols
// Version: 9 / 14 / 22

#include "Rectangle.h"
#include <iostream>

using namespace std;

class AreaComparator :
	public Rectangle
{
public:
	//static function
	static bool isLessThan(Rectangle a, Rectangle b)
	{
		// getting numbers to compare rectangles
		int a1 = a.getArea();
		int a2 = b.getArea();

		if (a1 < a2)
		{
			return true;
		}
		if (a1 > a2)
		{
			return false;
		}
		else
		{
			cout << "The rectangles have the same area" << endl;
			return false;
		}

	}
};


class PerimeterComparator :
	public Rectangle
{
public:
	//static function
	static bool isLessThan(Rectangle a, Rectangle b)
	{
		int p1 = a.getPerimeter();
		int p2 = b.getPerimeter();

		// Computing the numbers to get area

		if (p1 < p2)
		{
			return true;
		}
		if (p1 > p2)
		{
			return false;
		}
		else
		{
			cout << "The rectangles have the same perimeter" << endl;
			return false;
		}

	}
};