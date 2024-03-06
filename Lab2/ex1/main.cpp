#include "NumberList.h"
#include <stdio.h>
using namespace std;
int main()
{
	NumberList v;
	bool ok;
	v.Init();
	ok=v.Add(6);
	ok=v.Add(3);
	ok=v.Add(7);
	ok=v.Add(5);
	ok=v.Add(9);
	v.Sort();
	v.Print();
}