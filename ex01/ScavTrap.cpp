#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout<<"ScavTrap default constructor called"<<std::endl;
	setname("ScavTrap Default Name");
	setattackdamage(20);
	setenergypoint(50);
	sethitpoint(100);
}

ScavTrap::ScavTrap(std::string name){
	setname(name);
}

ScavTrap::ScavTrap(ScavTrap &other){
	*this = other;
}

ScavTrap::~ScavTrap(){
	std::cout<<"ScavTrap Destructor Called"<<std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other){
	(void) other;
	return *this; 
}

void ScavTrap::guardGate(){
	std::cout<<"ScavTrap is now in Gate keeper mode"<<std::endl;
}

void ScavTrap::attack(const std::string &target){
	std::cout<<"ScavTrap "<<_name<<" attacks "<<target<<" causing "<<_attackDamage<<" points of damage!"<<std::endl;
}
