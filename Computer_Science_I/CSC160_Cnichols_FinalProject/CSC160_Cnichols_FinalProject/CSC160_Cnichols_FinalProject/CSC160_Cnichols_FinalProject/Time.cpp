#include "Time.h"
#include <iostream>
using namespace std;



Time::Time()
{
	cout << "Constructing " << minute << " " << sec << endl;
}

Time::Time(int)
{
	cout << "Constructing " << sec << endl;
}

Time::Time(int, int)
{
	cout << "Constructing " << mill << " " << sec << endl;
}

Time::Time(int, int, int)
{
	cout << "Constructing " << mill << " " << sec << " " << minute << endl;
}

Time::Time(int, int, int, int)
{
	cout << "Constructing " << mill << " " << sec << " " << minute << " " << hr << endl;
}

Time::Time(int, int, int, int, int)
{
	cout << "Constructing " << mill << " " << sec << " " << minute << " " << hr << " " << day << endl;
}

Time::~Time()
{
	cout << "Destructing " << minute << " " << sec << endl;
}
