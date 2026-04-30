
#include "Fixed.hpp"

// initializing to 0 as required
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor - usually just calls the assignment operator
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	// we use *this to call the operator= below
	*this = other;
}

// assignment operator - need to check for self-assignment (a = a)
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// just copying the raw integer value
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this); // return the object for chaining (a = b = c)
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}