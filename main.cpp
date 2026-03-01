// main.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "date.h"
#include "address.h"
#include "student.h"

void testAddress();
void testDate();
void testStudent();

void loadStudents(std::vector<Student*>&);
void showStudentNames(std::vector<Student*>&);
void printStudents(std::vector<Student*>&);
void findStudent(std::vector<Student*>&);
void delStudents(std::vector<Student*>&);
std::string menu();


int main(){
	std::cout << "Hello!" << std::endl;
	std::vector<Student*> studentVec;
	loadStudents(studentVec);
	
	int keepGoing = 1;
	while(keepGoing == 1){
		std::string userChoice = menu();
		if(userChoice == "0"){
			std::cout << "Goodbye!" << std::endl;
			delStudents(studentVec);
			keepGoing = 0;
		}else if(userChoice == "1"){
			showStudentNames(studentVec);
		}else if(userChoice == "2"){
			printStudents(studentVec);
		}else if(userChoice == "3"){
			findStudent(studentVec);
		}else{
			std::cout << "Invalid input" << std::endl;
		}// end if else
	}// end while
	return 0;
} // end main

std::string menu(){
	std::cout << '\n';
	std::cout << "0) quit" << std::endl;
	std::cout << "1) print all student names" << std::endl;
	std::cout << "2) print all student data" << std::endl;
	std::cout << "3) find a student" << std::endl;
	std::cout << std::endl;

	std::cout << "Choose an option: ";
	std::string userChoice;
	std::cin >>  userChoice;

	return userChoice;
} // end menu

void loadStudents(std::vector<Student*>& studentVec){
	std::ifstream inFile;
	std::string currentLine;
	std::stringstream ss;
	std::string studentString;

	inFile.open("students.csv");
	while(getline(inFile, currentLine)){
		ss.clear();
		ss.str("");

		ss.str(currentLine);
		getline(ss, studentString, '\n');

		Student* student = new Student();
		student->init(studentString);
		studentVec.push_back(student);
	}// end while
}// end loadStudents
	

void showStudentNames(std::vector<Student*>& studentVec){
	for(int i=0; i < studentVec.size(); i++){
		std::cout << studentVec.at(i)->getLastFirst() << std::endl;
	}// end for
}// end showStudentNames

void printStudents(std::vector<Student*>& studentVec){
	for(int i=0; i < studentVec.size(); i++){
		studentVec.at(i)->printStudent();
	}// end for
}// end printStudents


void findStudent(std::vector<Student*>& studentVec){
	std::string toMatch;
	std::cout << "Enter student's last name: ";
	std::cin >> toMatch;
	std::cout << '\n';
	
	std::cout << "Listing matches: " << std::endl;
	std::cout << '\n';
	
	int match = 0;
	for(int i = 0; i < studentVec.size(); i++){
		std::string studentName = studentVec.at(i)->getLastFirst();
		std::size_t pos = studentName.find(toMatch);

		if(pos  == 0){
			match = 1;
			studentVec.at(i)->printStudent();
		} else{
			match = 0;
		}// end if
	}// end for
	if(match == 0){
		std::cout << "No matches found." << std::endl;
	}//end if
}// end findStudent

void delStudents(std::vector<Student*>& studentVec){
	for(int i = 0; i < studentVec.size(); i++){
		delete studentVec.at(i);
	}// end for
}// end delStudents

/*
void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress

void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate

void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst() << std::endl;
  delete student;
} // end testStudent
*/
