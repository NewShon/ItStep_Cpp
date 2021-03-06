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

	Digit& operator=(const Digit&);
	Digit& operator++();
	Digit operator++(int);
	Digit& operator--();
	Digit operator--(int);

	operator int();
	operator double();
	operator char();

	void operator()(const int);


	friend Digit operator+(const int, const Digit&);
	friend Digit operator-(const int, const Digit&);
	friend Digit operator-(const int, const Digit&);
	friend Digit operator*(const int, const Digit&);
	friend Digit operator/(const int, const Digit&);


	friend std::ostream& operator<<(std::ostream&, const Digit&);
	friend std::istream& operator>>(std::istream&, Digit&);

};

