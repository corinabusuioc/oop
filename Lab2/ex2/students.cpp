#include "students.h"
string students::SetName(string s)
{
	this->nume = s;
	return s;
}
float students::SetM(float a)
{
	this->math = a;
	return a;
}
float students::SetE(float a)
{
	this->english = a;
	return a;
}
float students::SetH(float a)
{
	this->history = a;
	return a;
}
float students::Average()
{
	this->average = (this->math + this->english + this->history) / 3;
	return average;
}


