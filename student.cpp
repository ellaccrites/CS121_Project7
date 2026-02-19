// student.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "student.h"

Student::Student(){
	firstName = "N/A";
	lastName = "N/A";
}// end no param constructor

void Student::init(){
	
}// end init

void Student::printStudent(){
	std::cout << firstName << " " << lastName << std::endl;
	address.printAddress();
	std::cout << "DOB: " << birthDate.printDate() << std::endl;
	std::cout << "Grad: " << gradDate.printDate() << std::endl;
	std::cout << "Credits: " << credits << std::endl;
}// end printStudent
