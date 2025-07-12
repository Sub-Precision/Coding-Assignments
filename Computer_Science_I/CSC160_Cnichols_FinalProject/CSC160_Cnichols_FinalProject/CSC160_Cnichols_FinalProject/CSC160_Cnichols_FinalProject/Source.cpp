// Speed runner Calculator final project by Cade Nichols

#include "Time.h"
#include "Game.h"
#include "ConsoleGame.h"
#include "PCGame.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

// Creating Game object
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

// Function prototypes
void menu();
Game getInfo();
string getPlatform(platform);
int* arrayAllocator(int);

// Declaring file arrays and variables
string titles[99];
string releases[99];
string consoles[99];
int lines;

int main()
{
	while (true)
	{
		menu();
		
		// Declaring variables
		int choice;
		int *pointer = nullptr;

		// Getting user choice
		
		cout << "What would you like to do?: ";
		cin >> choice;
		cout << endl;

		// Evaluating user choice
		if (choice == 1)
		{
			Game newGame;
			platform game;
			newGame = getInfo();
			if (game = pc)
			{
				string version;
				cout << "Game version: ";
				cin >> version;
			}
			
		}
		else if (choice == 2)
		{
			// Declaring variables
			string titles;
			string releases;
			int level;
			double records;
			string versions;
			string consoles;
			ifstream infile;

			// Exception handling of a lack of file
			try
			{
				infile.open("Library.txt");
			}
			catch (exception e)
			{
				cout << "No file found";
				// Terminate program
				return 0;
			}

			// Dynamic array variables
			int lines;
			string line;

			// loop to get number of lines in the file
			while (!infile.eof())
			{
				getline(infile, line);
				cout << line << endl;
				lines++;
			}
			pointer = arrayAllocator(lines);

			// reads file line by line
			for (int i = 0; i < lines; i++)
			{
				infile >> titles >> releases >> consoles;
			}
			
			infile.close();
			// Deallocate the array
			delete[] pointer;
			pointer = nullptr;

		}

		else if (choice == 7)
		{
			cout << "Thank you for releasing me.";
			return 0;
		}
	}
}
Game getInfo()
{
	string title;
	string release;
	int levels;
	Game newGame;
	platform plat = other;
	string console;
	cout << endl << "Name of Game: ";
	cin >> title;
	cout << endl << "Release Date: ";
	cin >> release;
	cout << endl << "Number of levels: ";
	cin >> levels;
	console = getPlatform(plat);
	ofstream outfile;
	outfile.open("Library.txt");
	outfile << title << " " << release << " " << levels << " " << 0.0;
	if (plat = pc)
	{
		string version;
		cout << "Game version: ";
		cin >> version;
		Game newGame = PCGame(title, release, levels, 0.0, version);
		outfile << version;
	}
	else
	{
		Game newGame = ConsoleGame(title, release, levels, 0.0, console);
		outfile << console;
	}

	outfile.close();
	return newGame;
}
string getPlatform(platform plat)
{
	string newPlat;
	cout << endl << "Platform Initials(lowercase): ";
	cin >> newPlat;
	if (newPlat == "ps4")
	{
		plat = ps4;
		return newPlat;
	}
	else if (newPlat == "xb1")
	{
		plat = xb1;
		return newPlat;
	}
	else if (newPlat == "xb360")
	{
		plat = xb360;
		return newPlat;
	}
	else if (newPlat == "ps3")
	{
		plat = ps3;
		return newPlat;
	}
	else if (newPlat == "ps2")
	{
		plat = ps2;
		return newPlat;
	}
	else if (newPlat == "ps1")
	{
		plat = ps1;
		return newPlat;
	}
	else if (newPlat == "xbox")
	{
		plat = xbox;
		return newPlat;
	}
	else if (newPlat == "wii")
	{
		plat = wii;
		return newPlat;
	}
	else if (newPlat == "wiiu")
	{
		plat = wiiu;
		return newPlat;
	}
	else if (newPlat == "pc")
	{
		plat = pc;
		return newPlat;
	}
	else if (newPlat == "mobile")
	{
		plat = mobile;
		return newPlat;
	}
	else if (newPlat == "handheld")
	{
		plat = handheld;
		return newPlat;
	}
	else
	{
		plat = other;
		return newPlat;
	}
}

void menu()
{
	// Printing the menu
	cout << "| -      -     -    -   -  - -|" << endl;
	cout << "| The Speed Runner Calculator |" << endl;
	cout << "1. New Game" << endl;
	cout << "2. Play Game" << endl;
	cout << "3. Vs Mode" << endl;
	cout << "4. Options" << endl;
	cout << "5. Edit Games" << endl;
	cout << "6. Display Library" << endl;
	cout << "7. Quit" << endl;
}

int* arrayAllocator(int num)
{
	int* arrPtr = nullptr;

	// Allocate space for the array
	arrPtr = new int[num];

	// Return the address of the allocated memory
	return arrPtr;
	cout << "";
	return 0;
}
