// Main-entry for code practice

#include <iostream>
#include <exception>
#include <stdexcept>
#include <memory.h>
//#include "Exception_Handling.h"

struct Cup {

	std::string cup_name;

	short radius, height;
	short bevel_amount, thickness;

	//explicit Cup() {}

	void get_user_cup_details();
	
}cup;

void Cup::get_user_cup_details() {

	std::cout << "Name of cup ? : ";
	std::cin >> cup.cup_name; std::cout << std::endl;
	
	if (cup.cup_name.length() < 2 || cup.cup_name.length() > 20)
		throw std::length_error("invalid name length for cup");
	
	std::cout << "Height of cup ? : ";
	std::cin >> cup.height; std::cout << std::endl;

	if (cup.height > 40)
		throw std::domain_error("Height of cup is too long.\n");

	std::cout << "Radius of cup ? : ";
	std::cin >> cup.radius; std::cout << std::endl;

	if (cup.radius > 40)
		throw std::invalid_argument("Cup width is too big.\n");

	std::cout << "Bevel amount of cup ? : ";
	std::cin >> cup.bevel_amount; std::cout << std::endl;

	if (cup.bevel_amount > 10)
		throw std::invalid_argument("Bevel amount is too high.\n");

	std::cout << "Thickness of cup ? : ";
	std::cin >> cup.thickness; std::cout << std::endl;
	if (cup.thickness > 5)
		throw std::invalid_argument("Cup is too thick.\n");

}

int cups() {
	
	std::wcout << "Hello, please describe your cup for us \n" << std::endl;

	try {

		cup.get_user_cup_details();

	}
	catch (const std::exception& e) {

		std::cerr << " An error occurred. " << e.what() << std::endl;

		//return -1;
	}
	catch (...) {

		std::cerr << "Unknown error." << std::endl;
	}
	
	std::wcout << "Moving on..." << std::endl;

	return 0;
}



/*
	std::wcout << "Hello, please describe your cup for us " << std::endl;

	try {

		std::cout << "Name of cup ? : " << std::flush;
		std::cin >> cup.cup_name; std::cout << std::endl;

		if (cup.cup_name.length() < 2)
			throw Error_Handling();

		std::cout << "Height of cup ? : ";
		std::cin >> cup.height; std::cout << std::endl;

		if (cup.height > 40)
			throw Error_Handling();

		std::cout << "Radius of cup ? : ";
		std::cin >> cup.radius; std::cout << std::endl;

		if (cup.radius > 40)
			throw Error_Handling();

		std::cout << "Bevel amount of cup ? : ";
		std::cin >> cup.bevel_amount; std::cout << std::endl;

		if (cup.bevel_amount > 10)
			throw Error_Handling();

		std::cout << "Thickness of cup ? : ";
		std::cin >> cup.thickness; std::cout << std::endl;
		if (cup.thickness > 5)
			throw Error_Handling();

	}
	catch (Error_Handling& e) {

		std::cerr << "An error occurred. " << e.what() << std::endl;

		//return e.value();
	}
	catch (...) {

		std::cerr << "Unknown error." << std::endl;

	}

	std::cout << "Moving on..." << std::endl;
	*/



/*
	try {

		std::cout << "Tell us ur name : " << std::flush;

		std::string name{ "" };
		std::cin >> name;
		std::cout << std::endl;

		if (name.length() < 2)
			throw Error_Handling();

		auto p_name = std::make_shared<std::string>(name);

		std::cout << "Oh Hi, " << name << std::endl;
		std::cout << "Let's do something fun!" << std::endl;

	}
	catch (Error_Handling& e) {

		std::cerr << e.what() << std::endl;

		return (0xffffffff);
	}

	std::cout << "Ok, Let's do something fun!" << std::endl;
	*/