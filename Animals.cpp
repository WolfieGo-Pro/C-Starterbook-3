#include "pch.h"

namespace them {

	Humans::Humans() {

		std::cout << "Animal created." << std::endl;
	}

	Humans::~Humans() {

		std::cout << "Animal destroyed." << std::endl;
	}

	void Humans::oral() {

		std::cout << "grrmoewoww" << std::endl;
	}

}