#include "Person.h"
#include "Phone_Book.h"


int main(){

	Person p1("Mike", "8044 285 65 33", "165 76 54");
	Person p2("Lisa", "37544 654 43 76");
	Person p3("Drake", "8029 165 76 54");
	Person p4("Clyain", "37529 908 65 43", "285 65 33");

	Phone_Book b;
	b.addPerson(p1);
	b.addPerson(p2);
	b.addPerson(p3);
	b.addPerson(p4);


	b.showAll();
	std::cout << "\n\n" << std::endl;
	b.showPerson("Mike");


	return 0;
}