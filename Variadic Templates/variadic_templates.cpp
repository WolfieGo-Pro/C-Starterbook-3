/*
  practicing variadic templates .
  These templates enable me to use one single template parameter to
  take in multiple data of different data types and encapsulate it in 
  a 'parameter pack'. The pack would then be expanded in a variadic function
  in order for me to use the data in the pack

*/

template <typename ... Ts>;

void variadic_function(Ts... ts){
	
	// essentially, I'm telling the function to 
    // create a function parameter pack of data from the template parameter pack.
	
	//Now, expand the pack to a data structure so that the data can then be used.
	// To do that, you have to expand template parameter pack 'Ts' first, then function parameter pack 'ts'
	std::tuple<Ts...> unpacked_data{ts...};
	
	// Normally, 'perfect forwarding' is used along with the tuple.
	std::tuple<Ts...> unpacked_data_2{std::forward<Ts>(ts)...}
	
	// Why? - "Whenever two packs appear side by side for a pack expansion, 
	// both will get expanded simultaneously and therefore need to have the same number of elements."
	// So in a way, using 'perfect forwarding' assures me that the no. of data/elements that will be unpacked is
	// equal to the no. of packed data/elements in the pack.
}



variadic_function(45u, 393.23, "vaya");

//The template parameter pack will be the list of the types of the pack(in this case, type unsigned, type double and type const char*), whereas
//the function parameter pack will be the list of the data/elements of the pack (in this case, 45u, 393.23 and "vaya").












// practice to see if you can expand the parameter pack without the variadic function.
// also practice if you can unpack the data/elements into other structures such as 'unordered_list', list 
// practice re-writing what this means if the variadic template and function wasn't used.
// check 'empty packs' (they are so easy to understand)