/*
  It's all about inline initialization of 
  constructor, using parameters/arguments of data members
  to explicitly state what values will be gotten when 
  a class instantiation takes place.

  Essentially, each instantiated object can contain their own data from the class blueprint
  
  Hence, implementation of the method in a class's .cpp file
  is not needed.

   Of course, it's not a modern C++17 approach but quoting a presenter
  in cppcon 2018, "... but it works."

  Also got to practise using the 'this->' pointer variable. (I already started using it
  before I completely understood what it is and what it contains. This means that 
  there's no need to declare & initialize 'new_name'.. just 'name' , with
  'this->name' pointing/referring to the data member.
  '&<instantiated object>' can be used to show the memory address of an instantiated object

  Definitely learnt 3 ways of initializing data members through constructors or get methods
*/

#include "Pch.h"

using namespace std;

int main() {

	Person_Blueprint default_person;
	
	unsigned short u_age;
	double some_decimal;
	string u_gender, u_name;

	cout << "Enter Age : " << flush;
	cin >> u_age; cout << endl;

	cout << "Enter Name : " << flush; 
	cin >> u_name; cout << endl;
	
	cout << "Enter Gender : " << flush; // lol
	cin >> u_gender; cout << endl;

	cout << "Enter a decimal number : " << flush;
	cin >> some_decimal; 
	cout << endl;

	default_person.set_some_decimal(some_decimal); // Switched to using constructors soom much, that I forgot how to use getters & setters for about 40 mins

	cout << endl;
	cout << "You entered " << default_person.get_some_decimal() << endl;
	/*
	Person_Blueprint person1(u_age); // Because of Person_Blueprint(unsigned short new_age) { age = new_age; }; - Inline
	
	Person_Blueprint person2(u_name, u_gender); // Because of Person_Blueprint(std::string new_name, std::string new_gender);
	//Person_Blueprint person2(const Person_Blueprint &); //passing values by reference - modern C++
	
	Person_Blueprint person3(u_age, u_name, u_gender);
	// Because of Person_Blueprint(unsigned short new_age, std::string new_name, std::string new_gender) { age = new_age;  name = new_name; gender = new_gender; }; // Inline

	cout << "1st - " << person1.all_data_to_string() << ". Memory Location : " << &person1 << '\n';
	cout << "2nd - " << person2.all_data_to_string() << ". Memory Location : " << &person2 << '\n';
	cout << "3rd - " << person3.all_data_to_string() << ". Memory Location : " << &person3 << '\n'; // This is the one with all the details printed together
	*/
}