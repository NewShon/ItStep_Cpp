#include "Digit.h"

int main() {

	Digit d1;
	Digit d2;

	std::cout << (d1 + d2).getDigit() << std::endl;
	std::cout << (d2 + 5).getDigit() << std::endl;
	std::cout << (d1 > d2) << std::endl;
	return 0;
}