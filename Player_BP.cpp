#include "Includes\pch.h"

using namespace std;

Player_BP::Player_BP()
{

	get_user_name();

	//user_name = "Harry";

	Gender_Info human_type;

	human_type.user_gender = true;
}

/*
Player_BP::~Player_BP()
{
}
*/

string Player_BP::get_user_name() {

	return user_name;
}

void Player_BP::set_user_name(string new_user_name) {

	new_user_name = user_name;
};

unsigned short Player_BP::get_user_age() {

	return user_age;
}

void Player_BP::set_user_age(unsigned short new_user_age) {

	user_age = new_user_age;
}
