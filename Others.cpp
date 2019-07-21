/*
  Other things to know when dealing with string streams.

  String streams can be used to validate user input (numeric/alphabetic)
*/

#include "Pch.h"

using namespace std;

int main() {

	struct Info
	{
		string name{ "" };

		unsigned short age{ 0 };
	};

	Info user1;

	cout << ls2 << "Enter your name : " << flush;

	getline(cin, user1.name); cout << endl; // Using this method for getting long strings of text. Otherwise, 'cin >> ...'

	cout << ls2 << "Enter your age : " << flush;

	cin >> user1.age; cout << endl;

	stringstream details; //Could have done 'stringstream details(user1.name, user1.age);' but nah, bcuz integrs won't output

	details << user1.name << ", " << user1.age;

	string all{ details.str() };
	
	cout << ls2 << all;
	
	for (unsigned i{ 0 }; i < all.length(); i++) { //Extracting strings of text as an array by looping through each character

		//cout << ls2 << all[i];

		char boom{ all.at(i) }; // char boom {all[i]};

		//cout << ls2 << boom;
	}

	/*
	unsigned i{ 0 };
	while (i < all.length())
	{

		char boom{ all.at(i) }; // char boom {all[i]};

		cout << ls2 << boom;
	}
	*/
	








}