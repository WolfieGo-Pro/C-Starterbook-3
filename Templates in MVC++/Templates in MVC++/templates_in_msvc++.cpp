// practicing type deduction of non-type template parameters declared with 'auto'

/*
	//deducing the type of data passed into a template when declared with auto
	// only works with VC++ compiler
	auto value = rigid<24>;
	auto value2 = show_value(rigid<11>);

*/

#include <cmath>
#include <cstdio>

auto return_value() {

	double val_a = pow(3, 3), val_b = pow(4, 4);

	double sum = val_a + val_b;

    return sqrt(sum);
}

template <auto x> constexpr auto rigid = x;

auto main()->int {

	auto value = rigid<return_value>;
	
	
	return 0;
}