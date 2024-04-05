#include "Volvo.h"
Volvo::Volvo()
{
	this->fuel_capacity = 71;
	this->fuel_consumption[0] = 9.1;
	this->speed[0] = 80;
	this->fuel_consumption[1] = 8.3;
	this->speed[1] = 87;
	this->fuel_consumption[2] = 9.9;
	this->speed[2] = 73;
	this->nume = new char[5];
	nume[0] = 'V';
	nume[1] = 'o';
	nume[2] = 'l';
	nume[3] = 'v';
	nume[4] = 'o';
	nume[5] = '\0';
}