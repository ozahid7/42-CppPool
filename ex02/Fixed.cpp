#include "Fixed.hpp"

//comparison operators

bool Fixed::operator==(Fixed const &other)
{
	return _integer == other._integer;
}

bool Fixed::operator>(Fixed const &other)
{
	return _integer > other._integer;
}

bool Fixed::operator<(Fixed const &other)
{
	return _integer < other._integer;
}

bool Fixed::operator>=(Fixed const &other)
{
	return _integer >= other._integer;
}

bool Fixed::operator<=(Fixed const &other)
{
	return _integer <= other._integer;
}

bool Fixed::operator!=(Fixed const &other)
{
	return _integer != other._integer;
}

//arithmetic operators

Fixed &Fixed::operator+(Fixed const &other)
{
	_integer = _integer + other._integer;
	return *this;
}

Fixed &Fixed::operator-(Fixed const &other)
{
	_integer = _integer - other._integer;
	return *this;
}

Fixed &Fixed::operator*(Fixed const &other)
{
	_integer = _integer * other.toFloat();
	return *this;
}

Fixed &Fixed::operator/(Fixed const &other)
{
	_integer = _integer / other.toFloat();
	return *this;
}

//increment operators

Fixed &Fixed::operator++()
{
	++_integer;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	_integer++;
	return tmp;
}
Fixed &Fixed::operator--()
{
	--_integer;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	--_integer;
	return tmp;
}

//#########################################

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._integer < b._integer)
		return a;
	return b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a._integer < b._integer)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._integer > b._integer)
		return a;
	return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._integer > b._integer)
		return a;
	return b;
}

//#########################################

Fixed::Fixed(): _integer(0){
};

Fixed::Fixed(Fixed const & other){
	*this = other;
};

Fixed & Fixed::operator=(Fixed const & other){
	this->_integer = other._integer;
	return *this;
}

Fixed::~Fixed(){
};

Fixed::Fixed(const int a){
	_integer = a << _fractional;
}

Fixed::Fixed(const float b){
	_integer = roundf(b * (1 << _fractional));
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed){
	stream << fixed.toFloat();
	return stream;
}


float Fixed::toFloat(void) const{
	return  (float)(_integer) / (1 << _fractional);
};

int Fixed::toInt(void) const{
 	return _integer >> _fractional;
}
