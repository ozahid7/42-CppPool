#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout<<"Default Constructor Called"<<std::endl;
	_name = "default _name";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 1;
}

ClapTrap::~ClapTrap(){
	std::cout<<"Destructor called"<<std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other){
	_attackDamage = other._attackDamage;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_name = other._name;
	return *this;
}

void ClapTrap::attack(const std::string &target){
	if (_hitPoints < 1 || _energyPoints < 1)
		std::cout<<"No Point Left"<<std::endl;
	else{
	std::cout<<"ClapTrap "<<_name<<" attacks "<<target<<" causing "<<_attackDamage<<" points of damage!"<<std::endl;
	_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints < 1 || _energyPoints < 1)
		std::cout<<"No Point Left"<<std::endl;
	else{
		std::cout<<"ClapTrap "<<_name<<" take "<<amount<<" damage "<<std::endl;
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_hitPoints < 1 || _energyPoints < 1)
		std::cout<<"No Point Left"<<std::endl;
	else{
		std::cout<<"ClapTrap "<<_name<<" Repairs itself with "<<amount<<" amount"<<std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}

unsigned int ClapTrap::getenerg()
{
	return _energyPoints;
}

unsigned int ClapTrap::gethit(){
	return _hitPoints;
}

ClapTrap::ClapTrap(std::string name){
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 1;
}
