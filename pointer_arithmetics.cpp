/*
  All what we I've done in 'pointers and arrays.cpp' file + This
  
  Having the pointers of an array as an operand, with operators,
  makes it possible to move the pointer to point to another 
  block of memory/element in the array by its type
  
  std::string honey[] {"loco", "juice", "hen"};
  
  std::string * p_honey {honey}; (default. Actually points to honey[0])
  
  p_honey++; - Tells the compiler to move the pointer forward per one string
  
  p_honey += 3; - Tells the compiler to move the pointer forward by 3 strings
  

  PRO TIP - Do not set a pointer to an element of an array you're not sure exists
  (eg. be cautious when pointing to the last element in the array)

			- when dealing with pointers it's a good idea to cast 
			pointer variables to (long) to "make it clear what's happenning"

  ...and so on.
*/