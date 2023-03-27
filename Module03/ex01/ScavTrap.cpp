#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout<<"ScavTrap default constructor called"<<std::endl;
	_name = "ScavTrap Default Name";
	_attackDamage = 20;
	_energyPoints = 50;
	_hitPoints = 100;
}

ScavTrap::ScavTrap(std::string name){
	std::cout<<"ScavTrap Paramitrised constructor called"<<std::endl;
	_name = name;
	_attackDamage = 20;
	_energyPoints = 50;
	_hitPoints = 100;
}

ScavTrap::ScavTrap(ScavTrap &other){
	std::cout<<"ScavTrap Copy constructor called"<<std::endl;
	*this = other;
}

ScavTrap::~ScavTrap(){
	std::cout<<"ScavTrap Destructor Called"<<std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other){
	std::cout<<"ScavTrap Operator Overload called"<<std::endl;
	this->_name = other._name;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	this->_hitPoints = other._hitPoints;
	return *this; 
}

void ScavTrap::guardGate(){
	std::cout<<"ScavTrap is now in Gate keeper mode"<<std::endl;
}

unsigned int ScavTrap::gethit()
{
	return _hitPoints;
}

unsigned int ScavTrap::getenerg()
{
	return _energyPoints;
}

void ScavTrap::attack(const std::string &target){
	if (_hitPoints < 1 || _energyPoints < 1)
		std::cout<<"ScavTrap No Point Left"<<std::endl;
	else{
		std::cout<<"ScavTrap "<<_name<<" attacks "<<target<<" causing "<<_attackDamage<<" points of damage!"<<std::endl;
		_energyPoints--;
	}
}
