#pragma once
#include <iostream>

class X
{
	int x;
public:
	X() : x(42) {
		std::cout << "i'm class X = " << x << std::endl;
	}
	X(int xx) : x(xx) {
		std::cout << "i'm class X = " << x << std::endl;
	}
	virtual ~X() {
		std::cout << "Goodbye i'm class X" << std::endl;
	}

	void useMe() {
		std::cout << "xxxxxxxxxxx" << std::endl;
	}

	void print() {
		std::cout << "XXX" << std::endl;
	}
};

