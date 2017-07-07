#pragma once
#include "Pet.h"
#include "Bird.h"

class Parrot : public Pet, public Bird
{
public:
	Parrot(std::string n, std::string c, std::string t, size_t a, size_t w, bool f) : Pet(n, c, t, a, w), Bird(f) {}
	virtual ~Parrot(){}

	void Sound(){
		std::cout << "Sound:\tChik-Chirik" << std::endl;
	}
};