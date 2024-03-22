#include "Sort.h"
#include <stdio.h>
using namespace std;
int main()
{
	Sort v1(7, 60, 100);
	Sort v2;
	int v[10] = {2, 5, 90, 4, 76, 12, 54, 60, 33, 19};
	int* p = v;
	Sort v3(p, 10);
	Sort v4(5, 12, 54, 33, 50, -1);
	char s[50] = "3,22,65,100,51,90";
	char* string = s;
	Sort v5(string);
	v1.InsertSort(1);
	v1.Print();
	v2.QuickSort(1, 0, v2.GetElementsCount()-1);
	v2.Print();
	v3.BubbleSort();
	v3.Print();
	v4.BubbleSort(1);
	v4.Print();
	v5.Print();
	printf("%d\n", v5.GetElementFromIndex(3));
}