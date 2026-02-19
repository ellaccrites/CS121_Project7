// date.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "date.h"

Date::Date(){
	Date::month = 1;
	Date::day = 1;
	Date::year = 0;
}// end no param constructor

void Date::init(std::string stringDate){
	std::stringstream ss;
	std::string sMonth;
	std::string sDay;
	std::string sYear;
	int intMonth;
	int intDay;
	int intYear;

	ss.clear();
	ss.str("");

	ss.str(stringDate);
	
	getline(ss, sMonth, '/');
	intMonth = stoi(sMonth);
	Date::month = intMonth;

	getline(ss, sDay,'/');
	intDay = stoi(sDay);
	Date::day = intDay;

	getline(ss, sYear,'/');
	intYear = stoi(sYear);
	Date::year = intYear;

}// end init

void Date::printDate(){
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	std::cout << months[Date::month - 1] << " " << Date::day << ", " << Date::year << std::endl;
}// end printDate


