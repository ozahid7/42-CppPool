#include "Weapon.hpp"

void	Weapon::setType(const std::string type){
	_type = type;
}

Weapon::Weapon(const std::string str){
	_type = str;
};

const std::string &Weapon::getType()
{
	return this->_type;
}