#pragma once

class Circle
{
	int x;
	int y;
	float radius;

public:
	Circle() = delete;
	Circle(const int, const int, const float);
	Circle(const Circle&);
	Circle(Circle&&);
	~Circle() = default;

	int getX() const;
	int getY() const;
	float getRadius() const;

	Circle& operator=(const Circle&);
	//Circle& operator=(Circle&&);

	bool operator==(const Circle&);
	bool operator!=(const Circle&);
	bool operator>(const Circle&);
	bool operator<(const Circle&);

	Circle& operator+=(const int);
	Circle& operator+=(const Circle&);

	Circle& operator-=(const int);
	Circle& operator-=(const Circle&);

	Circle& operator++();
	Circle operator++(int);

	Circle& operator--();
	Circle operator--(int);

	void operator()(const int);
	void operator()(const int, const int);
	void operator()(const int, const int, const float);

	float getArea() const;
	float getLength() const;

};

