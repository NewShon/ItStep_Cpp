#include "Complex.h"

Complex& Complex::operator=(const Complex& newComplex) {
	if (this == &newComplex) return *this;
	real = newComplex.real;
	img = newComplex.img;
	return *this;
}

Complex operator+(const Complex& c1, const Complex& c2) {
	return Complex(c1.real + c2.real, c1.img + c2.img);
}
Complex operator-(const Complex& c1, const Complex& c2) {
	return Complex(c1.real - c2.real, c1.img - c2.img);
}

Complex operator*(const Complex& c1, const Complex& c2) {
	float a = c1.real*c2.real + c1.img*c2.img;
	float b = c1.img*c2.real + c1.real*c2.img;
	return Complex(a, b);
}
Complex operator/(const Complex& c1, const Complex& c2) {
	return Complex(c1.real - c2.real, c1.img - c2.img);
}

std::ostream& operator<<(std::ostream& os, const Complex& a) {
	char sign = '+';
	if (a.img <= 0) sign = '-';
	os << a.real << sign << a.img << "i";
	return os;
}