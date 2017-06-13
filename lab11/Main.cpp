#include <iostream>
#include "Pair.h"

int main() {

	Pair<int,char>p(5,'a');

	std::cout << p.getFirst() << std::endl;
	std::cout << p.getSecond() << std::endl;

	return 0;
}