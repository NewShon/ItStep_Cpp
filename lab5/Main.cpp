#include "Digit.h"

int main() {

	Digit d1(10);
	Digit d2(5);

	std::cout << -d2.getDigit() << std::endl;

	std::cout << (d1 + d2).getDigit() << std::endl;
	std::cout << (d2 + 5).getDigit() << std::endl;

	std::cout << (d1 - d2).getDigit() << std::endl;
	std::cout << (d2 - 5).getDigit() << std::endl;

	std::cout << (d1 * d2).getDigit() << std::endl;
	std::cout << (d2 * 5).getDigit() << std::endl;

	std::cout << (d1 / d2).getDigit() << std::endl;
	std::cout << (d2 / 5).getDigit() << std::endl;

	std::cout << (d1 % d2).getDigit() << std::endl;
	std::cout << (d2 % 5).getDigit() << std::endl;

	std::cout << (d1 > d2) << std::endl;
	std::cout << (d1 < d2) << std::endl;
	std::cout << (d1 == d2) << std::endl;
	std::cout << (d1 != d2) << std::endl;
	std::cout << (d1 >= d2) << std::endl;
	std::cout << (d1 <= d2) << std::endl;


	return 0;
}