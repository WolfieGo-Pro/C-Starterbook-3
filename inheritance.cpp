/*
  I like to think of inheritance as an extension of attributes/features/blueprint/class.

  Each class created from the base class (1st class) / super-class is a sub-class/child-class of
  the base class.

  It has to be built in a way that makes sense and is applicable to the real world.

  When an object is instantiated from the sub-class/child class, the constructor of the parent-class runs,
  followed by the constructor of the child-class. Then the destructor of the child-class runs, and
  finally followed by destructor of the parent-class.

  2 analogies.

  one is the Employer-Supervisor-Employee hierachy.
  The other is the Person-Boy-Man hierachy.

  There's also constructor-inheritance, where the data members in a parent class is not the same in the child class.
  Hence, data members can be called by the child class/sub class, but instance variables used in the 
  child class/sub-class IS NOT inherited from the parent class/ super-class IF
  the variables have been declared outside the class.

  To put simply, There's inheritance across base & derived classes if the data members are static.

  ///////////// Encapsulation ///////////////

  Used for making most (if not) all data members private. For security reasons.
  Hiding away instance variables and only provide a few public methods which a user
  may call to do something with it.

  If data members aren't encapsulated, they will associate themselves to every object that is instantiated
  from that class and all data members would be accessible directly.
  It is most likely that you'll find methods that contain other methods so that they don't give away the
  actual value used in that method.

  BOTTOM LINE-:  You should make anything (method/functions) in your class private much as you can if
  the user of the class doesn't have to know about it.

  N. 4

  Now, let's mutate/change the data member of a parent class from a sub-class/child class

  Say the member function we want to mutate is in the 'Person' class, we create a pointer that points to an object instantiated from
  The 'Person' class. Then an object is instantiated from a direct derived/sub-class. The pointer will now point to the memory address of
  The instantiated object from the sub-class. From there, the pointer can be used to call the over-written member function in the
  Child class.

  The same goes for changing data members, except that we choose which constructor of the parent class that accepts the mutable data as a parameter

  All these kinda clash with virtual member functions. And is making my head spin.

*/

#include "pch.h"

int main() {

	Person new_person("whoa");
	new_person.info();
	
	Boy boy("Heyya");
	boy.info();
	
	Man man;
	man.info();
	/*
	short Ballsie{ 2 };

	short* P_balls = &Ballsie;

	man.set_balls(P_balls);

	man.detalles(); // outputs the method for getting no. of 'balls' (Encapsulation)
	*/

	//Man man;
	//man.info();

	//Boy *b;










	/*
	N.4

	Person *p;

	Boy b("Dang");
	p = &b;

	p->info();
	*/
}