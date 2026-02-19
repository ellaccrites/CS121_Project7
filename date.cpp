// date.cpp

#include <iostream>
#include "date.h"

Date::Date(){
	Date::month = "N/A";
	Date::day = "N/A";
	Date::year = "N/A";
}// end no param constructor

void Date::init(int month, int day, int year){
	Date::month = month;
	Date::day = day;
	Date::year = year;
}// end init

void Date::printDate(){
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	std::cout << months[Date::month - 1] << " " << Date::day << ", " << Date::year << std::endl;
}// end printDate


