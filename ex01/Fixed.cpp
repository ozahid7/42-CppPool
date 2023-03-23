#include "Fixed.hpp"


Fixed::Fixed() : _integer(0){
	std::cout<<"Default constructor called"<<std::endl;
};

Fixed::Fixed(Fixed const & other){
	std::cout<< "Copy constructor called"<<std::endl;
	*this = other;
};

Fixed & Fixed::operator=(Fixed const & other){
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->_integer = other.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw){
	_integer = raw;
}

int		Fixed::getRawBits() const{
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->_integer;
};

Fixed::~Fixed(){
	std::cout<<"Destructor called"<<std::endl;
};

Fixed::Fixed(const int a){
	_integer = a << _fractional;
}

Fixed::Fixed(const int b){
	_integer = b;

}

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed){

	stream << fixed.toFloat();
	return stream;
}


float Fixed::toFloat(void) const{
	return  (float)_integer * 256;
};

int Fixed::toInt(void) const{
 	return _integer << _fractional;
}


