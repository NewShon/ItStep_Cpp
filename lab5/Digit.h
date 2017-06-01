#pragma once
#include <iostream>
class Digit
{
	int digit;

public:
	Digit();
	explicit Digit(const int x);
	~Digit();

	int getDigit()const;

	Digit operator+(const Digit& newDigit);
	Digit operator+(const int newDigit);
	bool operator>(const Digit& newDigit);
};

