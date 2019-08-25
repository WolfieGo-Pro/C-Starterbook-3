#pragma once

class Person {
public:
	Person() { std::cout << "Person made" << std::endl; };
	Person(std::string stat) : status(stat) { std::cout << "This is a person." << std::endl; };
	~Person();

	void info() { std::cout << "Your status is " << status << std::endl; }; //outputs only what's already initialized in the class

private:
	std::string status{ "N/A" };
	
};

class Boy : public Person {
public:
	Boy() { size; };
	Boy(std::string stat) :Person(stat) { std::cout << "I'm a Boy." << std::endl; }; // this construcor will call its super class constructor
	~Boy();
	
	//void info() { std::cout << "Your size is " << size << std::endl; };

private:
	std::string size = ("Small");
	//std::string stat = "";
};


////// Encapsulation ///////
class Man : public Boy {
public:
	Man():Boy("Gang") { balls = 0; std::cout << "I'm a man now." << std::endl; };
	//Man() {};
	~Man();

	//std::string size = "";

	void detalles() { std::cout << "No. of balls is " << *get_balls() << std::endl; };

	short set_balls(short* n_balls) { this->balls = *n_balls; return balls; };

protected:
	short* get_balls() { short* p_balls = &balls; return p_balls; };

private:
	short balls;
};
