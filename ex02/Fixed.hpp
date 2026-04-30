#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	// orthodox canonical form before
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	// constructors from ex01
	Fixed(const int n); // takes an int
	Fixed(const float f); // takes a float

	// member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const; // convert back to float
	int toInt(void) const; // convert back to int

	// --- ex02 additions ---

	// comparison operators
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// arithmetic operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// increment/decrement
	Fixed &operator++();   // pre-increment
	Fixed operator++(int); // post-increment
	Fixed &operator--();   // pre-decrement
	Fixed operator--(int); // post-decrement

	// static min/max functions
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	// ---------------------

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8; // always 8 per subject rules
};

// overload for the << operator to print the value easily
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif