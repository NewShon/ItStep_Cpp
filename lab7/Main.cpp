#include "Circle.h"
#include <iostream>
int main() {

	Circle c1(5, 5, 10.0);
	Circle c2(5, 5, 20.0);

	std::cout << (c1 == c2) << std::endl;
	std::cout << (c1 != c2) << std::endl;

	std::cout << (c1 > c2) << std::endl;
	std::cout << (c1 < c2) << std::endl;

	c1 = c2;
	std::cout << c1.getX() << " " << c1.getY() << " " << c1.getRadius() << std::endl;

	c1(5, 5, 10.0);
	std::cout << c1.getX() << " " << c1.getY() << " " << c1.getRadius() << std::endl;

	c1 += c2;
	std::cout << c1.getX() << " " << c1.getY() << " " << c1.getRadius() << std::endl;

	c1 -= c2;
	std::cout << c1.getX() << " " << c1.getY() << " " << c1.getRadius() << std::endl;

	c1++;
	std::cout << c1.getX() << " " << c1.getY() << " " << c1.getRadius() << std::endl;
	c2 = c1--;
	std::cout << c1.getX() << " " << c1.getY() << " " << c1.getRadius() << std::endl;
	std::cout << c2.getX() << " " << c2.getY() << " " << c2.getRadius() << std::endl;



	return 0;
}