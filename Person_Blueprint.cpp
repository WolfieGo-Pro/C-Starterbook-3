#include "Pch.h"

/*
Person_Blueprint::Person_Blueprint(unsigned short new_age)
{
	unsigned short age{ 0 };
}
*/
/*
Person_Blueprint::Person_Blueprint(bool new_gender)
{
	bool gender{ true };
}
*/

Person_Blueprint::Person_Blueprint() {

	unsigned short age = 0; 
	
	std::string gender{ "Male" }; 
	
	std::string name{ "undefined" };

	double some_decimal;

};// Default constructor

Person_Blueprint::Person_Blueprint(unsigned short age, std::string name, std::string gender) {
	
	this->age = age;  this->name = name; this->gender = gender; 

	std::cout << "Memory Location : " << this << std::endl; // 'this' , also holds the memory address of each instantiated object
}
; // Inline . Prefer this method of initializing data members in a constructor (after input validation) & perhaps other stuff

/*
Person_Blueprint::Person_Blueprint(std::string new_name, std::string new_gender) {
	
	// From here you can set input validation code before allocating values to data members
	// That's why I don't like setting Inline constructors or methods
	// Thought that only getters & setters can do that, but now I know

	name = new_name; gender = new_gender;

};
*/

std::string Person_Blueprint::all_data_to_string() {

	std::stringstream all;

	// risky, as we're exposing our data members.
	// would have used getters (mutators).

	all << "So, you're " << age;
	all << ", your name is " << name;
	all << ", and you are a " << gender;

	std::string all_details = all.str();

	return all_details;
}


Person_Blueprint::~Person_Blueprint() { 
	
	std::cout << "Fair Well";
}

double Person_Blueprint::set_some_decimal(double some_decimal)
{
	if (std::cin >> some_decimal) {

		this->some_decimal = some_decimal;
	}
	else {

		std::cout << "Please enter a valid decimal";

		return 0.0;
	}
	return some_decimal;
}
