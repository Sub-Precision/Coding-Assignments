#pragma once
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

Game::Game()
{
	cout << "Constructing " << title << " " << levels << " " << record << endl;
}


Game::Game(string, string, int, double)
{
	cout << "Constructing " << title << " " << release << " " << levels << " " << record << endl;
}

Game::~Game()
{
	cout << "Destructing " << title << " " << levels << " " << record << endl;
}


