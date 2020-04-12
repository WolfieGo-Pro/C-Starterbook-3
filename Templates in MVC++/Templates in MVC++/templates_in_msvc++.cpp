// practicing type deduction of non-type template parameters declared with 'auto'

/*
	//deducing the type of data passed into a template when declared with auto
	// only works with VC++ compiler
	auto value = rigid<24>;
	auto value2 = show_value(rigid<11>);

*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <tuple>

auto return_value() {

	double val_a = pow(3, 3), val_b = pow(4, 4);

	double sum = val_a + val_b;

    return sqrt(sum);
}

//auto as type parameter
template <auto x> constexpr auto rigid = x;

//template as a template parameter - nothing yet



// practicing non-type templates

// Was thinking of using inheritance for these classes since they share some characteristics
struct Cup {

	short length{}, radius{};
	
	std::string name{};
};

struct Pot {

	short length{}, radius{};
};

struct Plate {

	short length{}, radius{}, thickness{};

	Plate() { std::cout << "Plate object." << std::endl; };

	void display_details() {

		std::cout << "Radius is " << radius << std::endl;
		std::cout << "Thickness is " << thickness << std::endl;
		std::cout << "Length is " << length << std::endl;
	}
};

template <class T, size_t S>
class Item_Manager {

public:
	T item_array[S]{};

	explicit Item_Manager() { 
		
		std::cout << "Okay..." << std::endl;
	};

	void compare_template_type_parameters() {

		std::cout << "Hash code of the 1st template parameter is = " << typeid(T).hash_code() << std::endl;
		std::cout << "Hash code of the 2nd template parameter is = " << typeid(S).hash_code() << std::endl;

		if (typeid(T).hash_code() == typeid(S).hash_code()) {
			std::cout << "The template parameter types are the same.\n";
		}
		else {
			std::cout << "The template parameter types are not the same.\n";
		}

	}
	
};


template <class ...Ts> void call_utensils(Ts... ts) {

	std::tuple<Ts...>gathered_data{ std::forward<Ts>(ts)... };

	std::cout << "No. of data/elements in tuple is = " << std::tuple_size<decltype(gathered_data)>::value << std::endl;

	//write tuple code that prints and changes unpacked data

};

auto main()->int {
	
	auto value = rigid<return_value>;
	
	//template as a template parameter - nothing yet


	//practicing non-type templates

	//auto ptr_plate = std::make_unique<Plate>();

	Item_Manager<Plate, 12>manager;

	manager.item_array[0].thickness = 2; //setting the thickness value of the first plate object in the array

	manager.item_array[0].display_details();

	manager.compare_template_type_parameters();
	
	//now with variadic templates
	std::unique_ptr<Plate> ptr_plate;
	std::unique_ptr<Pot> ptr_pot;
	std::unique_ptr<Cup> ptr_cup;
	
	call_utensils(&ptr_plate, 19, &ptr_pot, 3, &ptr_cup, 7, "utensils");


	
	return 0;
}
