#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;

#define PORTION 6.6
#define SIZE 10
int listofX[15];
int listofY[15];
class Grid
{
private:
    int array[SIZE][SIZE]; //2D array, default size
    int col;//column size
    int row;//row size
    int compare(int a, int b);
public:
    Grid(int incol, int inrow);
    
    int getCol()
    {
        return col;
    };
    int getRow()
    {
        return row;
    };
    int getVal(int incol, int inrow)
    {
        return array[inrow][incol];
    };
    void print()
    {
        for (int y = 0; y < row; y++)
        {
            for (int x = 0; x < col; x++)
            {
                cout << array[y][x] << " ";
            }
            cout << endl;
        }
    };
    void random()
    {
        int fill = (col * row) / PORTION;
        int index = 0;
        while (index < fill) {
            int rcol = rand() % col;
            int rrow = rand() % row;
            if (1 != array[rrow][rcol]) {
                array[rrow][rcol] = 1;
                listofX[index] = rrow;
                listofY[index] = rcol;
                
                index++;
            }
        }
    };

};

Grid::Grid(int incol, int inrow) {
    col = incol;
    row = inrow;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] = 0;
        }
    }
}

class WaterVehicle
{
private:
    //declaring water vehicle variables
    int length;
    int locateX;
    int locateY;
    bool ori;
    bool sunk;
    bool hit;
public:
    //getters
    int getLength() { return length; }
    int getLocateX() { return locateX; }
    int getLocateY() { return locateY; }
    bool getOri() { return ori; }
    bool getSunk() { return sunk; }
    bool getHit() { return hit; }
    //setters
    void setLength(int l) { length = l; }
    void setLocateX(int x) { locateX = x; }
    void setLocateY(int y) { locateY = y; }
    void setOri(bool o) { ori = o; }
    void setSunk(bool s) { sunk = s; }
    void setHit(bool h) { hit = h; }

    WaterVehicle()
    {
        length = 1;
        locateX = 0;
        locateY = 0;
        ori = false;
        sunk = false;
        hit = false;
    }
    WaterVehicle(int length, int locateX, int locateY, bool ori, bool sunk, bool hit)
    {
    }

};

class Submarine :
    public WaterVehicle
{
private:
    int depth;
    bool surf;
public:
    int getDepth() { return depth; }
    bool getSurf() { return surf; }
    void setDepth(int d) { depth = d; }
    void setSurf(int s) { surf = s; }

    Submarine()
    {
        depth = 0;
        surf = true;
    }
    Submarine(int length, int locateX, int locateY, bool ori, bool sunk, bool hit, int depth, bool surf)
    {
    }

    void operator = (Submarine& sub2)
    {
        depth = sub2.getDepth();
        surf = sub2.getSurf();
        setLength(sub2.getLength());
        setLocateX(sub2.getLocateX());
        setLocateY(sub2.getLocateY());
        setOri(sub2.getOri());
    }
};

int main()
{
int length1;
int locateX1;
int locateY1;
string ori1;
bool orientation;
int depth1;
bool surface;
Submarine sub1;
Submarine sub2;
int popMap[10][10];
int strikeMap[10][10];
//variables for both submarines
cout << "Length of submarine: ";
cin >> length1;
cout << endl << "left most X coordinate of submarine: ";
cin >> locateX1;
cout << endl << "lowest y coordinate of submarine: ";
cin >> locateY1;
cout << endl << "Is submarine vertical? (y or n): ";
cin >> ori1;
if (ori1 == "y")
{
    orientation = false;
}
else
{
    orientation = true;
}
sub1.setOri(orientation);
cout << endl << "depth of submarine: ";
cin >> depth1;
cout << endl << "is submarine surfaced?: ";
cin >> surface;
//Creating object
sub1.setLength(length1);
sub1.setLocateX(locateX1);
sub1.setLocateY(locateY1);
sub1.setSurf(surface);
sub1.setDepth(depth1);

sub2 = sub1;

if (sub1.getOri() == true)
{
    for (int i = 0; i < sub1.getLength(); i++)
    {
        popMap[sub1.getLocateY()][sub1.getLocateX() + i] = 1;
    }

}
if (sub1.getOri() == false)
{
    for (int i = 0; i < sub1.getLength(); i++)
    {
        popMap[sub1.getLocateY() - i][sub1.getLocateX()] = 1;
    }

}

srand(time(NULL));
int x = 10;
int y = 10;
Grid a(x, y);
a.random();
a.print();
cout << endl << endl;

for (int i = 0; i < 15; i++)
{
    strikeMap[listofX[i]][listofY[i]] = 1;

}
int die = 0;
for (int i = 0; i < 10; i++)
{
    cout << endl;
    for (int j = 0; j < 10; j++)
    {
        if (popMap[i][j] == 1)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
        if (strikeMap[i][j] == 1 && strikeMap[i][j] == popMap[i][j])
        {
            orientation = true;
            sub1.setHit(orientation);
            
            die++;
        }
    }
    
}
cout << endl << endl;
if (die == 0)
{
    cout << "topedos missed the target" << endl;

}
if (die != 0 && die != sub1.getLength())
{
    cout << "submarine has been hit" << endl;
}
if (die == sub1.getLength())
{
    cout << "submarine has sunk" << endl;
}

cout << endl << "Length of sub2: " << sub2.getLength() << endl;
cout << "Starting location of sub2: " << "(" << sub2.getLocateX() << "," << sub2.getLocateY() << ")" << endl;
cout << "Orientation of sub2: " << sub2.getOri() << endl;
cout << "Depth of sub2: " << sub2.getDepth() << endl;
return 0;
}