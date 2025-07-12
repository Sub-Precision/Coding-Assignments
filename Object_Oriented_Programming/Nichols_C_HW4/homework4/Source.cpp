#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

#define PORTION 6.6
#define SIZE 10

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
    //Constructors
    WaterVehicle();
    WaterVehicle(int, int, int, bool, bool, bool)

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
    public WaterVehicle;
{
private:
    int depth;
    bool surf;
public:
    Submarine();
    Submarine(int, int, int, bool, bool, bool, int, bool);
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
}

int main()
{
    srand(time(NULL));
    int x = 10;
    int y = 10;
    Grid a(x, y);
    a.random();
    a.print();
}