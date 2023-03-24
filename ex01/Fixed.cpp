#include "Fixed.hpp"


Fixed::Fixed(){
	std::cout<<"Default constructor called"<<std::endl;
};

Fixed::Fixed(Fixed const & other){
	std::cout<< "Copy constructor called"<<std::endl;
	*this = other;
};

Fixed & Fixed::operator=(Fixed const & other){
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->_integer = other._integer;
	return *this;
}

Fixed::~Fixed(){
	std::cout<<"Destructor called"<<std::endl;
};

Fixed::Fixed(const int a){
	std::cout<<"before##########"<<a<<std::endl;
	std::cout<<"Int constructor called"<<std::endl;
	_integer = a << _fractional;
	std::cout<<"after##########"<<_integer<<std::endl;
}

Fixed::Fixed(const float b){
	std::cout<<"before##########"<<b<<std::endl;
	std::cout<<"Float constructor called"<<std::endl;
	_integer = roundf(b * (1 << _fractional));
	std::cout<<"after##########"<<_integer<<std::endl;
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


