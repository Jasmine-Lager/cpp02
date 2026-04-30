
#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	// testing all parts of the canonical form
	Fixed a; // default
	Fixed b(a); // copy
	Fixed c; // default

	c = b; // assignment

	// checking if the values are actually 0
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}