#include "Fixed.hpp"

//comparison operators

bool Fixed::operator==(Fixed const &other)
{
	return _value == other._value;
}

bool Fixed::operator>(Fixed const &other)
{
	return _value > other._value;
}

bool Fixed::operator<(Fixed const &other)
{
	return _value < other._value;
}

bool Fixed::operator>=(Fixed const &other)
{
	return _value >= other._value;
}

bool Fixed::operator<=(Fixed const &other)
{
	return _value <= other._value;
}

bool Fixed::operator!=(Fixed const &other)
{
	return _value != other._value;
}

//arithmetic operators

Fixed &Fixed::operator+(Fixed const &other)
{
	_value = _value + other._value;
	return *this;
}

Fixed &Fixed::operator-(Fixed const &other)
{
	_value = _value - other._value;
	return *this;
}

Fixed &Fixed::operator*(Fixed const &other)
{
	_value = _value * other._value;
	return *this;
}

Fixed &Fixed::operator/(Fixed const &other)
{
	_value = _value / other._value;
	return *this;
}

//increment operators

Fixed &Fixed::operator++()
{
	++_value;
	return *this;
}

Fixed &Fixed::operator++(int)
{
	Fixed tmp;
	_value++;
	return tmp;
}
Fixed &Fixed::operator--()
{
	--_value;
	return *this;
}
Fixed &Fixed::operator--(int)
{
	Fixed tmp;

	--_value;
	return tmp;
}

//#########################################

int Fixed::min(int &a, int &b)
{
	if (a < b)
		return a;
	return b;
}

int Fixed::min(int &a, int &b, int)
{
	if (a < b)
		return a;
	return b;
}

int Fixed::max(int &a, int &b)
{
	if (a > b)
		return a;
	return b;
}

int Fixed::max(int &a, int &b, int)
{
	if (a > b)
		return a;
	return b;
}

//#########################################

Fixed::Fixed() : _value(0){
	std::cout<<"Default constructor called"<<std::endl;
};

Fixed::Fixed(Fixed const & other){
	std::cout<< "Copy constructor called"<<std::endl;
	*this = other;
};

Fixed & Fixed::operator=(Fixed const & other){
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->_value = other._value;
	return *this;
}

Fixed::~Fixed(){
	std::cout<<"Destructor called"<<std::endl;
};
