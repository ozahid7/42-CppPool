#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->_name = name;
};
Zombie::~Zombie(){
	std::cout<<"I'm "<<this->_name<<" from destructor"<<std::endl;
};
Zombie::Zombie(){};

void	Zombie::announce(){
	std::cout<<this->_name<<": BraiiiiiiinnnzzzZ"<<std::endl;
}