#pragma once
#include <iostream>
class Digit
{
	int digit;
	static unsigned int counter;

public:
	Digit();
	explicit Digit(const int x);
	explicit Digit(const double x);
	Digit(const Digit&);
	Digit(Digit&&);
	~Digit();

	int getDigit()const;
	int getCounter()const;
	void setDigit(int);

	Digit operator-();

	Digit operator+(const Digit&);
	Digit operator+(const int);

	Digit operator-(const Digit&);
	Digit operator-(const int);

	Digit operator*(const Digit&);
	Digit operator*(const int);

	Digit operator/(const Digit&);
	Digit operator/(const int);

	Digit operator%(const Digit&);
	Digit operator%(const int);

	bool operator>(const Digit&);
	bool operator<(const Digit&);
	bool operator==(const Digit&);
	bool operator!=(const Digit&);
	bool operator>=(const Digit&);
	bool operator<=(const Digit&);
};

