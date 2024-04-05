#pragma once
#include "Car.h"
#include "enum.h"
class Circuit
{
	Car** car;
	int l, nr;
	struct timp{
		int ok = 1;
		float t;
		char* nume;
	} *rank;
	Weather w;
public:
	void SetLength(int i);
	void SetWeather(Weather w);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks(); 
	void ShowWhoDidNotFinish();
};

