// practicing exception handling with user-defined exception class

#ifndef EH_H
#define EH_H

#include <iostream>
#include <exception>
#include <stdexcept>

namespace EH {

	class Error_Handling : public std::exception {

	public:
		virtual const char* what() {

			return "Invalid Values Provided for Cup";
		}

		virtual const short value() {

			return 2;
		}

	};

}

#endif // !EH_H