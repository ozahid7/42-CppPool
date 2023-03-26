#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	virtual ~ClapTrap();

	ClapTrap &operator=(ClapTrap const &other);

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
};

#endif