/*
  My first dive into classes in C++ (OOP)

  C++ had extra extensions to make it Object Orientated.

  Methods (Related functions in a class) that represent/display the Models (characteristics/abilities/capabilities) of an Object
  through a method of linking data/variables with those functions == is my definition of a Class

  It's also a specification of custom made data types a.k.a Blueprint
  While an Object is an instance of that blueprint.
*/

#include "pch.h"

using namespace std;

int main()
{
	
	cout << ls3 << "Hi b!sh" << endl;




	{ // For constructor and deconstructor basis
		Character_Blueprint bullie; // Real 3D object/character

		cout << ls3; bullie.punch();
		cout << ls3; bullie.shoot();
	}

	return 0;

}