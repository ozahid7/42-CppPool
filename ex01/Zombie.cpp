#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->_name = name;
};

Zombie::~Zombie(){
	std::cout<<"I'm "<<this->_name<<" from destructor"<<std::endl;
};

void Zombie::setname(std::string name){
	_name = name;
};

std::string Zombie::getname(){
	return _name;
}

Zombie::Zombie(){};

void	Zombie::announce(){
	std::cout<<this->_name<<": BraiiiiiiinnnzzzZ"<<std::endl;
}