//Implementation for Data members of the User_Info Class

#include "Pch.h"

using namespace std;

User_Info::User_Info() {

	usual_intro();

	user_name = ("");
	/* user_age = (0);
	user_gender = (true);
	*/
}

bool User_Info::set_user_name(string new_name) {

	if (!new_name.empty()) { // Primitive stuff

		user_name = (new_name);

		return true;
	}
	else
	{

		//cout << ls3 << "Name not set, please try again\0" << endl;

		return false;
	}

}

string User_Info::get_user_name() { //We don't need this though

	if (!user_name.empty()) {

		return user_name;
	}
	else
	{
		return "Please write your name\0";
	}
}

bool User_Info::set_user_age(unsigned short new_age) { //Won't use it in this project

	if (new_age < 99 && new_age > 14) { // Sanity check

		user_age = (new_age);

		return true;
	}
	else {

		//cout << ls3 << "Please enter your age : \0" << endl;

		return false;
	}
}

void User_Info::usual_intro() {

	cout << ls3 << "Hi, welcome to the Information Bank\0" << endl;
	cout << ls3 << "Please Provide the necessary details..\0" << endl;
}

User_Info::~User_Info() {

	//cout << ls3 << "Time's Out\0" << endl;

}