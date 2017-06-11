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
	float a = ((c1.real*c2.real) + (c1.img*c2.img)) / ((c2.real*c2.real) + (c2.img*c2.img));
	float b = ((c1.img*c2.real) - (c1.real*c2.img)) / ((c2.real*c2.real) + (c2.img*c2.img));
	return Complex(a, b);
}

std::ostream& operator<<(std::ostream& os, const Complex& a) {
	char sign = '+';
	if (a.img <= 0) sign = '-';
	os << a.real << sign << a.img << "i";
	return os;
}
std::istream& operator>>(std::istream& is, Complex& a) {
	float r;
	float i;
	is >> r >> i;
	a(r, i);
	return is;
}

Complex Complex::operator++(int){
	Complex tmp = *this;
	++real;
	++img;
	return tmp;
}
Complex& Complex::operator++(){
	++real;
	++img;
	return *this;
}
Complex Complex::operator--(int){
	Complex tmp = *this;
	--real;
	--img;
	return tmp;
}
Complex& Complex::operator--(){
	--real;
	--img;
	return *this;
}

bool operator==(const Complex& c1, const Complex& c2) { return (c1.real == c2.real && c1.img == c2.img); }
bool operator!=(const Complex& c1, const Complex& c2) { return !(c1 == c2); }
bool operator>(const Complex& c1, const Complex& c2) { return (c1.real > c2.real && c1.img > c2.img); }
bool operator<(const Complex& c1, const Complex& c2) { return (c1.real < c2.real && c1.img < c2.img); }
bool operator>=(const Complex& c1, const Complex& c2) { return (c1.real >= c2.real && c1.img >= c2.img); }
bool operator<=(const Complex& c1, const Complex& c2) { return (c1.real <= c2.real && c1.img <= c2.img); }

Complex& Complex::operator()(float r, float i){
	real = r;
	img = i;
	return *this;
}

Complex operator+(const Complex& c, const int num){
	return Complex(c.real + num, c.img);
}
Complex operator-(const Complex& c, const int num){
	return Complex(c.real - num, c.img);
}
Complex operator*(const Complex& c, const int num){
	return Complex(c.real * num, c.img * num);
}
Complex operator/(const Complex& c, const int num){
	return Complex(c.real / num, c.img / num);
}

Complex operator+(const int num, const Complex& c){
	return Complex(c.real + num, c.img);
}
Complex operator-(const int num, const Complex& c){
	return Complex(c.real - num, c.img);
}
Complex operator*(const int num, const Complex& c){
	return Complex(c.real * num, c.img * num);
}
Complex operator/(const int num, const Complex& c){
	return Complex(c.real / num, c.img / num);
}