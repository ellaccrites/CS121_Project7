// student.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "student.h"

Student::Student(){
	Student::firstName = "N/A";
	Student::lastName = "N/A";
}// end no param constructor

void Student::init(std::string studentString){
	std::stringstream ss;
	std::stringstream converter;

	std::string fName;
	std::string lName;
	std::string sStreet;
	std::string sCity;
	std::string sState;
	std::string sZip;
	std::string sBirthDate;
	std::string sGradDate;
	std::string sCredits;

	int numCredits;

	ss.str(studentString);

	getline(ss, fName, ',');
	getline(ss, lName, ',');

	Student::firstname = fName;
	Student::lastName = lName;

	getline(ss, sStreet, ',');
	getline(ss, sCity, ',');
	getline(ss, sState, ',');
	getline(ss, sZip, ',');

	address.init(sStreet, sCity, sState, sZip);

	getline(ss, sBirthDate, ',');
	getline(ss, sGradDate, ',');

	birthDate.init(sBirthDate);
	gradDate.init(sGradDate);

	getline(ss, sCredits, ',');

	ss.clear();
	ss.str("");

	ss << sCredits;
	ss >> numCredits;

	credits = numCredits;
	
}// end init

void Student::printStudent(){
	std::cout << firstName << " " << lastName << std::endl;
	address.printAddress();
	std::cout << "DOB: " << birthDate.printDate() << std::endl;
	std::cout << "Grad: " << gradDate.printDate() << std::endl;
	std::cout << "Credits: " << credits << std::endl;
}// end printStudent

std::string Student::getLastFirst(){
	lastFirst = lastName + ", " + firstName;
	return lastFirst;
}// end getLastFirst
