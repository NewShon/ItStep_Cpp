#pragma once
#include "Pet.h"

class Dog : public Pet
{
public:
	Dog(std::string n, std::string c, std::string t, size_t a, size_t w) : Pet(n, c, t, a, w) {}
	virtual ~Dog(){}

	void Sound(){
		std::cout << "Sound:\tWouf" << std::endl;
	}
};
