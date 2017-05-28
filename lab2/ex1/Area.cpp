#include "Area.h"

int Area::counter = 0;

void Area::getSquareArea()const{
	if (a > 0 && b > 0)square2();
	else if (a > 0)square1();
}
void Area::getParallelogramArea()const{
	if (a > 0 && b > 0 && angle > 0) Parallelogram2();
	else if (a > 0 && b > 0)Parallelogram1();
}
void Area::getRhombusArea()const{
	if (a > 0 && b > 0 && angle > 0) Parallelogram2();
	else if (a > 0 && b > 0)Parallelogram1();
}

float Area::square1()const{
	std::cout << "S = " << a*a << std::endl;
	++counter;
	return a*a;
}
float Area::square2()const{
	std::cout << "S = " << a*b << std::endl;
	++counter;
	return a*b;
}

float Area::Parallelogram1()const{
	std::cout << "S = " << a*b << std::endl;
	++counter;
	return  a*b;
}
float Area::Parallelogram2()const{
	std::cout << "S = " << a*b*sin(angle*M_PI / 180) << std::endl;
	++counter;
	return  a*b*sin(angle*M_PI / 180);
}

float Area::Rhombus1()const{
	std::cout << "S = " << a*b << std::endl;
	++counter;
	return a*b;
}
float Area::Rhombus2()const{
	std::cout << "S = " << 0.5*a*b << std::endl;
	++counter;
	return  0.5*a*b;
}

int Area::getCount() {
	std::cout << "Counter = " << counter << std::endl;
	return counter;
}

Area::~Area(){ --counter; }
