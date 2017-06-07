#include "Complex.h"
#include <iostream>

int main() {
	Complex c1(5, 3);
	Complex c2(5, -2);

	std::cout << c1*c2 << std::endl;
}