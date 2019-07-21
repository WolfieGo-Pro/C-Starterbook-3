/*
  Copy constructors is a default constructors of the 2nd instantiated object
  from the same class.
  In other words, it creates a clone of the only constructor in the class
  when we instantiate another object from the same class and
  equate it to the 1st instantiated object.


  Even though there's a default constructor, the 2nd instantiated object
  will obtain settings/values from the 1st instantiated object. (Unless a particular
  constructor that accepts certain arguments is made).

  Hence, it's important to explicitly specify/overwrite the copy constructor in your class.
  And as far as syntax is concerned, explicitly specifying the copy constructor shows the template/
  particular order an object is copied to another object. Making it seem like we're passing objects by reference,
  which we're.

  The 'const' in the copy constructor means we can't change the reference object we're passing.
  It also means we can't call any methods on the reference object that aren't declared as const.

  I used the constructor initializer list method in initializing constructors because I preferred it.

  In terms of copy constructors,
  '=' is an operator that's implicitly defined for objects. Usually used for calling objects.
  '()' enables us to just use the copy constructor directly.

  And the compiler gave warnings with this code.
*/

#include "pch.h"

class Book {
private:
	unsigned no_of_pages;
	short length, breadth, height, depth;

public:
	Book() : no_of_pages(no_of_pages) { std::cout << "Book created. There are Pages in this book." << std::endl; };

	Book(const Book& object) : no_of_pages(object.no_of_pages) { std::cout << "Book created by copying." << std::endl; }; // copy constructor

	void set_no_of_pages(unsigned no_of_pages) { this->no_of_pages = no_of_pages; /*return no_of_pages;*/ };

	void book_info() const { std::cout << "No of pages for this book is : " << no_of_pages << std::endl; };
};

int main() {

	Book book1;

	book1.set_no_of_pages(50);

	std::cout << "Book 1 : "; book1.book_info(); //outputs 50
	
	Book book2(book1); // at this point we're initializing & invoking the copy constructor. In other words, passing objects by reference. 

	std::cout << "Book 2 : "; book2.book_info(); //outputs 50 as well.

	book2.set_no_of_pages(100); // now, no_of_pages for book2 object is 100, no longer 50. So, we've override the value from book1.

	std::cout << "UPDATE - Book 2 : "; book2.book_info(); //outputs 50 as well.




	exit(2);
	return 0;
};