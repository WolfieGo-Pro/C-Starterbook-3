// Let's practice pointers... again.

#include "pch.h"

unsigned short set_age(unsigned short* age) {

	std::cout << ls2 << "So you are " << *age << " years old." << std::endl;
	
	*age = 25;

	std::cout << ls2 << "The thing is, you've got to be " << *age << " years old." << std::endl;

	return *age;
}

std::string set_name(std::string* name) {

	std::cout << ls2 << "Wow, you got named " << *name << ". Damn! your parents must hate you. lol" << std::endl;

	*name = "Steve";

	std::cout << ls2 << "Ok, from now on, your name will be " << *name << ". " << std::flush;
	std::cout << ls2 << "That sounds normal. Something you're not. lol" << std::endl;

	return *name;
}

int practise_pointers() {

	struct User
	{
		unsigned short age{ 0 };
		std::string name{""};
	};

	User info;

	std::cout << ls2 << "How old are you? : " << std::flush;
	std::cin >> info.age; // using 'std::getline' didn't work
	std::cout << std::endl;

	set_age(&info.age);

	std::cout << ls2 << info.age; // Outputs '25'
	
	std::cout << ls2 << "What's your name? : " << std::flush;
	std::cin >> info.name;
	std::cout << std::endl;

	set_name(&info.name);
	
	std::cout << ls2 << info.name;

	return 0;
}