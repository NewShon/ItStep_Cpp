#define _USE_MATH_DEFINES
#include "Novo_Triangle.h"
#include <cmath>

Novo_Triangle::Novo_Triangle(double s1, double s2, double s3) : 
	side1(s1), side2(s2), side3(s3), find_formula(1)
{
	check();
}
Novo_Triangle::Novo_Triangle(std::pair<double, double> sd_sd, double ang) : 
	side1(sd_sd.first), side2(sd_sd.second), angle1(ang), find_formula(2)
{
	side3 = std::sqrt(std::pow(side1, 2) + std::pow(side2, 2) - 2 * side1*side2*std::cos(angle1*M_PI / 180));
	check();
}
Novo_Triangle::Novo_Triangle(double s, std::pair<double, double> ang_ang) : 
	side1(s), angle1(ang_ang.first), angle2(ang_ang.second), find_formula(3)
{
	if (180 - angle1 - angle2 != 0) {
		allNULL();
	}
}


double Novo_Triangle::getArea() {
	if (find_formula == 1) {
		return get_Area_SideSideSide();
	}
	else if (find_formula == 2) {
		return get_Area_SideSideAngle();
	}
	else if (find_formula == 3) {
		return get_Area_SideAngleAngle();
	}
	return 0;
}


double Novo_Triangle::get_Area_SideSideSide() {
	const double p = side1 + side2 + side3;
	return std::sqrt(p*(p - side1)*(p - side2)*(p - side3));
}
double Novo_Triangle::get_Area_SideSideAngle() {
	return 0.5 * side1 * side2 * std::sin(angle1*M_PI/180);
}
double Novo_Triangle::get_Area_SideAngleAngle() {
	return (std::pow(side1, 2) / 2) * 
		((std::sin(angle1*M_PI / 180) * std::sin(angle2*M_PI / 180) / 
		std::sin(angle1*M_PI / 180 +angle2*M_PI / 180)));
}

void Novo_Triangle::allNULL() {
	side1 = 0;
	side2 = 0;
	side3 = 0;

	angle1 = 0;
	angle2 = 0;
	angle3 = 0;
}

bool Novo_Triangle::check() {
	if (side1 < side2 + side3 &&
		side2 < side1 + side3 &&
		side3 < side1 + side2) {
		allNULL();
		return false;
	}
	return true;
}


Novo_Triangle::~Novo_Triangle()
{
}
