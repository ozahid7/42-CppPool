#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout<<"ClapTrap Default Constructor Called"<<std::endl;
	_name = "ClapTrap default _name";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap(){
	std::cout<<"ClapTrap Destructor called"<<std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other){
	std::cout<<"ClapTrap operator overload Called"<<std::endl;
	_attackDamage = other._attackDamage;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_name = other._name;
	return *this;
}

void ClapTrap::attack(const std::string &target){
	if (_hitPoints < 1 || _energyPoints < 1)
		std::cout<<"Clap Trap No Point Left"<<std::endl;
	else{
	std::cout<<"ClapTrap "<<_name<<" attacks "<<target<<" causing "<<_attackDamage<<" points of damage!"<<std::endl;
	_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints < 1 || _energyPoints < 1)
		std::cout<<"ClapTrap No Point Left"<<std::endl;
	else{
		std::cout<<"ClapTrap "<<_name<<" take "<<amount<<" damage "<<std::endl;
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_hitPoints < 1 || _energyPoints < 1)
		std::cout<<"ClapTrap No Point Left"<<std::endl;
	else{
		std::cout<<"ClapTrap "<<_name<<" Repairs itself with "<<amount<<" amount"<<std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}

ClapTrap::ClapTrap(std::string name){
	std::cout<<"ClapTrap Pramitrised Constructor Called"<<std::endl;
	_name = name;
}

ClapTrap::ClapTrap(ClapTrap &other){
	std::cout<<"ClapTrap copy Constructor Called"<<std::endl;
	*this = other;
}

unsigned int ClapTrap::getattackdam()
{
	return _attackDamage;
}