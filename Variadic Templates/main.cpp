/*
  practicing variadic templates .
  These templates enable me to use one single template parameter to
  take in multiple data of different data types and encapsulate it in
  a 'parameter pack'. The pack would then be expanded in a variadic function
  in order for me to use the data in the pack

*/

#include <iostream>
#include <tuple>

template <class ...Ts>

// essentially, I'm telling the function to
// create a function parameter pack of data from the template parameter pack.
void show_me(Ts...ts);


template<class ...Ts>
void show_me(Ts... ts) {

 //Now, expand the pack to a data structure so that the data can then be used.
// To do that, you have to expand template parameter pack 'Ts' first, then function parameter pack 'ts'
    std::tuple<Ts...> unpacked_data_one{ts...};

 // Normally, 'perfect forwarding' is used along with the tuple.
    std::tuple<Ts...> unpacked_data_two{std::forward<Ts>(ts)...};

 // Why? - "Whenever two packs appear side by side for a pack expansion,
// both packs will get expanded simultaneously and therefore need to have the same number of elements."
// So in a way, using 'perfect forwarding' assures me that the no. of data/elements that will be unpacked is
// equal to the no. of packed data/elements in the pack.

}

template <class U, class D, typename S>struct Without_Variadic{

        Without_Variadic(const U& u, const D& d, const S& s){

            std::cout << "Okay\n";

            std::tuple<U, D, S>gather_data = std::make_tuple(u, d, s);
            //std::unordered_set<U, D, S>listing_data{u, static_cast<int>(d), static_cast<int>(s)};
            //std::list<U, D, S>list_data{u, d, s};

            size_t t_size = std::tuple_size<decltype(gather_data)>::value;

            std::cout << "Number of data in tuple is : " << t_size;

            /*
            for(auto i = 0; i < t_size; i++){
                std::cout << std::get<i>(gather_data);
            };
             */
        }

    };

/*
// Empty Packs - Since variadic templates can take an arbitrary no. of parameters, this includes 0
// parameters. So, this means an empty list can be made
template<>
void show_nada(){

    std::tuple<>nada{};
};
*/


int main() {

    show_me(45u, 163.93, "konishiwa");

//The template parameter pack will be the list of the types of the pack(in this case, type unsigned, type double and
// type const char*), whereas the function parameter pack will be the list of the data/elements of
// the pack (in this case, 45u, 163.93 and "konishiwa").

Without_Variadic<int, double, float> w(21, 321.2, 12.2f);

    return 0;
}

// practice re-writing what this means if the variadic template and function wasn't used. (done)
// practice to see if you can expand the parameter pack without the variadic function. (done)
// also practice if you can unpack the data/elements into other structures such as 'unordered_list', list (done)
// check 'empty packs' (they are so easy to understand) (done)
