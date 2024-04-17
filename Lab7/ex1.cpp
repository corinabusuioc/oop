#include <iostream>

float operator"" _Kelvin(unsigned long long int x)
{
    return x - 273.15;
}

float operator"" _Fahrenheit(unsigned long long int x)
{
    return (x - 32.0)/1.8;
}

int main() 
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << "300 Kelvin in Celsius: " << a << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << std::endl;
    return 0;
}
