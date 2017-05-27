#include "Student.h"

Student::Student(std::string name, std::string birth) : fio(name), bd(birth)
{
}

void Student::set_FIO(std::string f){
	fio = f;
}
//void Student::set_BD(std::string f) {
//	bd = f;
//}
void Student::set_Phone(std::string f) {
	phone = f;
}
void Student::set_City(std::string f) {
	city = f;
}
void Student::set_Univer(std::string f) {
	university = f;
}
void Student::set_ID_group(std::string f) {
	id_group = f;
}




void Student::get_FIO() const {
	std::cout << "FIO: " << fio << std::endl;
}
void Student::get_BD() const {
	std::cout << "Birthday: " << bd << std::endl;
}
void Student::get_Phone() const {
	std::cout << "Phone: " << phone << std::endl;
}
void Student::get_City() const {
	std::cout << "City: " << city << std::endl;
}
void Student::get_Univer() const {
	std::cout << "University: " << university << std::endl;
}
void Student::get_ID_group() const {
	std::cout << "ID group: " << id_group << std::endl;
}



Student::~Student()
{
}
