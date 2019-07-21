/*
  N. == 'Note';
  
  This is all about manipulating/mutating data in a variable through
  another variable. Which means pointers don't need to be involved.
  
  Using '&' before the variable to mutate, the memory address
  can be stored in another variable.

  N.1
  Regarding pointers, you mutate a value by de-referencing.

  N.2
  Regarding references, you mutate a value by equating 
  the value to the memory address of another variable of the same type, 
  then altering that other variable.
  In other words, create a reference (because it's not actually a variable, but a reference).
  
  short a {15};
  short &b {a}; 'b' is now a reference to 'a'. It can now only act as a synonym for the existing variable, a .
  b = 20;
  Now, a , b = 20

  N.3
  When functions/methods are involved, you can "pass values by reference".
  This is done by making the function accept the memory address 
  of a variable (a.k.a reference), of the same type as the variable declared in the main scope.
  This works because the parameters in the function is a reference to
  an already existing variable.
 */

#include "pch.h"

// N.1
short change_value(short * some_value) {// this function only accepts pointers.

	*(some_value) = 24; //putting in parenthesis so that the compiler will allocate 24 to 'some_value' before de-referencing

	std::cout << *some_value << std::endl;

	return *some_value; // But returning the de-referenced variable is required
}

void set_mojo(std::string & mojo) {// N.3

	mojo = "Blojo. " "This is me.";

}

std::string set_name(std::string& name) {

	name = "Boliki"; // No need to de-reference as I'm not passing a pointer, but a reference.

	return name;
}

int main() {

	// N.1
	short some_value{ 19 };

	short* p_some_value{ &some_value };

	change_value(p_some_value); // argument must be either a pointer varable or memory address of a variable/object

	std::cout << *p_some_value << std::endl;
	std::cout << "***********************" << std::endl;


	std::string mojo{ "dojo" };

	set_mojo(mojo); // argument must be the exact variable since the function only accepts the mem. address of a variable/object

	std::cout << "Strings : " << mojo << std::endl;
	std::cout << "***********************" << std::endl;


	// N.2
	short nonce{ 12 };

	short& nonce2 = nonce;

	nonce2 = 15;

	// Both will output 15. Because their memory address are equal to each other and is now, = 15.
	std::cout << "Nonce : " << nonce << std::endl;
	std::cout << "Nonce 2 : " << nonce2 << std::endl;


	std::cout << "What's your name? : " << std::flush;

	std::string name;
	std::cin >> name;
	std::cout << std::endl;

	set_name(name);

	std::cout << "Ha! , changed your name to " << name << std::endl;
	std::cout << "Wanna know how? (y/n) : " << std::flush;

	char answer;
	std::cin >> answer;
	std::cout << std::endl;

	while (true) {// Didn't have to. The conditional expressions are enough

		if (answer == 'y') {

			std::cout << "Simple, I passed your name by reference to a function that accepts " << std::endl;
			std::cout << "the memory address of a variable or object. In this case, your name." << std::endl;
			std::cout << "Then I changed it to a name that sounds like you're from a country in Africa. lol" << std::endl;
			std::cout << "They're 2 other ways of doing this, but this method is preferred by most devs." << std::endl;

			break;
		}
		else {

			std::cout << "Damn, okay." << std::endl;

			exit(2);
		}
	}


	return 0;
};