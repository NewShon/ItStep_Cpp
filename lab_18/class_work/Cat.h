#pragma once
#include "Pet.h"
#include <iostream>

class Cat : public Pet
{
public:
	Cat(std::string n, size_t w, std::string c) : Pet(n,w,c) {}
	~Cat() {}

	void sound() override{
		std::cout << "My sound is meouw" << std::endl;
	}
	int attack();
};


