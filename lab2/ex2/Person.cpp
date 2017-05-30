#include "Person.h"

Person::Person() : fio("None"), mobile_phone("None"), home_phone("None") {}
Person::Person(std::string f) : fio(f), mobile_phone("None"), home_phone("None") {}
Person::Person(std::string f, std::string m) : fio(f), mobile_phone(m), home_phone("None") {}
Person::Person(std::string f, std::string m, std::string h) : fio(f), mobile_phone(m), home_phone(h) {}


void Person::showINFO(){
	std::cout << "FIO:\t\t" << this->fio << std::endl;
	std::cout << "Mobile phone:\t" << this->mobile_phone << std::endl;
	std::cout << "Home phone:\t" << this->home_phone << std::endl;
	std::cout << std::endl;
}


Person::~Person() {}
