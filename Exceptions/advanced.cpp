// practicing how using smart pointers for handling errors is useful
// and how it can be a garbage collector

#include <iostream>
#include <exception>
#include <stdexcept>
#include <memory.h>
#include <vcruntime_exception.h>

struct Character {

private:
	char dot;
	std::unique_ptr<char>p_dot = (nullptr);

public:
	Character() : dot(0x2E), p_dot(std::make_unique<char>(dot)) { std::cout << "Character object instantiated" << std::endl; }
	//Character(const Character& obj) { Character c = obj; }
	~Character() {};

	void show_dot() { std::cout << *p_dot << std::endl; }
};

struct Char_Manager {

private:
	std::unique_ptr<Character[]>p_character;
	
public:
	Char_Manager(const int& n_chars) : p_character(nullptr) {
		
		p_character = std::make_unique<Character[]>(n_chars), std::default_delete<Character[]>();

		if (!p_character)
			throw std::exception("Could not create character objects"); //tried throwing std::bad_alloc
		
		while (!std::cin >> n_chars) {

			std::cin.clear();
			std::cin.ignore(123, '\n');

			throw std::invalid_argument("Please enter the number of Dots to print out");
		}
	}
	
	~Char_Manager() {};

	void show_chars() { /*p_character->show_dot();*/ }
};

int main() {

	try {

		Char_Manager cm(10);
	}
	catch (const std::exception& e) {

		std::cerr << "Error occurred. " << e.what();

		return -1;
	}
	catch (...) {

		std::cerr << "Error occurred.";

		return 1;
	}

	return 0;
};