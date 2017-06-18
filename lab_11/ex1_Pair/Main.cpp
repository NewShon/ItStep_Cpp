#include <iostream>
#include "Pair.h"

int main() {

	Pair<int, int> p(3, 4);
	std::cout << p.getFirst() << std::endl;
	std::cout << p.getSecond() << std::endl;
	p.make_pair(5, 6);
	std::cout << p.getFirst() << std::endl;
	std::cout << p.getSecond() << std::endl;
	
	Pair<bool, bool> p2(true);
	std::cout << p2.getFirst() << std::endl;
	std::cout << p2.getSecond() << std::endl;
	p2.make_pair(false);
	std::cout << p2.getFirst() << std::endl;
	std::cout << p2.getSecond() << std::endl;

	return 0;
}