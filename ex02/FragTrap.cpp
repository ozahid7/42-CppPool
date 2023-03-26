#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout<<"FragTrap default constructor called"<<std::endl;
	_name = "FragTrap Default Name";
	_attackDamage = 30;
	_energyPoints = 100;
	_hitPoints = 100;
}

FragTrap::FragTrap(std::string name){
	_name = name;
	_attackDamage = 30;
	_energyPoints = 100;
	_hitPoints = 100;
}

FragTrap::FragTrap(FragTrap &other){
	*this = other;
}

FragTrap::~FragTrap(){
	std::cout<<"FragTrap Destructor Called"<<std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other){
	this->_name = other._name;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	this->_hitPoints = other._hitPoints;
	return *this; 
}

void FragTrap::highFivesGuys(void){
	std::cout<<" high fives "<<std::endl;
}

unsigned int FragTrap::gethit()
{
	return _hitPoints;
}

unsigned int FragTrap::getenerg()
{
	return _energyPoints;
}
