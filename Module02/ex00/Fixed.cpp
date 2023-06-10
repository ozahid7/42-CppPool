#include "Fixed.hpp"


Fixed::Fixed() : _value(0){
	std::cout<<"Default constructor called"<<std::endl;
};

Fixed::Fixed(Fixed const & other){
	std::cout<< "Copy constructor called"<<std::endl;
	*this = other;
};

Fixed & Fixed::operator=(Fixed const & other){
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->_value = other.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw){
	_value = raw;
}

int		Fixed::getRawBits() const{
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->_value;
};

Fixed::~Fixed(){
	std::cout<<"Destructor called"<<std::endl;
};
