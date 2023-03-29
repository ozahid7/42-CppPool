#include "WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout<<"WrongCat default constructor called"<<std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &other){
	std::cout<<"WrongCat copy constructor called"<<std::endl;
	*this = other;
}

WrongCat::~WrongCat(){
	std::cout<<"WrongCat destructor called"<<std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other){
	std::cout<<"WrongCat copy operator called"<<std::endl;
	this->_type = other._type;
	return *this;
}

std::string WrongCat::getType() const{
	return _type;
}

void	WrongCat::makeSound() const{
	std::cout<<"wrong sound of cat"<<std::endl;
}