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
	return *this;
}

std::string WrongCat::getType(){
	return _type;
}

void	WrongCat::makeSound(){
	std::cout<<"--------WrongMewo--------"<<std::endl;
}