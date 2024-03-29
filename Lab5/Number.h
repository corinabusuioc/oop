#pragma once
class Number
{
	int base, nr10;
	char* val;
public:
	Number(const char* value, int base); 
	Number(int val);
	~Number();
	friend Number& operator+(Number& n, Number& m);
	friend Number& operator-(Number& n, Number& m);
	char operator[](int index);
	bool operator>(Number& n);
	Number& operator=(int nr);
	Number& operator=(const char* value);
	Number& operator+=(Number& n);
	friend Number& operator--(Number& n);
	friend Number& operator--(Number& n, int val); //?
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); 
	int  GetBase(); 
};