#include "Math.h"
#include <iostream>
using namespace std;
int main()
{
	Math m;
	printf("Sum of 32 and 453 = %d\n", m.Add(32, 453));
	printf("Sum of 21, 54 and 2 = %d\n", m.Add(21, 54, 2));
	printf("Sum of 12.75 and 12.3 = %d\n", m.Add(12.75, 12.3));
	printf("Sum of 13.2, 32.2 and 3.3 = %d\n", m.Add(13.2, 32.2, 3.3));
	printf("Multiplication of 4 and 16 = %d\n", m.Mul(4, 16));
	printf("Multiplication of 5, 21 and 85 = %d\n", m.Mul(5, 21, 85));
	printf("Multiplication of 2.5 and 8.75 = %d\n", m.Mul(2.5f, 8.75f));
	printf("Multiplication of 2.6, 8.9 and 34 = %d\n", m.Mul(2.6f, 8.9f, 34.0));
	printf("Sum of 4, 20, 25 and 30 = %d\n", m.Add(4, 4, 20, 25, 30));
	printf("Sum of 34 and 996 = %s\n", m.Add("34", "996"));
}