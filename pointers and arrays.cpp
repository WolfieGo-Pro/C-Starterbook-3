/*
  Iterating through the array using operator[] - not very efficient

  Iterating through the array using pointers :

  N.0
  A pointer variable must refer to either the address of an element, or
  to the array without the address sign, which points to the 1st element by default

  N.1
  The pointer knows it's pointing to a string, and knows the size of the 1st element,
  but doesn't know how many strings they are nor the size of the elements
  also, the pointer is the same as the array. That's why we can do this without using the '&' sign
  
  N.2
  Another way to iterate through an array with pointers is to mark 
  the beginning and end of the arrays with pointers (of course) and 
  check if they match with each other. In other words, if the beginning has reached the end

  By the way, this operator '[]' has a high precedence 
*/

#include "pch.h"

int main() {

	std::string stuff[]{ "Double", "Spectre", "House" }; // no need for '\0' - because I'm using string literals.

	std::cout << ls2 << stuff->size() << std::endl; // I noticed that '->size' or '.size' outputs the length of the 1st element
	std::cout << ls2 << sizeof(stuff) << std::endl; // outputs the size of the total elements in the array
	std::cout << ls2 << sizeof(stuff) / sizeof(std::string) << std::endl; // this gives us the no. of elements in the array
	std::cout << ls2 << "***********************************************" << std::endl;

	// Iterating through the array using operator[] - not very efficient
	for (int i = 0; i < sizeof(stuff) / sizeof(std::string); i++)
	{
		std::cout << ls2 << stuff[i] << " " << std::endl; // tried 'stuff.at(i)' but didn't work
	}

	std::string* p_stuff{ stuff }; // N.0 - N.1

	//p_stuff++; // increments the value the pointer refers to. (in this case, from the array). So "Spectre" will be outputed

	std::cout << ls2 << "The pointer points to the next element in the array, which is : " << *p_stuff << std::endl;
	std::cout << ls2 << "****************************************************************" << std::endl;

	//Better way of Iterating through the array using a pointer
	for (int j = 0; j < sizeof(stuff) / sizeof(std::string); j++, p_stuff++)
	{
		std::cout << ls2 << *p_stuff << " " << std::endl; // or p_stuff[j] . Tried 'p_stuff->at(j)' but didn't work

	}

	std::cout << ls2 << "****************************************************************" << std::endl;

	/*
	N.2.
	After doing this I felt like a BOSS
	*/
	std::string* start_element{ &stuff[0] }; // N.0 . Can also be written as std::string* start_element{ stuff };
	
	unsigned last_element{ sizeof(stuff) / sizeof(std::string) - 1 }; // To get the last element in the array as C++ counts from 0
							
	// Or, std::string* end_element { stuff[3] - stuff[0] }. Supposing we know how many elements there are.
	std::string* end_element{ &stuff[last_element] };

	std::cout << ls2 << "Start element : " << *start_element << std::endl;
	std::cout << ls2 << "End element : " << *end_element << std::endl;
	
	/*
	while (true) // Could have used a for loop. Prefer a for loop
	{
		std::cout << ls2 << *start_element << std::endl;

		if(start_element == end_element) {

		    break;
		}
		
		*start_element++;
	}
	*/

	
	do
	{

		std::cout << ls2 << *start_element << " " << std::endl;

		if (start_element == end_element) {
			break;
		}

		*start_element++;

	} while (start_element != end_element);
	

	return 0;
}