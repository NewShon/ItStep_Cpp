#include "Triangle.h"

Triangle::Triangle(float c, float h) :c(c), h(h), a(0), bl(0), angle(0) {}
Triangle::Triangle(float a, float b, float angle, bool b_) : a(a), b(b), angle(angle), bl(b), c(0), h(0) {}
Triangle::Triangle(float a, float b, float c) : a(a), b(b), c(c), h(0), angle(0), bl(0) {}


float Triangle::getA()const{
	return this->a;
}
float Triangle::getB()const{
	return this->b;
}
float Triangle::getC()const{
	return this->c;
}
float Triangle::getH()const{
	return this->h;
}
float Triangle::getAngle()const{
	return this->angle;
}

void Triangle::setA(float a){
	this->a = a;
}
void Triangle::setB(float b){
	this->b = b;
}
void Triangle::setC(float c){
	this->c = c;
}
void Triangle::setH(float h){
	this->h = h;
}
void Triangle::setAngle(float angle){
	this->angle = angle;
}

void Triangle::getTriangleArea()const{
	if (c > 0 && h > 0) getCH();
	else if (bl > 0) getABA();
	else if (a > 0 && b > 0 && c > 0) getABC();
	else std::cout << "XPEHb" << std::endl;
}

float Triangle::getCH()const{
	float s = (0.5 * c*h);
	std::cout << "CH = "<< s << std::endl;
	return s;
}
float Triangle::getABA()const{
	float s = 0.5 * a * b * sin(angle*M_PI/180);
	std::cout << "ABAngle = " << s << std::endl;
	return s;
}
float Triangle::getABC()const{
	float p = (a + b + c)/2;
	float s = sqrt(p*(p-a)*(p-b)*(p-c));
	std::cout << "ABC = " << s << std::endl;
	return s;
}


Triangle::~Triangle(){}
