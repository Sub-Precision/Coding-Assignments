#pragma once
#include <string>
using namespace std;

class Game
{
private:
	string title;
	string release;
	int levels;
	double record;
public:
	enum platform
	{
		ps4,
		xb1,
		xb360,
		ps3,
		ps2,
		ps1,
		xbox,
		wii,
		wiiu,
		pc,
		mobile,
		handheld,
		other,
	};
	Game();
	Game(string, string, int, double);
	// Getters
	string getTitle() { return title; }
	string getRelease() { return release; }
	int getLevels() { return levels; }
	double getRecord() { return record; }

	// Setters
	void setTitle(string t) { title = t; }
	void setRelease(string rel) { release = rel; }
	void setLevels(int l) { levels = l; }
	void setRecord(double rec) { record = rec; }
	~Game();
};

