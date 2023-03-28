#include "Dog.hpp"

Dog::Dog(){
	std::cout<<"Dog default constructor called"<<std::endl;
	_type = "Dog";
}

Dog::Dog(Dog const &other){
	std::cout<<"Dog copy constructor called"<<std::endl;
	*this = other;
}

Dog::~Dog(){
	std::cout<<"Dog destructor called"<<std::endl;
}

Dog &Dog::operator=(Dog const &other){
	std::cout<<"Dog copy operator called"<<std::endl;
	_type = other._type;
	return *this;
}

std::string Dog::getType(){
	return _type;
}

void	Dog::makeSound(){
	std::cout<<"Soound of Dog"<<std::endl;
}