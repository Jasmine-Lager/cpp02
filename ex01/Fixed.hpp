
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	// orthodox canonical form stuff
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	// new constructors for ex01
	Fixed(const int n); // takes an int
	Fixed(const float f); // takes a float

	// member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const; // convert back to float
	int toInt(void) const; // convert back to int

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8; // always 8 per subject rules
};

// overload for the << operator to print the value easily
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif