#include <iostream>
#include "Array.h"

int main()
{
	Array<int> v(10);
	v += 3;
	v.Insert(0, 7);
	v += 0;
	v += 6;
	v.Sort();
	std::cout << "Elementele sortate din v sunt: ";
	for (int i = 0;i < v.GetSize();i++)
		std::cout << v[i] << ' ';
	std::cout << std::endl << "Pozitia elementului 6 in v este " << v.BinarySearch(6) << std::endl;
	Array<char> c(7);
	c += 'f';
	c += '5';
	c += '}';
	c.Insert(2, '@');
	c += 'a';
	c.Insert(6, '3');
	std::cout << "Elementele din a sunt: ";
	for (int i = 0;i < c.GetSize();i++)
		std::cout << c[i] << ' ';
	std::cout << std::endl << "Pozitia elementului 1 in c este " << c.Find('1') << std::endl;
	Array<float> a(-2);
	Array<std::string> s(6);
	s += "abc";
	s += "bcc";
	s += "1h";
	s.Insert(0, "mere");
	s.Sort(compareDesc);
	std::cout << "Elementele sortate din s sunt: ";
	for (int i = 0;i < s.GetSize();i++)
		std::cout << s[i] << ' ';
	std::cout << std::endl << "Pozitia elementului mere in s este " << s.BinarySearch("mere",compareDesc) << std::endl;
	Array<float> f(10);
	f += 1.5f;
	f += 66;
	f += 3.75;
	GenericCompare<float> comparator;
	std::cout << "Pozitia elementului 3.75 in f este " << f.Find(3.75f, &comparator) << std::endl;
	f += 1.25;
	f += 5.34;
	f.Sort(&comparator);
	f.Delete(1.5);
	std::cout << "Elementele sortate din f sunt: ";
	for (int i = 0;i < f.GetSize();i++)
		std::cout << f[i] << ' ';
	return 0;
}