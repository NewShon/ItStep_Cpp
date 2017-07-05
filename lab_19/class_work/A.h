#pragma once
#include <iostream>
#include "X.h"

class A : public virtual X
{
	double a;
public:
	A() : X(5){ std::cout << "i'm class A" << std::endl; }
	A(double aa) : a(aa), X(aa) { std::cout << "a = " << a << std::endl; }
	virtual ~A() {
		std::cout << "Goodbye i'm class A" << std::endl;
	}

	void print() {
		std::cout << "Hello i'm class A" << std::endl;
	}
};

