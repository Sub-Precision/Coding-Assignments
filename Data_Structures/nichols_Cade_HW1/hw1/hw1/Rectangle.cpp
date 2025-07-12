// Rectangle Class
// Author: Cade Nichols
// Version: 9 / 14 / 22


#include "Rectangle.h"
#include <iostream>
#include <string>
using namespace std;

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int length, int width)
{
	setLength(length);
	setWidth(width);
}