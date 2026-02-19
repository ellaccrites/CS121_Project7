// student.h

#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include "address.h"
#include "date.h"

class Student {
	private:
		std::string firstName;
		std::string lastName;
		Address studentAddy;
		Date birthDate;
		Date gradDate;
		int credits;
	public:
		Student();
		void init(std::string studentString);
		void printStudent();
		std::string  getLastFirst();

};

#endif

