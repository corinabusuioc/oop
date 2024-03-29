#include "Number.h"
#include <iostream>
Number::Number(const char* value, int base)
{
	int i = 0;
	this->nr10 = 0;
	this->base = base;
	while (value[i] != '\0')
	{
		if (value[i] >= '0' && value[i] <= '9')
			this->nr10 = this->nr10 * base + value[i] - '0';
		else
			this->nr10 = this->nr10 * base + value[i] - 'A' + 10;
		i++;
	}
	this->val = new char[i];
	i = 0;
	while (value[i] != '\0')
	{
		this->val[i] = value[i];
		i++;
	}
	this->val[i] = '\0';
}
Number::Number(int val)
{
	this->base = 10;
	this->nr10 = val;
	int i = 0;
	while (val)
	{
		val /= 10;
		i++;
	}
	if (this->nr10 == 0)
		i = 1;
	this->val = new char[i];
	i = 0;
	val = this->nr10;
	while (val)
	{
		this->val[i] = val % 10;
		i++;
		val /= 10;
	}
	this->val[i] = '\0';
	for (int j = 0;j < i / 2;j++)
		std::swap(this->val[j], this->val[i - j - 1]);
}
Number::~Number()
{
	delete[]val;
}
Number& operator+(Number& n, Number& m)
{
	int s = n.nr10 + m.nr10, i = 0;
	int b = std::max(n.base, m.base);
	char* sum = new char[std::max(n.GetDigitsCount(), m.GetDigitsCount()) + 1];
	while (s)
	{
		int r = s % b;
		if (r < 10)
			sum[i] = r + '0';
		else
			sum[i] = r + 'A' - 10;
		i++;
		s /= b;
	}
	sum[i] = '\0';
	for (int j = 0;j < i / 2;j++)
		std::swap(sum[j], sum[i - j - 1]);
	static Number add(sum,b);
	Number a(sum, b);
	add = a;
	return add;
}
Number& operator-(Number& n, Number& m)
{
	int s = abs(n.nr10 - m.nr10), i = 0;
	int b = std::max(n.base, m.base);
	char* sum = new char[std::max(n.GetDigitsCount(), m.GetDigitsCount()) + 1];
	while (s)
	{
		int r = s % b;
		if (r < 10)
			sum[i] = r + '0';
		else
			sum[i] = r + 'A' - 10;
		i++;
		s /= b;
	}
	sum[i] = '\0';
	for (int j = 0;j < i / 2;j++)
		std::swap(sum[j], sum[i - j - 1]);
	if (n.nr10 < m.nr10)
	{
		for (int j = i;j > 0;j--)
			sum[j] = sum[j - 1];
		sum[0] = '-';
		sum[i + 1] = '\0';
	}
	static Number scadere (sum,b);
	Number a(sum, b);
	scadere = a;
	return scadere;
}
char Number::operator[](int index)
{
	return this->val[index];
}
bool Number::operator>(Number& n)
{
	if (this->nr10 > n.nr10)
		return true;
	return false;
}
Number& Number::operator=(int nr)
{
	this->nr10 = nr;
	int i = 0;
	while (nr)
	{
		int r = nr % this->base;
		if (r < 10)
			this->val[i] = r + '0';
		else
			this->val[i] = r + 'A' - 10;
		i++;
		nr /= this->base;
	}
	this->val[i] = '\0';
	for (int j = 0;j < i / 2;j++)
		std::swap(this->val[j], this->val[i - j - 1]);
	return (*this);
}
Number& Number::operator=(const char* value)
{
	this->val = (char*)value;
	int i = 0;
	this->nr10 = 0;
	while (value[i] != '\0')
	{
		if (value[i] >= '0' && value[i] <= '9')
			this->nr10 = this->nr10 * this->base + value[i] - '0';
		else
			this->nr10 = this->nr10 * this->base + value[i] - 'A' + 10;
		i++;
	}
	return (*this);
}
Number& Number::operator+=(Number& n)
{
	int s = this->nr10 + n.nr10, i = 0;
	while (s)
	{
		int r = s % this->base;
		if (r < 10)
			this->val[i] = r + '0';
		else
			this->val[i] = r + 'A' - 10;
		i++;
		s /= this->base;
	}
	this->val[i] = '\0';
	for (int j = 0;j < i / 2;j++)
		std::swap(this->val[j], this->val[i - j - 1]);
	return (*this);
}
Number& operator--(Number& n)
{
	int i = 0, l = n.GetDigitsCount();
	char c;
	char* v = new char[l];
	for (i = 0;i < l - 1;i++)
		v[i] = n[i+1];
	v[l - 1] = '\0';
	n.val = v;
	return (n);
}
Number& operator--(Number& n, int val)
{
	n.val[n.GetDigitsCount() - 1] = '\0';
	return (n);
}
void Number::SwitchBase(int newBase)
{
	this->base = newBase;
	int i = 0, nr=this->nr10;
	while (nr)
	{
		int r = nr % newBase;
		if (r < 10)
			this->val[i] = r + '0';
		else
			this->val[i] = r + 'A' - 10;
		i++;
		nr /= newBase;
	}
	this->val[i] = '\0';
	for (int j = 0;j < i / 2;j++)
		std::swap(this->val[j], this->val[i - j - 1]);
}
void Number::Print()
{
	printf("%s\n", this->val);
}
int  Number::GetDigitsCount()
{
	int i = 0;
	while (this->val[i] != '\0')
		i++;
	return i;
}
int  Number::GetBase()
{
	return this->base;
}