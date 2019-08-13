/*
  Going through how arrays should be passed to functions/methods & how arrays should be
  returned from functions/methods

  'show_names1(std::string name[])' is the intuitive way to pass arrays to functions

  - Problem is, information is lost (the size of the array) as we pass it to a function.
  - So we get instead, the size of a pointer == size of long == 4 - 8 bytes


  'show_names2(int n_elements, std::string array[])' solves the issue from 'show_names1()'

  - The no. of elements in the array is passed as type 'int' through parameters as well.


  'show_names3(std::string* p)' is the preferred way to pass arrays to functions (for me)

  - Though the size of the pointer to the array won't give the size of the array, but the pointer instead.
  - So, the no of elements can be included in the parameters as well to look like this :--
  'show_names3(int n_elements, std::string* p)'


  'show_names4(std::string (&names_array)[3])' --> passing arrays (and the whole elements) by reference

  - Brackets are used so that the compiler knows that we want a reference to an array of strings.
  - So, there's no need to pass an argument that specifies the no. of elements

  //////////////////////////// RETURNING ARRAYS FROM FUNCTIONS ////////////////////////////////

  Of course , there's one thing that one must not do, return a local array from a function.
  However, one may return a pointer to an array.
  If using 'new', one should make sure other programmers know that they've got to free up memory.
*/

#include "pch.h"

void show_names1(std::string name[]) {

	for (short i{ 0 }; i < 3; i++) {
		std::cout << ls1 << name[i] << std::endl;
	}

	//std::cout << ls1 << "Size of array in function is " << sizeof(name) << std::endl; // outputs size of pointer instead

	std::cout << ls1 << "***************************" << std::endl;
}


void show_names2(const int n_elements, std::string arrays[/*3*/]) {// C++ will ignore the no. of elements in the square brackets

	for (short i{ 0 }; i < n_elements; i++) {
		std::cout << ls1 << arrays[i] << std::endl;
	}
}

void show_names3(const int n_elements, std::string* p) {

	for (short i{ 0 }; i < n_elements; i++) {
		std::cout << ls1 << p[i] << std::endl;
	}

}

void show_names4(std::string (&names_array)[3]) {// Doesn't look nice, but it works

	for (unsigned i{ 0 }; i < sizeof(names_array) / sizeof(std::string); i++) {

		std::cout << ls1 << names_array[i] << std::endl;
	}

}


//// Returning Arrays from functions ////

double* get_scores() {

	double *scores = new double[4];

	scores[0] = 15.5;
	scores[1] = 17.85;
	scores[2] = 20.85;
	scores[3] = 21.25;

	for (unsigned i{ 0 }; i < 4; i++) {

		std::cout << ls1 << scores[i] << std::flush;
	}

	return scores;
}

void clear_scores(double *scores) {

	delete[] scores;
}

int main() {

	std::string names[]{ "berry", "terry", "harry" };

	show_names1(names);

	std::cout << ls1 << "Size of array in main scope is " << sizeof(names) << std::endl;

	std::cout << ls1 << std::endl;


	show_names2(3, names);

	std::cout << ls1 << std::endl;


	std::string* p_names{ names };

	show_names3(3, p_names);

	std::cout << ls1 << std::endl;


	show_names4(names);


	///////////  RETURNING ARRAYS FROM A FUNCTION  ////////////

	double* scores{ get_scores() };

	clear_scores(scores);

	return 0;
	//exit(0);
}
