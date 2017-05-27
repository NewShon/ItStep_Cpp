#include "Square.h"

Square::Square(float a) : a(a), b(0){}
Square::Square(float a, float b) : a(a), b(b) {}

float Square::getA()const{
	return this->a;
}
float Square::getB()const{
	return this->b;
}

void Square::setA(float a){
	this->a = a;
}
void Square::setB(float b){
	this->b = b;
}

void Square::getSquareArea()const{
	if (a > 0 && b > 0) getAB();
	else if (a > 0) getAA();
	else std::cout << "XPEHb" << std::endl;
}

float Square::getAA()const{
	std::cout << "AA = " << this->a * this->a << std::endl;
	return (this->a * this->a);
}
float Square::getAB()const{
	std::cout << "AB = " << this->a * this->b << std::endl;
	return (this->a * this->b);
}

Square::~Square()
{
}
