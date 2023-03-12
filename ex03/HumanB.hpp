#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
private:
	Weapon& _Bweapon;
	std::string _name;
public:
	HumanB(std::string name);
	void attac();
};

#endif