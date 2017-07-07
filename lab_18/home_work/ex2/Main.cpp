#include "Taxi.h"

int main(){

	Taxi taxi("Opel", "Asta", "2003", 60);
	taxi.getInfo();
	
	std::cout << "Fare:\t" << taxi.Fare(1.5) << std::endl;

	std::cout << "Fare:\t" << taxi.move() << std::endl;

	return 0;
}