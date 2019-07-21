/*
  Reversing strings & other data types in arrays without making a copy of them.
  Of course, pointers are gonna be involved. (they don't necessarily need to be though),
  and I could have just reversed variables with arrays. (But that'll require copying data).
*/

#include "pch.h"

int main() {

	std::cout << "Let's reverse a double." << std::endl;

	double decs[]{ 18.5, 21.25, 19.75 };

	double* p_first_element{ &decs[0] };

	unsigned end_position{ sizeof(decs) / sizeof(double) - 1 };

	double* p_last_element{ &decs[end_position] };

	std::cout << "Checking if the pointers point to the 1st & last elements :-" << std::endl;
	std::cout << "First element " << *p_first_element << std::endl;
	std::cout << "Last element " << *p_last_element << std::endl;

	//reversing the doubles, from last to 1st

	while (p_first_element <= p_last_element) {

		std::cout << *p_last_element << std::endl;

		*p_last_element--;
	}

	// Lets reverse strings.( c-type strings)

	/*
	Tried using struct but didn't allow me to leave
	the space in the brackets of the char variable empty.

	struct User
	{


	};
	*/

	char user_name[]{ "Who are you" };

	char* p_first_character{ &user_name[0] };

	unsigned end_character{ sizeof(user_name) - 2 }; //subtracts the \0 terminator & because C++ counts fom 0

	char* p_last_character{ &user_name[end_character] };

	/*
	std::cout << user_name << std::endl;
	std::cout << "What's your first name? (must be less than 12 characters) : " << std::flush;
	std::cin >> user_name;
	std::cout << std::endl;
	*/

	std::cout << "Checking if the pointers point to the 1st & last characters..." << std::endl;
	std::cout << "First character " << *p_first_character << std::endl;
	std::cout << "Last character " << *p_last_character << std::endl;

	//Preferred way of reversing a variable
	while (p_first_character <= p_last_character) {

		std::cout << *p_last_character << std::flush;

		*p_last_character--;
	}
	std::cout << std::endl;
	std::cout << "**************" << std::endl;

	//with swapping. Doesn't work
	std::cout << "By swapping :-" << std::endl;

	while (p_first_character < p_last_character) {

		char save = *p_first_character; // saving the pointer to 1st character

		*p_first_character = *p_last_character; // pointing last character to 1st character

		*p_last_character = save; // saving the pointer to last character

		p_first_character++;
		p_last_character--;
	}
	std::cout << user_name << std::endl;


	return 0;
}