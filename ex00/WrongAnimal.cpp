#include "WrongAnimal.hpp"

void WrongAnimal::makeSound(){
	std::cout<<"What type of WrongAnimal"<<std::endl;
}

std::string WrongAnimal::getType(){
	return type;
}

WrongAnimal::WrongAnimal(){
	std::cout<<"WrongAnimal default constructor called"<<std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &other){
	std::cout<<"WrongAnimal copy constructor called"<<std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(){
	std::cout<<"WrongAnimal destructor called"<<std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other){
	std::cout<<"WrongAnimal copy operator called"<<std::endl;
	type = other.type;
	return *this;
}
