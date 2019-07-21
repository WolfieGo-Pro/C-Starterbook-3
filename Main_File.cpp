/*
  Practicing OOP - Classes, Constructors & Destructors, Accessors(Getters) & Mutators(Setters), Structs.
  Will deal with unions & enums user-defined types later
*/

#include "Includes/pch.h"

using namespace std;
using namespace my_vars;

int main() {

	

	Player_BP player;

	cout << ls3 << "What's ur name? : " << flush;

	string levi;
	cin >> levi; cout << endl; //hmmmm

	levi = player.get_user_name();
	

	/*

	cout << ls3 << "And how old are you? : " << flush;
	cin >> player.user_age; cout << endl;

	cout << ls3 << "Your gender? (type 'm' for male / 'f' for female) : " << flush;
	cin >> player.user_gender; cout << endl;

	

	switch (player.user_gender)
	{

	case 'm':
		//user_info.gender = true;
		cout << ls3 << "Okay" << endl;

	case 'f':
		//user_info.gender = false;
		cout << ls3 << "Right" << endl;

	default:
		cout << "Come on now" << endl;
		break;
	}

	cin.get();

	*/


};

