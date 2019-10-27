// Time.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <time.h> // crucual
#include <errno.h> //(error number). This macro is needed to specify the pattern/rule of input to the 'tm' time struct

std::string get_date_time() {

	time_t raw_time = time(NULL);

	errno_t time_pattern;

	struct tm time_details; // can be a pointer to or variable of 'tm'

	char time_buffer[80];
	
	// Normally, 'localtime()' would be used, but VC++ produces an error stating that it is unsafe for use and 'localtime_s()' should be used instead.
	
	time_pattern = localtime_s(&time_details, &raw_time);

	char time_format[13] = "%Y-%m-%d. %X";

	strftime(time_buffer, sizeof(time_buffer), time_format, &time_details);

	std::string buffer = time_buffer;

	return buffer;
}

int main()
{

	std::cout << "System's current date & time is : " << get_date_time() << std::endl;

	return 0;
}






/*

    TO ONLY OUTPUT SECONDS
	
	while (true) {

		time_t rt = time(NULL);

		struct tm td;

		localtime_s(&td, &rt);

		//char bf[80];

		//strftime(bf, sizeof(bf), "%X", &td);

		std::cout << "Time (seconds) : " << td.tm_sec << std::endl;

	}
*/