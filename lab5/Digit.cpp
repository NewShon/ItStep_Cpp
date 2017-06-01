#include "Digit.h"


Digit::Digit() : digit(1) {}
Digit::Digit(const int x) : digit(x) {}
Digit::~Digit() {}

int Digit::getDigit()const {
	return digit;
}

Digit Digit::operator+(const Digit& newDigit) {
	Digit tmp;
	tmp.digit = digit + newDigit.digit;
	return tmp;
}

Digit Digit::operator+(const int newDigit) {
	Digit tmp;
	tmp.digit = digit + newDigit;
	return tmp;
}
bool Digit::operator>(const Digit& newDigit) {
	return digit > newDigit.digit;
}