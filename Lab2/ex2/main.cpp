#include "students.h"
#include "global.h"
#include <stdio.h>
int main()
{
	students a, b, c, d, e; 
	printf("%d\n", cmpname(a.SetName("Popescu Andrei"), b.SetName("Anton Ana")));
	printf("%d\n", cmpmath(a.SetM(9.5), b.SetM(10)));
	printf("%d\n", cmpenglish(a.SetE(8.75), b.SetE(8.25)));
	printf("%d\n", cmphistory(a.SetH(7.25), b.SetH(7.25)));
	printf("%d\n", cmpaverage(a.Average(), b.Average()));
}