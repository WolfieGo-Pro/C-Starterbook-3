// Checking if a struct can be used instead of a class.
// The compiler gave warnings.

#include "pch.h"

struct Book {

protected:
	short thickness{ 0 };

public:
	Book();

	//Book(short thickness);

	Book(const Book& object) : thickness(object.thickness) {}; // copy constructor

	short set_thickness(short thickness) { this->thickness = thickness; return thickness; };

	void info() { std::cout << thickness << std::endl; };
};

int xtra_code() {

	Book new_book1;

	new_book1.set_thickness(12);

	std::cout << "Thickness for Book 1 is : "; new_book1.info();

	Book new_book2(new_book1); //copy constructor has been initialized

	std::cout << "Thickness for Book 2 is : "; new_book2.info(); 

	Book new_book3(new_book2);

	new_book3.set_thickness(45);

	std::cout << "Thickness for Book 3 is different : "; new_book3.info();

	exit(2);
	return 0;
}