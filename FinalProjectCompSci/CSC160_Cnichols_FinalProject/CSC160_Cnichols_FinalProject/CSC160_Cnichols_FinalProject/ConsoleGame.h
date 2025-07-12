#pragma once
#include "Game.h"

using namespace std;
class ConsoleGame :
	public Game
{
private:
	string console;
public:
	ConsoleGame();
	ConsoleGame(string title, string release, int levels, double record, string console);
	~ConsoleGame();

	string getConsole() { return console; }
	void setConsole(string c) { console = c; }
};

