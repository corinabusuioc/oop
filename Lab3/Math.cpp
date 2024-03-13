#include "Math.h"
#include <iostream>
#include <cstring>
using namespace std;
int* p = new int[100];
int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c) 
{
	return a * b * c;
}
int Math::Add(int count, ...) // sums up a list of integers
{
	int sum = 0;
	for (int i = 0; i < count ; i++)
		sum = sum + p[i];
	return sum;
}
char* Math::Add(const char* a, const char* b)
{
	if (a == NULL || b == NULL)
		return nullptr;
	int l1 = strlen(a), l2 = strlen(b), i, j, v, t=0;
	int l = max(l1,l2) + 1;
	char *sum = new char[l];
	for (i = l1-1, j = l2-1; i >= 0, j >= 0; i--, j--)
	{
		v = t + a[i] + b[j] - '0' - '0';
		t = 0;
		if (v > 9)
			t = v / 10;
		sum[l] = v % 10 + '0';
		l--;
	}
	for(;i>=0;i--)
	{
		v = t + a[i] - '0';
		t = 0;
		if (v > 9)
			t = v / 10;
		sum[l] = v % 10 + '0';
		l--;
	}
	for (;j >= 0;j--)
	{
		v = t + b[j] - '0';
		t = 0;
		if (v > 9)
			t = v / 10;
		sum[l] = v % 10 + '0';
		l--;
	}
	if(l==0)
		sum[0] = t + '0';
	//sum[l] = '\0';
	if (sum[0] == '0')
		return sum + 1;
	return sum;
}
