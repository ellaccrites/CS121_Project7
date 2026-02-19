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

	Student::firstName = fName;
	Student::lastName = lName;

	getline(ss, sStreet, ',');
	getline(ss, sCity, ',');
	getline(ss, sState, ',');
	getline(ss, sZip, ',');

	Student::address.init(sStreet, sCity, sState, sZip);

	getline(ss, sBirthDate, ',');
	getline(ss, sGradDate, ',');

	Student::birthDate.init(sBirthDate);
	Student::gradDate.init(sGradDate);

	getline(ss, sCredits, ',');

	ss.clear();
	ss.str("");

	ss << sCredits;
	ss >> numCredits;

	Student::credits = numCredits;
	
}// end init

void Student::printStudent(){
	std::cout << Student::firstName << " " << Student::lastName << std::endl;
	Student::address.printAddress();
	std::cout << "DOB: ";
	Student::birthDate.printDate();
	std::cout << "Grad: ";
	Student::gradDate.printDate();
	std::cout << "Credits: " << Student::credits << std::endl;
	std::cout << "----------------------------------" << std::endl;
}// end printStudent

std::string Student::getLastFirst(){
	std::string lastFirst;
	lastFirst = Student::lastName + ", " + Student::firstName;
	return lastFirst;
}// end getLastFirst
