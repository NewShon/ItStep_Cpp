#pragma once


class Shape {
public:
	virtual ~Shape() {};
	virtual double getArea() = 0;
};