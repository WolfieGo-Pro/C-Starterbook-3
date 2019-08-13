#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{

protected:
	std::string animal_name;
	short animal_age;
	double lifespan;

	char name;

public:
	Animal() { std::cout << "Animal created." << std::endl; };
	Animal(double lifespan) : lifespan(lifespan) {};
	~Animal() { std::cout << "Animal destroyed." << std::endl; };
	Animal(const Animal& object) : animal_name(object.animal_name), animal_age(object.animal_age), lifespan(object.lifespan) { std::cout << "Animal created by copying" << std::endl; };

	std::string set_animal_name(std::string animal_name);

	short set_animal_age(short animal_age);

	void animal_info();

	void* get_lifespan();


	// for the last activity in the main.cpp file (Object Arrays)
	char set_name(char names) { this->name = names; return name; };
	void output_name() { std::cout << name << std::endl; };
};

#endif // !ANIMAL_H