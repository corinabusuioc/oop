#include "RangeRover.h"
RangeRover::RangeRover()
{
	this->fuel_capacity = 90;
	this->fuel_consumption[0] = 11.6;
	this->speed[0] = 85;
	this->fuel_consumption[1] = 10;
	this->speed[1] = 100;
	this->fuel_consumption[2] = 13.2;
	this->speed[2] = 74;
	this->nume = new char[10];
	nume[0] = 'R';
	nume[1] = 'a';
	nume[2] = 'n';
	nume[3] = 'g';
	nume[4] = 'e';
	nume[5] = 'R';
	nume[6] = 'o';
	nume[7] = 'v';
	nume[8] = 'e';
	nume[9] = 'r';
	nume[10] = '\0';
}