#include <iostream>
#include <string>
#include <utility>
#include <bits/stdc++.h>

// Type parameter templates consists of :
//Function templates and Class templates

//Function Template
template <typename T>
T maximum_value(const T& value_a, const T& value_b){

    return (value_a > value_b ? value_a : value_b);
};

//Class Template
template <class P>
struct Pencil{

private:
    P length{}, radius{};

public:
    //Pencil(){}
    Pencil(const P len, const P rad): length(len), radius(rad){

        if((len < 1 || len > 100) && (rad < 1 || rad > 28))
            throw std::range_error("Invalid Values");
    }

    void pencil_details(){
        std::cout << "Length of pencil is " << length << std::endl;
        std::cout << "Radius of pencil is " << radius << std::endl;
    }
};

// Non-Type parameter Template

template <class W, size_t array_size>
class Element{

    W array[array_size]{};

public:
    Element(){std::cout << "Hey, ";}

    void set_array_elements(W arr[array_size] ){

        for(size_t t{0}; t < array_size; t++){

            array[t] = arr[t];
        }

        //return array[array_size];
    };

    auto get_elements(const size_t& element_position){

        if(element_position > array_size)
            throw std::out_of_range("Element position is out of range.");

        std::cout << array[element_position] << std::endl;
    };
};

//practicing templates with multiple type parameters

template <typename A, typename B, typename C> struct Card{

    Card(const A& a, const B& b, const C& c){

        std::cout << "A is " << a << std::endl;
        std::cout << "B is " << b << std::endl;
        std::cout << "C is " << c << std::endl;
    }
};

//practicing templates that take any datatype

template <typename ...ARGS>
struct Student{

    Student(){

        std::cout << "Just a student object that is encapsulated in a template that \n";
        std::cout << "takes in any datatype and uses the ellipsis as the placeholder.\n";
    }
};

//practicing default templates
template <typename L = std::string, typename C = char, typename S = size_t> struct Characters{

private:
    L str{};
    S num{};
    C arr[];

public:
    explicit Characters(const L ch): str(std::move(ch)), num(0), arr(){
        // clang prefers using the std::move instead of passing by ref

        num = str.length();

        arr[num];

        std::strcpy(arr, str.c_str());

        std::cout << "Random number generated from input is : " << sizeof(str) * rand() << std::endl;
    };

    S character_length(){

        return num;
    }

    L reverse_characters(){

        if(std::cin.fail())
            throw std::invalid_argument("Write a word");

        //std::cout << "You typed in : " << str << std::endl;

        for(size_t t = num; t <= num; t--){

            std::cout << arr[t] << std::flush;
        }
        std::cout << std::endl;

    }
};



/*
// The compiler can deduce a datatype if the type argument passed to a template is declared with auto
// If accompanied with the ellipsis operator (...), the template can
   be used to directly declare and initialize a list of different data types
=================================================================

 This delves into the practice of Variadic templates and
 how to pack and unpack template arguments (data)
*/
template <auto v> constexpr auto rigid = v;
auto value = rigid<24>;
//template <auto x> auto show_value(){};


/*
 Variadic templates refers to a template that receives an arbitrary number of
 template parameters declared with an identifier/placeholder that follows the ellipsis (...) operator.

 This (the data) will pass into the template as a 'template pack' and must be
 expanded in a variadic function before use.
 Though there're many ways of expansion, I'm going to be practicing some.

 Basic variadic template:
 template <class ...Ts>


 Variadic template with type 'auto'
 template <auto ...Ts>
*/
template <auto...X> struct Player{

    explicit Player(X... x){};

    short power{};
    float speed{};
    double direction{};

};


int main() {

    //practicing function templates
    std::cout << "Maximum value is " << maximum_value('B', 'A') << std::endl;

    //practicing class templates
    try {

        Pencil <int> pencil_one(2, 2);
        pencil_one.pencil_details();

        Pencil <float> pencil_two(2.5, 1.4);
        pencil_two.pencil_details();

        Pencil <double> pencil_three(12.4569, 3.3337);
        pencil_three.pencil_details();
    }
    catch(std::range_error& e){

        std::cerr << "Error occurred. " << e.what();

        return -1;
    }
    catch(std::out_of_range& o){

        std::cerr << "Error occurred. " << o.what();

        return 1;
    }

    //practicing non-type parameter templates || standard type parameter templates
    double an_array[] {23.341, 12.765, 48.912};

    Element <double, 3> elem;
    elem.set_array_elements(an_array);

    std::cout << "Element position 1 has the value: "; elem.get_elements(1);

    int int_array[5]{21, 12, 54, 23, 72};

    Element <int, 5> elem_2;
    elem_2.set_array_elements(int_array);

    std::cout << "Element position 3 has the value: "; elem_2.get_elements(3);

    // practicing templates with multiple type parameters
    Card <int, double, double> card_one(21, 22.4, 23.14);

    //practicing templates that take any datatype (with ellipsis placeholder)
    Student <> stud;

    //practicing default templates
    Characters <> words("This is Epic");

    std::cout << "Word Length is " << words.character_length() << std::endl;

    std::cout << "Word in reverse is : "; words.reverse_characters();
/*
    const char w[]{"MEGASTAR"};
    short n_elem{ sizeof(w) / sizeof(char) - 1 };
    std::cout << "Size of w is : " << sizeof(w) << '\n';
    std::cout << "No. of letters in w is : " << n_elem << '\n';

    for(size_t c = n_elem; c <= n_elem; c--){

        std::cout << w[c] << std::flush;
    }
    std::cout << std::endl;
*/

/*
//deducing the type of data passed into a template when declared with auto
// only works with VC++ compiler
auto value = rigid<24>;
auto value2 = show_value(rigid<11>);
*/


using my_player = Player<21, 18, 91, 'A'>;



return 0;
};
