// address.h

#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS

class Address {
	private:
		std::string street;
		std::string city;
		std::string state;
		std::string zip;
	public:
		Address();
		void init(std::string myStreet, std::string myCity, std::string myState, std::string myZip); 
		void printAddress();
};

#endif
