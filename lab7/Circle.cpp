#include "Circle.h"
#define _USE_MATH_DEFINES
#include <cmath>



Circle::Circle(const int x1, const int y1, const float radius1) : x(x1), y(y1), radius(radius1) {};

Circle::Circle(const Circle& newCircle) : x(newCircle.x), y(newCircle.y), radius(newCircle.radius) {}

Circle::Circle(Circle && newCircle) : x(newCircle.x), y(newCircle.y), radius(newCircle.radius) {
	newCircle.x = 0;
	newCircle.y = 0;
	newCircle.radius = 0;
}

int Circle::getX() const { return x; }
int Circle::getY() const { return y; }
float Circle::getRadius() const { return radius; }

Circle& Circle::operator=(const Circle& newCircle) {
	if (this == &newCircle) return *this;
	x = newCircle.x;
	y = newCircle.y;
	radius = newCircle.radius;
	return *this;
}
bool Circle::operator==(const Circle& newCircle) {
	if (x == newCircle.x &&
		y == newCircle.y &&
		radius == newCircle.radius) return true;
	return false;
}
bool Circle::operator!=(const Circle& newCircle) {
	return !(operator==(newCircle));
}

bool Circle::operator>(const Circle& newCircle) { return radius > newCircle.radius; }
bool Circle::operator<(const Circle& newCircle) { return radius < newCircle.radius; }

Circle& Circle::operator+=(const int newR) {
	radius += newR;
	return *this;
}
Circle& Circle::operator+=(const Circle& newCircle) {
	radius += newCircle.radius;
	return *this;
}

Circle& Circle::operator-=(const int newR) {
	radius -= newR;
	return *this;
}
Circle& Circle::operator-=(const Circle& newCircle) {
	radius -= newCircle.radius;
	return *this;
}

Circle& Circle::operator++() {
	++radius;
	return *this;
}
Circle Circle::operator++(int) {
	Circle tmp = *this;
	++radius;
	return tmp;
}
Circle& Circle::operator--() {
	--radius;
	return *this;
}
Circle Circle::operator--(int) {
	Circle tmp = *this;
	--radius;
	return tmp;
}

void Circle::operator()(const int x1) { x = x1; }
void Circle::operator()(const int x1, const int y1) { x = x1; y = y1; }
void Circle::operator()(const int x1, const int y1, const float r1) 
{ x = x1; y = y1; radius = r1; }

float Circle::getArea() const { return M_PI * radius * radius; }
float Circle::getLength() const { return 2 * M_PI * radius; }