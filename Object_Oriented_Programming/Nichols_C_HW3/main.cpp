#include <string>
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point();
	Point(int, int);

	//Getters
	int getX() { return x; }
	int getY() { return y; }

	// Setters
	void setX(int xCo) { x = xCo; }
	void setY(int yCo) { y = yCo; }
};

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int xCo, int yCo): x(xCo), y(yCo)
{
}

class Rectangle
{
private:
	int length;
	int width;
	Point p;
public:
	Rectangle();
	Rectangle(Point, int, int);

	//Getters
	int getLength() { return length; }
	int getWidth() { return width; }
	Point getPoint() { return p; }

	//Setters
	virtual void setLength(int l) { length = l; }
	virtual void setWidth(int w) { width = w; }
	void setPoint(Point point) { p = point; }
};

Rectangle::Rectangle()
{
	length = 0;
	width = 0;
}

Rectangle::Rectangle(Point point, int l, int w): p(point), width(w), length(l)
{
}

//Declaring variables
void output();
int intersect(Rectangle, Rectangle);
int length;
int width;
int xCo;
int yCo;
Point p1;
Point p2;
Rectangle r1;
Rectangle r2;
void getPoint(Rectangle, Point, int);
bool operator%(Rectangle& r1, Rectangle& r2);

int main()
{
	// Get input for rectangle 1
	cout << "x of rectangle 1: ";
	cin >> xCo;
	cout << endl << "y of rectangle 1: ";
	cin >> yCo;
	cout << endl << "length of rectangle 1: ";
	cin >> length;
	cout << endl << "width of rectangle 1: ";
	cin >> width;

	// Set object for rectangle 1
	p1.setX(xCo);
	p1.setY(yCo);
	r1 = Rectangle(p1, length, width);

	//Get input for rectangle 2
	cout << endl << "x of rectangle 2: ";
	cin >> xCo;
	cout << endl << "y of rectangle 2: ";
	cin >> yCo;
	cout << endl << "length of rectangle 2: ";
	cin >> length;
	cout << endl << "width of rectangle 2: ";
	cin >> width;

	// Set objects for rectangle 2
	p2.setX(xCo);
	p2.setY(yCo);
	r2 = Rectangle(p2, length, width);

	// Output results
	output();
	bool validate = r1 % r2;
	return 0;
}

void output()
{
	cout << endl << "Co-ordinates of rectangle 1: "; 

	//Function to output the coordinates
	getPoint(r1, p1, 1);
	getPoint(r1, p1, 2);
	getPoint(r1, p1, 3);
	getPoint(r1, p1, 4);
	cout << endl << endl << "Co-ordinates of rectangle 2: ";
	getPoint(r2, p2, 1);
	getPoint(r2, p2, 2);
	getPoint(r2, p2, 3);
	getPoint(r2, p2, 4);
	cout << endl << endl;
}

void getPoint(Rectangle x, Point z, int y)
{
	xCo = z.getX();
	yCo = z.getY();
	length = x.getLength();
	width = x.getWidth();
	if (y > 2)
	{
		xCo = xCo + width;
	}
	if (y > 1 && y < 4)
	{
		yCo = yCo - length;
	}
	
	cout << "(" << xCo << ", " << yCo << "), ";
}

bool operator%(Rectangle& a, Rectangle& b)
{
	Point r1P = a.getPoint();
	int r1x1 = r1P.getX();
	int r1x2 = r1x1 + a.getWidth();
	int r1y1 = r1P.getY();
	int r1y2 = r1y1 - a.getLength();
	Point r2P = b.getPoint();
	int r2x1 = r2P.getX();
	int r2x2 = r2x1 + a.getWidth();
	int r2y1 = r2P.getY();
	int r2y2 = r2y1 - a.getLength();

	if ((r1x2 > r2x1 && r2x1 > r1x1) || (r1x2 > r2x2 && r2x2 > r1x1))
	{
		if ((r1y2 < r2y1 && r2y1 < r1y1) || (r1y2 < r2y2 && r2y2 < r1y1))
		{
			cout << "They intersect." << endl;
			return true;
		}
		else
		{
			cout << "They do not intersect." << endl;
			return false;
		}
	}
	else
	{
		cout << "They do not intersect." << endl;
		return false;
	}
}