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
int Digit::getCounter()const{
	return Digit::counter;
}
void Digit::setDigit(int d){
	this->digit = d;
}

Digit Digit::operator-(){
	Digit tmp;
	tmp.digit = -(this->digit);
	return tmp;
}

Digit Digit::operator+(const Digit& newDigit) {
	Digit tmp;
	tmp.digit = this->digit + newDigit.digit;
	return tmp;
}
Digit Digit::operator+(const int num) {
	Digit tmp;
	tmp.digit = this->digit + num;
	return tmp;
}

Digit Digit::operator-(const Digit& newDigit){
	Digit tmp;
	tmp.digit = this->digit - newDigit.digit;
	return tmp;
}
Digit Digit::operator-(const int num){
	Digit tmp;
	tmp.digit = this->digit - num;
	return tmp;
}

Digit Digit::operator*(const Digit& newDigit){
	Digit tmp;
	tmp.digit = this->digit * newDigit.digit;
	return tmp;
}
Digit Digit::operator*(const int num){
	Digit tmp;
	tmp.digit = this->digit * num;
	return tmp;
}

Digit Digit::operator/(const Digit& newDigit){
	Digit tmp;
	tmp.digit = this->digit / newDigit.digit;
	return tmp;
}
Digit Digit::operator/(const int num){
	Digit tmp;
	tmp.digit = this->digit / num;
	return tmp;
}

Digit Digit::operator%(const Digit& newDigit){
	Digit tmp;
	tmp.digit = this->digit % newDigit.digit;
	return tmp;
}
Digit Digit::operator%(const int num){
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