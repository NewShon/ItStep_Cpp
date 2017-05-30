#include "Phone_Book.h"


Phone_Book::Phone_Book() {}


void Phone_Book::addPerson(Person p){
	book[position] = p;
	++position;
}
void Phone_Book::showPerson(std::string name){
	for (int i = 0; i < position; ++i)
		if (name == book[i].fio) book[i].showINFO();
}
void Phone_Book::showAll(){
	for (int i = 0; i < position; ++i)
		book[i].showINFO();
}


Phone_Book::~Phone_Book() {}
