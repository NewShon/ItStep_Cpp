#include "Digit.h"

unsigned int Digit::counter = 0;

Digit::Digit() : digit(0) { ++counter; }
Digit::Digit(const int x) : digit(x) { ++counter; }
Digit::Digit(const double x) : digit(x) { ++counter; }
Digit::Digit(const Digit& newDigit) { this->digit = newDigit.digit; ++counter; }
Digit::Digit(Digit&& newDigit) {
	this->digit = newDigit.digit;
	newDigit.digit = 0;
	++counter;
}
Digit::~Digit() {}

int Digit::getDigit()const {
	return digit;
}
int Digit::getCounter()const {
	return Digit::counter;
}
void Digit::setDigit(int d) {
	this->digit = d;
}



Digit Digit::operator-() {
	Digit tmp;
	tmp.digit = -(digit);
	return tmp;
}

Digit Digit::operator+(const Digit& newDigit) {
	Digit tmp;
	tmp.digit = digit + newDigit.digit;
	return tmp;
}

Digit Digit::operator+(const int num) {
	Digit tmp;
	tmp.digit = digit + num;
	return tmp;
}

Digit Digit::operator-(const Digit& newDigit) {
	Digit tmp;
	tmp.digit = this->digit - newDigit.digit;
	return tmp;
}
Digit Digit::operator-(const int num) {
	Digit tmp;
	tmp.digit = this->digit - num;
	return tmp;
}

Digit Digit::operator*(const Digit& newDigit) {
	Digit tmp;
	tmp.digit = this->digit * newDigit.digit;
	return tmp;
}
Digit Digit::operator*(const int num) {
	Digit tmp;
	tmp.digit = this->digit * num;
	return tmp;
}

Digit Digit::operator/(const Digit& newDigit) {
	Digit tmp;
	tmp.digit = this->digit / newDigit.digit;
	return tmp;
}
Digit Digit::operator/(const int num) {
	Digit tmp;
	tmp.digit = this->digit / num;
	return tmp;
}

Digit Digit::operator%(const Digit& newDigit) {
	Digit tmp;
	tmp.digit = this->digit % newDigit.digit;
	return tmp;
}
Digit Digit::operator%(const int num) {
	Digit tmp;
	tmp.digit = this->digit % num;
	return tmp;
}



bool Digit::operator>(const Digit& newDigit) { return digit > newDigit.digit; }
bool Digit::operator<(const Digit& newDigit) { return digit < newDigit.digit; }
bool Digit::operator==(const Digit& newDigit) { return digit == newDigit.digit; }
bool Digit::operator!=(const Digit& newDigit) { return digit != newDigit.digit; }
bool Digit::operator>=(const Digit& newDigit) { return digit >= newDigit.digit; }
bool Digit::operator<=(const Digit& newDigit) { return digit <= newDigit.digit; }

Digit& Digit::operator=(const Digit& newDigit) {
	if (this == &newDigit) return *this;
	digit = newDigit.digit;
	return *this;
}
Digit& Digit::operator++() {
	++digit;
	return *this;
}
Digit Digit::operator++(int) {
	Digit tmp = *this;
	++digit;
	return tmp;
}
Digit& Digit::operator--() {
	--digit;
	return *this;
}
Digit Digit::operator--(int) {
	Digit tmp = *this;
	--digit;
	return tmp;
}

Digit::operator int() { return digit; }
Digit::operator double() { return (double)digit; }
Digit::operator char() { return (char)digit; }

void Digit::operator()(const int i) { digit = i; }



Digit operator+(const int num, const Digit& dig1) {
	return Digit(num + dig1.digit);
}
Digit operator-(const int num, const Digit& dig1) {
	return Digit(num - dig1.digit);
}
Digit operator*(const int num, const Digit& dig1) {
	return Digit(num * dig1.digit);
}
Digit operator/(const int num, const Digit& dig1) {
	return Digit(num / dig1.digit);
}



std::ostream& operator<<(std::ostream& os, const Digit& a) {
	os << a.digit;
	return os;
}
std::istream& operator>>(std::istream& is, Digit& a) {
	int tmp;
	is >> tmp;
	a.setDigit(tmp);
	return is;
}