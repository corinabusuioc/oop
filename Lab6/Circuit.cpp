#include "Circuit.h"
#include "enum.h"
#include "Car.h"
#include <iostream>
#include <stdio.h>
using namespace std;
void Circuit::SetLength(int i)
{
	this->l = i;
	this->nr = 0;
	this->car = new Car * [5];
}
void Circuit::SetWeather(Weather w)
{
	this->w = w;
}
void Circuit::AddCar(Car* c)
{
	this->car[this->nr] = new Car;
	car[this->nr]->fuel_capacity = c->fuel_capacity;
	for (int i = 0;i < 3;i++)
	{
		car[this->nr]->fuel_consumption[i] = c->fuel_consumption[i];
		car[this->nr]->speed[i] = c->speed[i];
	}
	char* nume = new char[10];
	int i;
	for (i = 0;c->nume[i] != '\0';i++)
		nume[i] = c->nume[i];
	car[this->nr]->nume = nume;
	car[this->nr]->nume[i] = '\0';
	this->nr++;
}
void Circuit::Race()
{
	this->rank = new timp[this->nr];
	for (int i = 0;i < this->nr;i++)
	{
		char* nume = new char[10];
		int j;
		for (j = 0;car[i]->nume[j] != '\0';j++)
			nume[j] = car[i]->nume[j];
		rank[i].nume = nume;
		rank[i].nume[j] = '\0';
		rank[i].t = this->l / car[i]->speed[w];
		if (car[i]->fuel_consumption[w] * l / 100 > car[i]->fuel_capacity)
			rank[i].ok = 0;
	}
	for (int i = 0;i < nr;i++)
		for (int j = i + 1;j < nr;j++)
			if (rank[i].t > rank[j].t)
				std::swap(rank[i], rank[j]);
}
void Circuit::ShowFinalRanks()
{
	for (int i = 0;i < this->nr;i++)
		if (rank[i].ok == 1)
			printf("%s\n", rank[i].nume);
}
void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0;i < this->nr;i++)
		if (rank[i].ok == 0)
			printf("%s\n", rank[i].nume);
}
Circuit::~Circuit()
{
	delete[]rank;
	for (int i = 0;i < this->nr;i++)
		delete car[i];
	delete[]car;
}
