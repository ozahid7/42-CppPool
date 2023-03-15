#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
private:
	Weapon* _Bweapon;
	std::string _name;
public:
	HumanB(const std::string name);
	void setWeapon(Weapon *bw);
	void attack();
};

#endif