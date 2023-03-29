#include "Cat.hpp"

Cat::Cat(){
	std::cout<<"Cat default constructor called"<<std::endl;
	_type = "Cat";
	_brain = new Brain;
}

Cat::Cat(Cat const &other){
	std::cout<<"Cat copy constructor called"<<std::endl;
	*this = other;
}

Cat::~Cat(){
	std::cout<<"Cat destructor called"<<std::endl;
	delete _brain;
}

Cat &Cat::operator=(Cat const &other){
	std::cout<<"Cat copy operator called"<<std::endl;
	_type = other._type;
	printf("%p | %p \n", *_brain, *other._brain);
	if (_brain)
		std::cout<<"yes \n";
	return *this;
}

std::string Cat::getType() const{
	return _type;
}

void	Cat::makeSound() const{
	std::cout<<"Sound of Cat"<<std::endl;
}

Brain Cat::getbrain()
{
	return Brain();
}