#include "Fiat.h"
Fiat::Fiat()
{
	this->fuel_capacity = 57;
	this->fuel_consumption[0] = 5.4;
	this->speed[0] = 72;
	this->fuel_consumption[1] = 4.8;
	this->speed[1] = 80;
	this->fuel_consumption[2] = 6.0;
	this->speed[2] = 67;
	this->nume = new char[4];
	nume[0] = 'F';
	nume[1] = 'i';
	nume[2] = 'a';
	nume[3] = 't';
	nume[4] = '\0';
}