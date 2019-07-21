/*
  The keyword 'const' essentially, Keep things (variables/functions/methods) from mutating (changing).
  They can be uppercase or lowercase.

  When using pointers with const, the place the 'const' is used
  (in terms of declaring & initializing variables/functions/methods), determines whether 
  the pointer can be modified to point to another location or if it can be de-referenced and point to
  another value.

  How to know this? - Read backwards (from the right hand side).
  N.1 - meaning we can't change the pointer variable to point to another location 
  N.2 - meaning we can't de-reference and change the value.
*/

#include "pch.h"

class Pencil {// Could have just used a struct instead.

private:
	short length, width;

protected:
	short radius; // Not important.

public:
	void set_length(short length) { this->length = length; };

	const void info() const { std::cout << "Length of pencil is : " << length << "m" << std::endl; }; //'const' here reduces bugs
};


int main() {

	const auto PI { 3.1456 }; // because this value is const, the rest associated with this value has to be const as well.
	
	const double& ref_pi = PI;

	const double* p_PI{ &ref_pi }; // Pointing to the reference of Pi. It Means 'pointer to a double is constant'
	
								   //double* const p_PI{ &ref_pi }; // It Means 'const pointer to a double'. N.1
	
								   //const double* const p_PI{ &ref_pi }; // It means 'const pointer to a double that's const'. N.2
	
	double other_pi = 12.5; 
	
	p_PI = &other_pi; // const pointers can still point to mem. address of another variable.

	bool greater{ *p_PI > 3.14 }; // 'greater' is true when other_pi > 3.14
	
	if (!greater) {

		std::cout << "Pi is less than 3.14." << std::endl;
	}

	std::cout << "Pointer to PI is now : " << other_pi << std::endl;
	std::cout << "Okay, Pi is def greater than 3.14." << std::endl;
	std::cout << "**********************************" << std::endl;


	Pencil pencil;

	pencil.set_length(18);
	pencil.info();



	exit(0);
	return 0;
}