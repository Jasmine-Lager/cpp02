
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	// orthodox canonical form needs these 4 things
	Fixed(); // default constructor
	Fixed(const Fixed &other); // copy constructor
	Fixed &operator=(const Fixed &other); // copy assignment operator
	~Fixed(); // destructor

	// just basic raw bit access for now
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8; // always 8 per subject
};

#endif