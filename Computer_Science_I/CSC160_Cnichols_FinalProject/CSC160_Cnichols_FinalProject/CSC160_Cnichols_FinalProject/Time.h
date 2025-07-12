#pragma once
using namespace std;

class Time
{
private:
	int mill;
	int sec;
	int minute;
	int hr;
	int day;
public:
	Time();
	Time(int);
	Time(int, int);
	Time(int, int, int);
	Time(int, int, int, int);
	Time(int, int, int, int, int);
	~Time();

	int getMill() { return mill; }
	int getSec() { return sec; }
	int getMin() { return minute; }
	int getHr() { return hr; }
	int getD() { return day; }

	void setMill(int mil) { mill = mil; }
	void setSec(int s) { sec = s; }
	void setMin(int min) { min = min; }
	void setHr(int h) { hr = h; }
	void setDay(int d) { day = d; }
};

