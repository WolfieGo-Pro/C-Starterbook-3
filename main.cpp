/*
 * Practicing macro constants and iterators
 *
 * Macro Constants
 * Since pre-processor directives run before the program compiles,
 * defining a macro constant means that you're telling the compiler to
 * directly replace <this> with <that>. i.e. replace this value/function with this value/function in
 * all areas of the file.
 *
 * Iterators
 * To 'iterate' means to run repetitively.
 * Iterator in C++ is a pointer and is used to point at container memory location/address.
 * Since its a pointer, you can de-reference it to print out the actual value from a container.
 *
 *
 */

/*
 *Using static members with classes/struct that use templates
template <typename T>struct DK{

    static int counter;
};

template<T> int DK<T>::counter;
*/



#include <iostream>
#include <cmath>
#include <iterator>

#define LOG std::cout <<
#define END std::cout << std::endl;
#define RAND_NUMBER 10
#define PI 3.14159
#define area_of_circle(r) (PI * pow(r, 2))


int main() {

    std::cout << "Hiya!" << std::endl;
    LOG "Using macros, Yoo!" << std::endl;

    for(int i = 1; i < RAND_NUMBER; i++){

        short remainders = RAND_NUMBER % i;

        LOG "Remainders of Random number divided by 'i' is =  " << remainders; END

        LOG "Area of circle is : " ; LOG area_of_circle(remainders); END

    }
    LOG "***************************************"; END
    LOG "Now, Iterators"; END



    return 0;
}