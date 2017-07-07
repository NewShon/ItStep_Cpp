#pragma once
#include "Automobile.h"

class Taxi : public Automobile
{
	double tarif = 5;
	double money;
	static size_t taxi_counter;

public:
	Taxi(std::string ma, std::string mo, std::string y, double s) :
		Automobile(ma, mo, y, s) {
		TaxiPP();
	}

	virtual ~Taxi() {}

	size_t getTaxiCounter(){
		return taxi_counter;
	}

	void setTarif(double t){
		tarif = t;
	}
	double getTarif(){
		return tarif;
	}
	double getMoney(){
		return money;
	}

	double Fare(double time){
		return tarif * computeDistance(time);
	}

	void getInfo(){
		Automobile::getInfo();
		std::cout << "Tarif:\t" << tarif << std::endl;
	}

	std::string move(){
		return "Valim bokom";
	}

private:
	static void TaxiPP(){
		++taxi_counter;
	}
};

size_t Taxi::taxi_counter = 0;