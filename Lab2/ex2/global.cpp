#pragma once
#include "global.h"
#include <string>
using namespace std;
int cmpname(string a, string b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
}
int cmpmath(float a, float b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
}
int cmpenglish(float a, float b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
}
int cmphistory(float a, float b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
}
int cmpaverage(float a, float b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
}