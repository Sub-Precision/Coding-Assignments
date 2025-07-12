#pragma once
#include "ConsoleGame.h"
#include "Game.h"
#include <string>
#include <iostream>
using namespace std;


ConsoleGame::ConsoleGame()
{
	cout << "Constructing" << " " << console << endl;;
}

ConsoleGame::ConsoleGame(string title, string release, int levels, double record, string console)
	: Game(title, release, levels, record)
{
	cout << "Constructing" << " " << title << " " << levels << " " << record << " " << console << endl;
}

ConsoleGame::~ConsoleGame()
{
	cout << "Destructing" << " " << console << endl;
}
