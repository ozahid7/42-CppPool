#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
private:
	Weapon& _Aweapon;
	std::string _name;
public:
	HumanA(std::string name);
	void attac();
};

#endif