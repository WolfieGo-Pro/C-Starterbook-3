/*
String streams - Concatenating disparate values of different data types
				 into one string data/variable.

				 20/06/2019

It's like classes & structs, meaning that 'stringstream' is a class.
Which also means that an object (string object in this case), has to be 
instantiated from the class.

We can then input words, characters and spaces into the string object
using the insertion operator (<<), append 'str()' to the string object
and do what we want with it - like we would with a normal string value.

Up next, converting string and int inputs to char[] or just char
*/

#include "Pch.h"

using namespace std;

int sstream() {

	struct Info
	{
		string name{ "" };

		unsigned short age{0};
	};

	Info user1;

	user1 = { "Fish", 19 };

	stringstream details; // Same as classes and structs. You instantiate a string object from the class

	details << "Name : " << user1.name; // Feed data into the string object 'details'
	details << ", Age : " << user1.age;

	string user_details{ details.str() }; //The '.str()' method of string stream converts the objects to actual strings of texts.
	//Imagine what 'substr()' does

	cout << ls2 << user_details;
	cout << ls2 << "Length of string object : " << user_details.length() << endl; //The spaces are counted and put as part of the string object
	cout << ls2 << "Size of string object : " << sizeof(user_details);

	user_details.clear();

	cout << ls2 << user_details;
	cout << ls2 << "Length of string object (after details have been cleared) : " << user_details.length() << endl;
	cout << ls2 << "Size of string object (after details have been cleared) : " << sizeof(user_details); // Noticed that the 'size of' user_details remained the same

	return 0;
}