/*
  I pretty much know what namespaces are and how to
  articulate it in a program
*/

#include "pch.h"

namespace voos{

	const std::string ls{ "\n\t" };
}

int main() {

	std::cout << voos::ls << "Yoo, I'm going to be wealthy and make other reliable people around me wealthy as well." << std::endl;

	us::Humans human;

	human.oral();

	them::Humans animal;

	animal.oral();


}