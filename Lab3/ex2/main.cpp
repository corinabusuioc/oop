#include "Canvas.h"
#include <iostream>
int main()
{
	Canvas c(50,50);
    c.DrawCircle(45, 45, 15, '*');
    c.FillCircle(10, 10, 7, '*');
    c.DrawRect(5, 25, 10, 35, '*');
    c.FillRect(15, 30, 27, 49, '*');
    c.SetPoint(0, 0, '*');
    c.DrawLine(20, 2, 40, 27, '*');
    c.Print(); 
    c.Clear(); 
}