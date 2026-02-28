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
  showStudentNames(studentVec);
  std::cout << std::endl;
  printStudents(studentVec);
  delStudents(studentVec);

  return 0;
} // end main

/*
std::string menu(){
	std::cout << "0) quit" << std::endl;
	std::cout << "1) print all student names" << std::endl;
	std::cout << "2) print all student data" << std::endl;
	std::cout << "3) find a student" << std::endl;
	std::cout << std::endl;

	std::cout << "Choose an option: ";
	std::cin >> std::string userChoice;

	return userChoice;
} // end menu
*/

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
		ss >> studentString;

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

/*
void findStudent(std::vector<Student*>& studentVec){

}// end findStudent
*/


void delStudents(std::vector<Student*>& studentVec){
	for(int i = 0; i < studentVec.size(); i++){
		delete studentVec.at(i);
	}// end for
}// end delStudents


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
