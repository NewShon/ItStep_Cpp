#pragma once
#include <string>
#include <iostream>

class Pet{
	std::string name;
	std::string color;
	std::string type;
	size_t age;
	size_t weight;
	
	std::string owner = "";

public:
	Pet(std::string n, std::string c, std::string t, size_t a, size_t w) : name(n), color(c), type(t), age(a), weight(w) {}
	virtual ~Pet() = 0;

	void setOwner(std::string owner_name){
		owner = owner_name;
	}
	void OwnerName(){
		std::cout << "Owner:\t" << owner << std::endl;
	}
	void Name(){
		std::cout << "Name:\t" << name << std::endl;
	}
	void Color(){
		std::cout << "Color:\t" << color << std::endl;
	}
	void Type(){
		std::cout << "Type:\t" << type << std::endl;
	}
	void Age(){
		std::cout << "Age:\t" << age << std::endl;
	}
	void Weight(){
		std::cout << "Weight:\t" << weight << std::endl;
	}
};

Pet::~Pet(){}
