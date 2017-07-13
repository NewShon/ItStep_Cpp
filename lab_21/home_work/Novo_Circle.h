#pragma once
#define _USE_MATH_DEFINES
#include "Novo_Shape.h"
#include <cmath>

class Novo_Circle : public Novo_Shape
{
	double radius;
	double center;
public:
	Novo_Circle(double r, double c) :
	radius(r), center(c) {}
	~Novo_Circle() {}

	double getArea() {
		return M_PI*std::pow(radius, 2);
	}

	double get_radius() const { return radius; }
	double get_center() const { return center; }
};