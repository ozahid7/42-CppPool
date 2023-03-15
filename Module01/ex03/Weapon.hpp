#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>


class Weapon{
private:
	std::string _type;
public:
	Weapon(const std::string str);
	const	std::string& getType();
	void	setType(const std::string type);
};

#endif