#pragma once
#include <iostream>
#include "A.h"
#include "B.h"
#include "X.h"

class Y : public A, public B
{
	double y;
public:
	Y(double a, int b) : A(a), B(b), X(999) { std::cout << "i'm class Y" << std::endl; }
	~Y() {
		std::cout << "Goodbye i'm class Y" << std::endl;
	}

	void print() {
		std::cout << "Hello i'm class Y" << std::endl;
	}
};


