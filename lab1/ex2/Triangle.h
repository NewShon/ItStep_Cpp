#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include<string>
#include<cmath>
class Triangle
{
	float a;
	float b;
	float c;
	float h;
	float angle;
	bool bl;

public:
	Triangle(float, float);
	Triangle(float, float, float, bool);
	Triangle(float, float, float);
	
	
	float getA()const;
	float getB()const;
	float getC()const;
	float getH()const;
	float getAngle()const;

	void setA(float);
	void setB(float);
	void setC(float);
	void setH(float);
	void setAngle(float);

	void getTriangleArea()const;

	~Triangle();


private:
	float getCH()const;
	float getABA()const;
	float getABC()const;


	
};

