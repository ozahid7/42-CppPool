#include "Fixed.hpp"


Fixed::Fixed(): _integer(0){
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
	std::cout<<"Int constructor called"<<std::endl;
	_integer = a << _fractional;
}

Fixed::Fixed(const float b){
	std::cout<<"Float constructor called"<<std::endl;
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

void	Fixed::setRawBits(int const raw){
	_integer = raw;
}

int		Fixed::getRawBits() const{
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->_integer;
};
