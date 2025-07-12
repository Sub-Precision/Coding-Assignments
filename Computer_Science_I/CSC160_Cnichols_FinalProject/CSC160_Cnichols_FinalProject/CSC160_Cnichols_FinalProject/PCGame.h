#pragma once
#include "Game.h"

using namespace std;
class PCGame :
	public Game
{
private:
	string version;
public:
	PCGame();
	PCGame(string, string, int, double, string);
	~PCGame();

	string getVersion() { return version; }
	void setVersion(string v) { version = v; }
};

