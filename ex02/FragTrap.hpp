#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap: public ClapTrap{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &other);
	~FragTrap();

	FragTrap &operator=(FragTrap const &other);

	void highFivesGuys(void);
	unsigned int gethit();
	unsigned int getenerg();

};

#endif