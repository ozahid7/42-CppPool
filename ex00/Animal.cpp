#include "Animal.hpp"

void Animal::makeSound() const{
	std::cout<<"Sound of animal"<<std::endl;
}

std::string Animal::getType() const{
	return type;
}

Animal::Animal(){
	std::cout<<"Animal default constructor called"<<std::endl;
	type = "Animal";
}

Animal::Animal(Animal const &other){
	std::cout<<"Animal copy constructor called"<<std::endl;
	*this = other;
}

Animal::~Animal(){
	std::cout<<"Animal destructor called"<<std::endl;
}

Animal &Animal::operator=(Animal const &other){
	std::cout<<"Animal copy operator called"<<std::endl;
	type = other.type;
	return *this;
}
