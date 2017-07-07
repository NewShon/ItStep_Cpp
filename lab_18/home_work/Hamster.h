#pragma once
#include "Pet.h"

class Hamster : public Pet
{
public:
	Hamster(std::string n, std::string c, std::string t, size_t a, size_t w) : Pet(n, c, t, a, w) {}
	virtual ~Hamster(){}

	void Sound(){
		std::cout << "Sound:\tpwpgregebreb" << std::endl;
	}
};