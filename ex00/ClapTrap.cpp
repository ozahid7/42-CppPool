#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	_name = "default Claptrap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap(){
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other){

}

void ClapTrap::attack(const std::string &target){

}

void ClapTrap::takeDamage(unsigned int amount){
}

void ClapTrap::beRepaired(unsigned int amount){
}

ClapTrap::ClapTrap(std::string name){
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}
