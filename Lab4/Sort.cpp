#include "Sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cstdarg>

Sort::Sort(int count, int mini, int maxi)
{
	this->v = new int[count];
	srand(time(0));
	for (int i = 0;i < count;i++)
		this->v[i] = mini + (rand() % (maxi - mini + 1));
	this->count = count;
}

Sort::Sort(int* v, int count)
{
	this->v = new int[count];
	for (int i = 0;i < count;i++)
		this->v[i] = v[i];
	this->count = count;
}
Sort::Sort(int count, ...)
{
	this->v = new int[count];
	va_list list;
	int i;
	va_start(list, count);
	for (i = 0; i < count; i++)
	{
		this->v[i] = va_arg(list, int);
	}
	va_end(list);
	this->count = count;
}
Sort::Sort(char *string)
{
	int i = 0, nr = 0, count=0;
	this->count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ',')
			this->count++;
		i++;
	}
	this->count++;
	i = 0;
	this->v = new int[this->count];
	while (string[i] != '\0')
	{
		if (string[i] != ',')
			nr = nr * 10 + string[i] - '0';
		else
		{
			this->v[count] = nr;
			nr = 0;
			count++;
		}
		i++;
	}
	this->v[count] = nr;
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < this->count; i++)
	{
		int x = this->v[i];
		int p = i - 1;
		while (p >= 0 && !ascendent ? (this->v[p] < x) : (this->v[p] > x))
			this->v[p + 1] = this->v[p], p--;
		this->v[p + 1] = x;
	}
}
void Sort::QuickSort(bool ascendent, int st, int dr)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (ascendent ? this->v[i] > v[j] : v[i] < v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(v, st, i - 1);
		QuickSort(v, i + 1, dr);
	}
}
void Sort::BubbleSort(bool ascendent)
{
	bool sortat;
	do
	{
		sortat = true;
		for (int i = 0; i < this->count - 1; i++)
			if (ascendent ? this->v[i] > v[i+1] : v[i] < v[i+1])
			{
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortat = false;
			}
	} while (!sortat);
}
void Sort::Print()
{
	for (int i = 0;i < this->count;i++)
		printf("%d ", this->v[i]);
	printf("\n");
}
int Sort::GetElementsCount()
{
	return this->count;
}
int Sort::GetElementFromIndex(int index)
{
	if (index < this->count)
		return this->v[index];
	else
	{
		printf("%s", "Index invalix");
		return -1;
	}
}