
#include <cmath> // need this for roundf()
#include "Fixed.hpp"

// default constructor - just sets everything to zero
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// int constructor - shift left by 8 bits
// this is basically multiplying by 256 (2^8)
Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// float constructor - multiply by 256 and round it
// we use roundf so 42.42 doesn't just get chopped off (truncated)
Fixed::Fixed(const float f) : _fixedPointValue(roundf(f * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

// tofloat - cast to float first, then divide by 256
// dividing by 2^8 moves the decimal point back where it belongs
float Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (1 << _fractionalBits));
}

// toint - shift right by 8 bits to drop the fractional part
// it's like the opposite of the int constructor
int Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

// ostream overload - uses tofloat() so cout knows what to print
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

// --- comparisons ---
// since they are both scaled by 256, we can just compare the raw ints
bool Fixed::operator>(const Fixed &other) const { return _fixedPointValue > other.getRawBits(); }
bool Fixed::operator<(const Fixed &other) const { return _fixedPointValue < other.getRawBits(); }
bool Fixed::operator>=(const Fixed &other) const { return _fixedPointValue >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed &other) const { return _fixedPointValue <= other.getRawBits(); }
bool Fixed::operator==(const Fixed &other) const { return _fixedPointValue == other.getRawBits(); }
bool Fixed::operator!=(const Fixed &other) const { return _fixedPointValue != other.getRawBits(); }

// --- arithmetic ---

// addition and subtraction are easy, scale stays the same
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(_fixedPointValue + other.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(_fixedPointValue - other.getRawBits());
	return res;
}

// multiplication: (a * 2^8) * (b * 2^8) = (a * b) * 2^16
// we need to shift right by 8 to get back to 2^8
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res;
	res.setRawBits((long)_fixedPointValue * other.getRawBits() >> _fractionalBits);
	return res;
}

// division: (a * 2^8) / (b * 2^8) = a / b (scale is gone!)
// we shift the top number left first so the result keeps the scale
Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(((long)_fixedPointValue << _fractionalBits) / other.getRawBits());
	return res;
}

// inc / dec
// the smallest epsilon is just 1 in raw bits (1/256)

Fixed &Fixed::operator++()
{ // pre
	_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{ // post
	Fixed tmp(*this);
	_fixedPointValue++;
	return tmp;
}

Fixed &Fixed::operator--()
{ // pre
	_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{ // post
	Fixed tmp(*this);
	_fixedPointValue--;
	return tmp;
}

// --- min / max ---
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }