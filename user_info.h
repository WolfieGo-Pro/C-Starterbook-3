#ifndef USER_INFO
#define USER_INFO

class User_Info
{
private:
	string user_name;
	unsigned short user_age;
	bool user_gender;

	void usual_intro();

public:
	User_Info();
	~User_Info();

	bool set_user_name(string new_name);
	string get_user_name();

	bool set_user_age(unsigned short new_age); // WOn't use it in this project
};

#endif