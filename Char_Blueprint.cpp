#include "pch.h"

/*
  I'm using a made-up model/blueprint of 3D characters to practice the use of classes
*/

using namespace std;

Character_Blueprint::Character_Blueprint()
{
	ghost = { false }; // Tried the C++17 syntax, but didn't work i.e ghost {false};
}

Character_Blueprint::~Character_Blueprint()
{
	cout << ls3 << "H E L P!!" << endl;
}


void Character_Blueprint::punch() {

	cout << "bjz-bjz-bjz" << endl;

	if (ghost)
	{
		cout << "This player is dead" << endl;
	}
	else
	{
		cout << "This player is about to die - revive him" << endl;
	}
	
};

void Character_Blueprint::jump() {

	cout << "fjuuum" << endl;
};

void Character_Blueprint::fly() {

	cout << "fiiiu-sshh" << endl;
};

void Character_Blueprint::shoot() {

	cout << "Pow-pow" << endl;
};

void Character_Blueprint::stance() {

	cout << endl;
};