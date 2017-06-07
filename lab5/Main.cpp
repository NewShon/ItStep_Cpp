#include "Digit.h"

int main() {

	Digit d1(10);
	std::cout << (d1+10).getDigit() << std::endl;
	std::cout << (10+d1).getDigit() << std::endl;

	std::cout << (d1 - 10).getDigit() << std::endl;
	std::cout << (10 - d1).getDigit() << std::endl;

	std::cout << (d1 * 10).getDigit() << std::endl;
	std::cout << (10 * d1).getDigit() << std::endl;

	std::cout << (d1 / 10).getDigit() << std::endl;
	std::cout << (10 / d1).getDigit() << std::endl;


	std::cout << d1 << std::endl;
	std::cin >> d1;
	std::cout << d1 << std::endl;

	return 0;
}