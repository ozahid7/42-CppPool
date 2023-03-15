#include "Zombie.hpp"

Zombie::~Zombie(){
	std::cout<<"I'm "<<this->_name<<" from destructor"<<std::endl;
};

void Zombie::setname(std::string name){
	_name = name;
};

Zombie::Zombie(){};

void	Zombie::announce(){
	std::cout<<this->_name<<": BraiiiiiiinnnzzzZ"<<std::endl;
}