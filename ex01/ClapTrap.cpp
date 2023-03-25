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
	_name = name;
}

ClapTrap::ClapTrap(ClapTrap &other){
	*this = other;
}


////////////getters//////////////////

unsigned int ClapTrap::getenergypoint()
{
	return _energyPoints;
}

unsigned int ClapTrap::gethitpoint(){
	return _hitPoints;
}

unsigned int ClapTrap::getattackdamage(){
	return _attackDamage;
}

std::string ClapTrap::getname(){
	return _name;
}

///////////////setters///////////////

void ClapTrap::setname(std::string name){
	_name = name;
}

void ClapTrap::setattackdamage(unsigned int damage){
	_attackDamage = damage;
}

void ClapTrap::setenergypoint(unsigned int energy){
	_energyPoints = energy;
}

void ClapTrap::sethitpoint(unsigned int hit){
	_hitPoints = hit;
}
