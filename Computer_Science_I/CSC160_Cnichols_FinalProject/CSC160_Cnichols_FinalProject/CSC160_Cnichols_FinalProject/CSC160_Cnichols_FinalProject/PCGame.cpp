#pragma once
#include "PCGame.h"
#include <iostream>



PCGame::PCGame()
{
	cout << "Constructing " << version << endl;
}
PCGame::PCGame(string title, string release, int levels, double record, string version)
	: Game(title, release, levels, record)
{
	cout << "Constructing " << title << " " << release << " " << levels << " " << record << " " << version;
}


PCGame::~PCGame()
{
}
