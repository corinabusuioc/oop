#include "Seat.h"
Seat::Seat()
{
	this->fuel_capacity = 40;
	this->fuel_consumption[0] = 5;
	this->speed[0] = 70;
	this->fuel_consumption[1] = 4.6;
	this->speed[1] = 75;
	this->fuel_consumption[2] = 5.5;
	this->speed[2] = 62;
	this->nume = new char[4];
	nume[0] = 'S';
	nume[1] = 'e';
	nume[2] = 'a';
	nume[3] = 't';
	nume[4] = '\0';
}