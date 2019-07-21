/*
  Practicing Accessors and Mutators - a.k.a Getters & Setters.
  Will end up using only the 'set method'.
  And eventually learn and use the 'this' keyword.
  There are some C++11 & C++17 syntax combination.

  This led me to battle with Input Validation for an entire day
  18/06/2019
*/

#include "Pch.h"

using namespace std; // Yes. Will keep doing this. Not 'std:: ..'

int main() {

	User_Info user1; //Class instantiation

	struct User{//To organize the variables in the main scope

		string u_name;
	};

	User info; //From Struct

	cout << ls3 << "What's your name? : " << flush; //Starting with the user's name

	cin >> info.u_name;

	cout << endl;

	//bool valid_input{ user1.set_user_name(info.u_name) }; //The 'bool' can be removed
	//bool valid_input{ cin.fail()}; //In case the user inputs garbage

	// Input Validation comes in. Would prefer it to be put in a function in a class. 

	bool invalid_input{ true };

	for (unsigned short i = 0; i < info.u_name.size(); i++) {// this type of validation works, but isn't efficient

		if (isalpha(info.u_name.at(i))) {

			user1.set_user_name(info.u_name); //The setter method kicks in.

			cout << ls3 << "Okay, " << info.u_name << ", here are the details --\0" << endl;
			cout << ls3 << user1.get_user_name() << endl;
			break;
		}

		else if (info.u_name == " " || invalid_input) { // In case the user inputs other stuff aside from strings and spaces

			cin.clear();

			cout << ls3 << "Please enter a Valid Name\0" << endl;

			continue;

		}

	}

	//cout << ls3 << "This is the next thing";

	//Proceeding to using regex.

};