#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &other);
	~ScavTrap();

	ScavTrap &operator=(ScavTrap const &other);

	void guardGate();
	unsigned int gethit();
	unsigned int getenerg();
	void attack(const std::string& target);
};

#endif