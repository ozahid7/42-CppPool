#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &other);

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	/////////////////////SETERS
	void setname(std::string name);
	void sethitpoint(unsigned int);
	void setenergypoint(unsigned int);
	void setattackdamage(unsigned int);
	//////////////////////GETERS
	std::string	getname();
	unsigned int gethitpoint();
	unsigned int getenergypoint();
	unsigned int getattackdamage();

protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
};

#endif