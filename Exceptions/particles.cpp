// practice error handling with smart pointers

#include <iostream>
#include <exception>
#include <stdexcept>
#include "Exception_Handling.h"
#include <time.h>

struct Dot {

private:
	char dot;
	//std::unique_ptr<char> p_dot;

public:
	Dot(): dot(0x2F){};
	//Dot(const Dot& obj) { Dot d = obj; };
	//~Dot() {};

	void show_dots(int n_dots) {

		if (n_dots < 1)
			throw std::invalid_argument("Too small");

		for (short c = 0; c < n_dots; c++) {
			std::cout << dot << std::flush;
		};
	}
};

int pixels() {

	srand(time(NULL));

	Dot dot;

	while (true) {

		long r = (INT16_MAX / rand());

		try {

			dot.show_dots(r);
		}
		catch (const std::exception& e) {

			std::cerr << e.what();

			return 1;
		}


	};
	

	return 0;
}