#include "pch.h"
// Animal Class implementation.

std::string Animal::set_animal_name(std::string animal_name)
{
	this->animal_name = animal_name;

	return animal_name;
}

short Animal::set_animal_age(short animal_age)
{
	this->animal_age = animal_age;
	
	return animal_age;
}

void Animal::animal_info()
{
	std::cout << "Animal's name is : " << animal_name << std::endl;
	std::cout << "The animal is : " << animal_age << " years old." << std::endl;
	//std::cout << "The animal's lifespan is : " << lifespan << std::endl;
}

void* Animal::get_lifespan() // could have worked if this function was not in the 'Animal' class
{
	std::cout << "The animal's lifespan is : " << lifespan << std::endl;
	
	if (!lifespan) {
		return nullptr;
	}
}
