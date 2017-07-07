#pragma once
#include <iostream>

class Bird{
	bool fly;
	
public:
	Bird(bool f) : fly(f) {}
	virtual ~Bird() = 0;

	void setFly(bool f){
		fly = f;
	}
	void Fly(){
		std::cout << "Fly:\t" << std::boolalpha << fly << std::endl;
	}
};
Bird::~Bird(){}