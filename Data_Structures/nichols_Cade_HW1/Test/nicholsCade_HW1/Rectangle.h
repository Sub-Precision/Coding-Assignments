// Rectangle Class
// Author: Cade Nichols
// Version: 9 / 14 / 22

using namespace std;

class Rectangle
{
private:
	int length;
	int width;
	int area;
	int perimeter;

public:
	Rectangle();
	Rectangle(int length, int width);
	// Getters
	int getLength() { return length; }
	int getWidth() { return width; }
	int getArea() { area = length * width;  return area; }
	int getPerimeter() { perimeter = (width * 2) + (length * 2);  return perimeter; }

	// Setters
	void setLength(int l) { length = l; }
	void setWidth(int w) { width = w; }
	void setArea(int a) { area = a; }
	void setPerimeter(int p) { perimeter = p; }

};
