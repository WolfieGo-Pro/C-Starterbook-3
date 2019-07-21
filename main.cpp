/*
  Practising the use of pointers in cpp
  which stores the memory address of variables & objects.

  De-referencing the pointer involves typing an asterisk (*) before the pointer variable which 
  gives us the value that the pointer refers to.

*/

#include "pch.h"

short random(short* random_number) {

	//This function receives the value that a pointer to a 'short' refers to,
	//Meaning that the 'short' variable gets passed by reference

	*random_number = 25;

	//std::cout << "Random number after passed by reference : " << *random_number << std::endl; // couts 25

	return *random_number;
}
/*
void casual(const std::string& casoname) {

	// This function receives the memory address of a string variable,
	// meaning that the string variable in the main scope gets passed by value

	std::cout << "In function : " << std::endl; // didn't cout anything;
/*
	I've noticed that passing variables/objects by memory address from the function won't work
	As there's nothing left to do with the address in the function.
	Passing variables/objects from the function by pointers will work.
	As you can later de-reference the pointer to provide the real value which can be worked with.

	This all means that, passing a variable/object from the main scope or any other scope, should be done
	by passing its memory address. Of course their exceptions.

}; 
*/

void bb(std::string* p_bby) {

	*p_bby = "fabulo";

	std::cout << "Word after been passed in function : " << *p_bby << std::endl;

}

int pointers() {

	short value{ 5 };

	std::cout << "Int (Short) value : " << value << std::endl;

	short* p{ &value }; // This stores the address of 'short' (can be any data type). A value of type 'short' cannot be used to initialize an entity of type 'int'
	//Pointer to a 'short' equals the (memory) address of 'value
	std::cout << "Pointer to 'short' address " << p << std::endl;

	value /= 5; // This proves that the pointer updates with the address ( of course- since a pointer shows the (memory) address)

	std::cout << "Value from pointer : " << *p << std::endl; // 
	std::cout << "------------------------------------------" << std::endl;

	short random_number{ 13};

	std::cout << "Random number from 'main' scope before passing to function: " << random_number << std::endl;

	random(&random_number); // Passing value to a function by reference 

	std::cout << "Random number from 'main' scope after passing to function : " << random_number << std::endl; // couts 25 . Of course - value passed and updated by reference
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

	std::string casname{ "yubo" };

	std::cout << "Casual name before passing : " << casname << std::endl;
	
	std::string casual(casname); // Passing a variable to a function by value. Meaning the function receiving this won't do much with it as it will receive the memory address

	std::cout << "Casual name after passing : " << casname << std::endl;  // 
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;

	std::string bby{ "buffalo" };

	std::cout << "Word before passing : " << bby << std::endl;

	bb(&bby);

	return 0;
}