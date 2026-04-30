
#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	// this uses our overloaded << operator
	// it should show the numbers in a readable float format
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	// now testing the toint() conversion
	// should just chop off the decimals
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// // __________________________
	// // negative numbers - fixed point should handle these fine if we use signed ints
	// std::cout << "\nthe non-mandatory tests..." << std::endl;
	// Fixed const e(-10.5f);
	// std::cout << "e (float -10.5) is " << e << ", as int: " << e.toInt() << std::endl;

	// // rounding logic - 0.5 should round up (or to nearest) because of roundf()
	// Fixed const f(1.5f);
	// std::cout << "f (1.5) rounds to " << f.toInt() << std::endl;

	// // raw bits directly - 256 in raw bits should be exactly 1.0 because 256 / 2^8 = 1
	// Fixed g;
	// g.setRawBits(256);
	// std::cout << "raw bits 256 is " << g << " and raw value is " << g.getRawBits() << std::endl;

	return 0;
}
