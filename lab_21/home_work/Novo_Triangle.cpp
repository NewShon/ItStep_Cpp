#include "Novo_Triangle.h"



Novo_Triangle::Novo_Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3), find_formula(1)
{
}
Novo_Triangle::Novo_Triangle(std::pair<double, double> sd_sd, double ang) : side1(sd_sd.first), side2(sd_sd.second), angle1(ang), find_formula(2)
{
}
Novo_Triangle::Novo_Triangle(double s, std::pair<double, double> ang_ang) : side1(s), angle1(ang_ang.first), angle2(ang_ang.second), find_formula(3)
{
}


double Novo_Triangle::getArea() {
	if (find_formula == 1) {
		return SSS();
	}
	else if (find_formula == 2) {
		return SSU();
	}
	else if (find_formula == 3) {
		return SUU();
	}
	return 0;
}


double Novo_Triangle::SSS() {
}
double Novo_Triangle::SSU() {
}
double Novo_Triangle::SUU() {
}



Novo_Triangle::~Novo_Triangle()
{
}
