#pragma once
#include "Person.h"
#include <array> 
class Phone_Book
{
	int position{ 0 };
	Person* book = new Person[20];

public:
	Phone_Book();

	void addPerson(Person);
	void showPerson(std::string);
	void showAll();

	~Phone_Book();
};

