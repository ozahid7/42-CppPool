#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
private:
	std::string type;
public:
	const	std::string& getType();
	void	setType(const std::string type);
};



#endif