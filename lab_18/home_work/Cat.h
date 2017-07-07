#pragma once
#include "Pet.h"

class Cat : public Pet
{
public:
	Cat(std::string n, std::string c, std::string t, size_t a, size_t w) : Pet(n, c, t, a, w) {}
	virtual ~Cat(){}

	void Sound(){
		std::cout << "Sound:\tMeow" << std::endl;
	}
};