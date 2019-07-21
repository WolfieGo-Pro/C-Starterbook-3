/*
Practising with chars & strings.

N.1
I've noticed that when a char array is declared & initialized,
if a user's input is allocated to the char array, it (the user's input)
must be <= the no. of characters initially set when declaring the char array.
Else, an exception will be thrown - error.
Which makes it easy for us to validate input - try, catch & throw.

Again, don't wanna be using [] operator, but no other replacement for now so..
*/

#include "pch.h"

int main() {

	char user_input[] = "none";
	//char* p_input{ user_input }; // same as char * p_input {user_input[0]};

	std::cout << "Enter name : " << std::flush;

	std::cin >> user_input; // since the char array has a 4-letter-word, the user's input has to be a 4-letter-word as well.
							// so we don't need to 'setw()' for this.

	for (short i{ 0 }; i < sizeof(user_input); i++) {

		std::cout << i << " : " << user_input[i] << std::endl; // prints 5 times because of N.1 & because c++ starts from 0
	
	}

	// MY PREFERRED METHOD OF ITERATING AND VALIDATING THROUGH A CHAR ARRAY

	/*
	std::cin.clear();
	std::cout << "Enter again : " << std::flush;
	std::cin >> user_input;
	std::cout << std::endl;

	for (short j = 0; j < sizeof(user_input); j++)
	{
		if (isdigit(user_input[j])) {

			std::cin.clear();
			std::cin.ignore(1000, '\n');

			std::cout << "No man, try again : " << std::flush;
			
			std::cin >> user_input;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Alright" << std::endl;
			break;
		}
	}
	*/
	
	short w{ 0 };
	short* p_w{ &w };

	// checking if a char array contains only letters. Doesn't work well like a for loop
		
	do
	{
		if (isalpha(user_input[*p_w])) {

			*p_w++; // iterate through the char array

			if (user_input[*p_w] == 0) { //if at the end of the char array
				std::cout << "Okay, these are all alphabets" << std::endl;

				break;
			}

		}
		else {

			// could have done this another way with less code
			std::cin.clear();

			std::cout << "Enter name : " << std::flush;

			std::cin >> user_input;
			std::cout << std::endl;
		}

	} while (true);
	
	// Iterating through a char array w/ do-while loop
	do
	{
		std::cout << user_input << std::endl;
		
		// To break out of the iterations
		if (user_input[*p_w] == 0) {
			break;
		}

		*p_w++;
		
	} while (true);
	
	return 0;
}