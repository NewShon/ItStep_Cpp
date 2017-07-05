#pragma once
#include "Pet.h"
#include <iostream>
#include <string>

class Dog : public Pet
{
	std::string owner_name;
public:
	Dog(std::string n, size_t w, std::string c, std::string on) : Pet(n, w, c), owner_name(on) {}
	~Dog(){}

	void sound() override {
		std::cout << "My sound is Wouf!!!" << std::endl;
	}

	int eat();
	void set_owner_name(std::string);
	std::string get_owner_name();
};

