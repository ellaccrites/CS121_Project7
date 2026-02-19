// address.cpp

#include "address.h"

Address::Address(){
	Address::street = "N/A";
	Address::city = "N/A";
	Address::state = "N/A";
	Address::zip = "N/A";
}// end no param constructor

void Address::init(std::string street, std::string city, std::string state, std::string zip){
	Address::street = street;
	Address::city = city;
	Address::state = state;
	Address::zip = zip;
}// end init

void Address::printAddress(){
	std::cout << Address::street << std::endl;
	std::cout << Address::city << " " << Address::state << ", " << Address::zip << std::endl;
}// end printAddress


