#pragma once
#include <iostream>
class Complex
{
	float real { 0 };
	float img { 0 };
public:
	Complex() {}
	Complex(const float a, const float b) : real(a), img(b) {}
	Complex(const Complex& newComplex) : real(newComplex.real), img(newComplex.img) {}
	~Complex() {}

	Complex& operator=(const Complex&);

	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

	friend std::ostream& operator<<(std::ostream& os, const Complex& a);
};

