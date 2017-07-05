#pragma once
#include <iostream>
#include "X.h"

class B : public virtual X
{
	int b;
public:
	B() : X(10) { std::cout << "i'm class B" << std::endl; }
	B(int bb) : b(bb), X(bb) { std::cout << "b = " << b << std::endl; }
	virtual ~B() {
		std::cout << "Goodbye i'm class B" << std::endl;
	}

	void print() {
		std::cout << "Hello i'm class B" << std::endl;
	}
};

