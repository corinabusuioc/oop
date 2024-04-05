#include "BMW.h"
BMW::BMW()
{
	this->fuel_capacity = 59;
	this->fuel_consumption[0] = 7.9;
	this->speed[0] = 75;
	this->fuel_consumption[1] = 7;
	this->speed[1] = 90;
	this->fuel_consumption[2] = 8.4;
	this->speed[2] = 65;
	this->nume = new char[3];
	nume[0] = 'B';
	nume[1] = 'M';
	nume[2] = 'W';
	nume[3] = '\0';
}