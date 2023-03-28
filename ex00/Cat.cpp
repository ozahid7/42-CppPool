#include "Cat.hpp"

Cat::Cat(){
	std::cout<<"Cat default constructor called"<<std::endl;
	_type = "Cat";
}

Cat::Cat(Cat const &other){
	std::cout<<"Cat copy constructor called"<<std::endl;
	*this = other;
}

Cat::~Cat(){
	std::cout<<"Cat destructor called"<<std::endl;
}

Cat &Cat::operator=(Cat const &other){
	std::cout<<"Cat copy operator called"<<std::endl;
	_type = other._type;
	return *this;
}

std::string Cat::getType(){
	return _type;
}

void	Cat::makeSound(){
	std::cout<<"Sound of Cat"<<std::endl;
}