/* 
  To practice Operator Overloading in C++.
  It is all about re-defining how an operator works
  so that it can be used with objects of 
  user-defined types only
*/

#include <iostream>
#include <exceptions>
#include <memory>

Class Pencil{
	
	int rand;
	short length, radius, sharpness;
	
	unique_ptr<short>ptr_l(nullptr);
	unique_ptr<short>ptr_r(nullptr);
	unique_ptr<short>ptr_s(nullptr);
	
	public:
	Pencil(const short& len, rad, shp): length(len), radius(rad), sharpness(shp), rand(0):{
		
		ptr_l = std::make_unique<short>(length);
		ptr_r = std::make_unique<short>(radius);
		ptr_s = std::make_unique<short>(sharpness);
	}
	
	Pencil operator++(){
		
		Pencil p;
		
		p.rand = rand + 1;
		
		return p;
	}
	
	void pencil_sum(){std::cout << "Sum is " << rand << std::endl;}
}

int main(){
	
	// add pencil objects 
	
	return 0;
}