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

	d1 = d2;
	std::cout << -d1.getDigit() << std::endl;

	int x = d1;
	double y = d2;
	char c = d1;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << c << std::endl;

	d1(100);
	std::cout << d1.getDigit() << std::endl;

	return 0;
}
