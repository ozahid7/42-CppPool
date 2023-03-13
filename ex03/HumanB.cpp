#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	_name = name;
	_Bweapon = NULL;
};

void HumanB::setWeapon(Weapon *bw){
	_Bweapon = bw;
}
void HumanB::attack(){
	if (_Bweapon)
		std::cout<<_name<<" :  attacks with their "<<_Bweapon->getType()<<std::endl;
}