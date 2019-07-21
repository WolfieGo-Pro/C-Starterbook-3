#pragma once
class Person_Blueprint
{
private:

	unsigned short age;

	std::string name, gender;

	double some_decimal;

public:

	// Three different constructors from the same class blueprint

	Person_Blueprint(std::string name) : name(name) {}; // Another Inline method. Can be done normally. Also, it's better passing strings using pointers
	Person_Blueprint(unsigned short new_age) { age = new_age; }; // Inline. I prefer passing an input validation method as a parameter
	Person_Blueprint(std::string new_name, std::string new_gender) { name = new_name; gender = new_gender; }; // Inline

	Person_Blueprint(unsigned short age, std::string new_name, std::string gender); //{ this->age = age;  this->name = new_name; this->gender = gender; }; // Inline

	Person_Blueprint(); // Default constructor
	~Person_Blueprint();

	double set_some_decimal(double some_decimal);
	double get_some_decimal() { return some_decimal; }; // Inline because I just want the method to return a data member

	std::string all_data_to_string(); // To parse all values to a string. Not important for this topic

	//unsigned short get_age(unsigned short new_age);
};