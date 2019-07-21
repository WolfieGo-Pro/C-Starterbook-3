#pragma once
class Player_BP
{
private:
	string user_name;

	unsigned short user_age{};

	struct Gender_Info
	{
		char user_gender;

		bool gender;
	};

public:
	Player_BP();
	//~Player_BP();

	string get_user_name();

	void set_user_name(string new_user_name);

	unsigned short get_user_age();

	void set_user_age(unsigned short new_user_age);
};