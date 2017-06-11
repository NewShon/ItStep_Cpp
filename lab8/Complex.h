#pragma once
#include <iostream>
class Complex
{
	float real;
	float img;
public:
	Complex() : real(0), img(0) {}
	Complex(const float a, const float b) : real(a), img(b) {}
	Complex(const Complex& newComplex) : real(newComplex.real), img(newComplex.img) {}
	~Complex() = default;

	Complex& operator=(const Complex&);

	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, const Complex&);

	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator/=(const Complex&);
	Complex& operator*=(const Complex&);

	Complex operator++(int);
	Complex& operator++();
	Complex operator--(int);
	Complex& operator--();

	friend bool operator==(const Complex&, const Complex&);
	friend bool operator!=(const Complex&, const Complex&);
	friend bool operator>(const Complex&, const Complex&);
	friend bool operator<(const Complex&, const Complex&);
	friend bool operator>=(const Complex&, const Complex&);
	friend bool operator<=(const Complex&, const Complex&);

	Complex& operator()(float,float);

	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

	friend Complex operator+(const Complex&, const int);
	friend Complex operator-(const Complex&, const int);
	friend Complex operator*(const Complex&, const int);
	friend Complex operator/(const Complex&, const int);

	friend Complex operator+(const int, const Complex&);
	friend Complex operator-(const int, const Complex&);
	friend Complex operator*(const int, const Complex&);
	friend Complex operator/(const int, const Complex&);
};

