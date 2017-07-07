#pragma once
#include "Transport.h"
#include <iostream>

class Automobile : public Transport
{
	std::string mark;
	std::string model;
	std::string year;
	double speed;

public:
	Automobile(std::string ma, std::string mo, std::string y, double s) :
		mark(ma), model(mo), year(y), speed(s) {}
	virtual ~Automobile() = 0;

	void setSpeed(double s){
		speed = s;
	}
	std::string getMark() const{
		return model;
	}
	std::string getModel() const{
		return mark;
	}
	std::string getYear() const{
		return year;
	}
	double getSpeed() const{
		return speed;
	}

	double computeDistance(double time){
		return time * speed;
	}

	void getInfo(){
		std::cout << "Mark:\t" << mark << std::endl;
		std::cout << "Model:\t" << model << std::endl;
		std::cout << "Year:\t" << year << std::endl;
		std::cout << "Speed:\t" << speed << std::endl;
	}
};

Automobile::~Automobile(){}