#pragma once
#include <string>
using namespace std;
class students
{
	string nume;
	float math, english, history, average;
public:
	string SetName(string s);
	float SetM(float a);
	float SetE(float a);
	float SetH(float a);
	float Average();
};

