/*
  (It's actually the 'new' & 'delete' operators)
  
  Essentially, the 'new' operator enables me to instantiate an object from
  a class with a pointer on the heap memory.
  
  stack < heap

  Using parenthesis '()' around an object/variable/pointer gets C++ to
  read the value in the parenthesis 1st. As it carries a high precedence
  (higher than the '*' operator). (doesn't work with MSVC++ compiler any more, which is good)
  But, instead of using that, we can simply use '->' when using pointers
  to point to objects.

  The delete operator de-allocates memory occupied by the pointers and calls the destructor (if there's any).
  Or it just de-allocates memory for non-class/struct data types (e.g int, char, std::string).

  If enough memory is not available in the heap to allocate, the new request indicates failure by 
  throwing an exception of type std::bad_alloc. But I like to use 'std::nothrow' so that if it fails 
  to allocate memory, it returns a NULL pointer.

  It's also important to store results of pointer operands in a 'long' int data type.

  Now, returning objects from functions/methods (we defintely wanna use new & delete operators for this one)
  so we don't end up returning objects/variables that won't exist once the compiler goes out of scope.
*/

#include "pch.h"

// this function is only here for me to practice returning objects from functions using pointers (i.e using 'new').
Animal *set_lifespan(double lifespan) {

	Animal *set_lifespan = new(std::nothrow) Animal(lifespan);

	if (!set_lifespan) {
		
		std::cout << "Couldn't allocate memory\n";
		
		return nullptr;
	}
	else {
		return set_lifespan;
	}
	
}

int main() {


	Animal* p_animal1{ new Animal() }; // object instantiated/created, and constructor called.

	p_animal1->set_animal_age(3);

	p_animal1->set_animal_name("Bitsy");

	p_animal1->animal_info();

	Animal& ref_animal1 = *p_animal1; // reference to a de-referenced pointer that points to an object.

	ref_animal1.set_animal_name("Gringo"); // using the reference value to change data that a pointer points to.

	std::cout << "**********************************************" << std::endl;

	char* char_array = new(std::nothrow) char[5];

	if (char_array) {

		std::cout << "Succeeded to allocate memory to char[5]\n";
	}
	else {

		std::cout << "Failed to allocate memory to char[5]\n";

	}
	delete[] char_array; // How you made the array is how you must delete the array.

	std::cout << "**********************************************" << std::endl;

	Animal* p_animal3 = new Animal(*p_animal1); // object dynamically instantiated/created on the heap, and copy constructor called.

	p_animal3->set_animal_age(16);

	p_animal3->animal_info();

	std::cout << "**********************************************" << std::endl;

	std::cout << "Size of Both pointers = " << sizeof(p_animal1) + sizeof(p_animal3) << std::endl;

	delete(p_animal1);

	std::cout << "Copied "; delete(p_animal3); // Alternatively, Animal* p_animal3 = NULL;

	std::cout << "**********************************************" << std::endl;

	// created a function that returns a pointer to an object (by calling a constructor).
	Animal* p_lifespan = set_lifespan(8.4); //you may not see 'new' here, but is in the 'set_lifespan' function

	p_lifespan->get_lifespan();

	delete p_lifespan;

	std::cout << "**********************************************" << std::endl;

	// just instantiating a lot of objects by using pointers to point to array objects
	Animal* p_animal{ new Animal[5] };

	p_animal[3] = Animal(12);

	p_animal[4].set_animal_age(3);
	p_animal[4].animal_info();

	delete[] p_animal;


	char alp{ 'a' };
	char& ref_alp{ alp };
	ref_alp++;
	std::string buff(5, ref_alp);
	std::cout << buff << std::endl;
	

	char *p_mem{ new char[10] };

	delete[](p_mem);

	std::cout << "******************************************" << std::endl;

	// Object Arrays

	Animal* p_animals{ new Animal[27] };

	char names{ 65 }; // So that we don't get that C4458 (Level 4) warning of identical identifiers
	
	// iterating through objects in arrays whilst setting and outputting the object's names
	for (unsigned short i = 1; i < 27; i++, names++)
	{
		p_animals[i].set_name(names);
		std::cout << "Object " << i << "'s name is "; p_animals[i].output_name();
		
		std::cout << "************************" << std::endl;
	};
	
	delete[](p_animal);



	exit(2);
	return 0;
}

/*

  'new is all about using pointers to create objects from a class.
  Meaning, we can use it to copy data members from one object to another,
  which invokes the copy constructor.

  Animal* p_animal0 = new Animal();

  Animal* p_animal1 = new Animal(*animal0);
*/