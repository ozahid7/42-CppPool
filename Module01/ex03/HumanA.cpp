#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &aw) : _Aweapon(aw)
{
	_name = name;
}

void HumanA::attack(){
	std::cout<<_name<<" :  attacks with their "<<_Aweapon.getType()<<std::endl;
};