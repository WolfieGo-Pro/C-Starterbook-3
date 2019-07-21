/*
  Practicing arithmetics before moving onto pointer arithmetics such as casting
  Highest precedence of operators is the multuply operator '*'
  The 'Mod' operator - 
*/

#include "pch.h"

int arithmetics() {
	
	
	double value = (int)3.5 * 2;

	int ans = { (int)value }; // the casting here is not compulsory

	std::cout << ls2 << value;

	std::string value2{ "mojo" };

	ans += 5;

	std::cout << ls2 << ans;

	short modulus{ (int)90.5 % 12 }; // will output 6, as that's the remainder

	std::cout << ls2 << "Modulus modulo : " << modulus << std::endl;
	std::cout << ls2 << "*********************************************" << std::endl;

	// Using the mod operator to execute every 100th executions in a loop that runs 10,000 times
	long runner{ 100 * 100 };

	for (long i = 0; i < runner; i++) {

		if (i % 100 <= 0) {

			std::cout << ls2 << "Next 100th iteration at --> " << i << " ." << std::endl;
		}


		/*
		if (i == 100) {

			std::cout << ls2 << i << "Next 100th iteration at --> " << i << " " << dot << std::endl;

			i += 100;

			continue;
		}
		*/
	}

	return 0;
}


/*
// For identifying the number next to the decimal point and deciding whether to round up/down the number

std::cout << ls2 << "Enter a decimal number : " << std::flush;

	std::cin >> decimal;
	std::cout << std::endl;

	for (double i = 0; i < decimal.size(); i++) {

		char dot = '.';

		if (decimal.at(i) == dot) {
			unsigned int next_digit = decimal.at(i);

			next_digit++;

			if (next_digit >= 5) {
				decimal = (int)dec;
				decimal += 1;
			}
			else {
				decimal = (int)dec;
			}
		}
	}
*/

/*
if ( i % 100 >= 1) {

			std::cout << ls2 << i << "th Iteration --> " << dot << std::endl;

			//continue;
		}
		else {

			std::cout << ls2 << i << "NOPE" << std::endl;

		}
*/