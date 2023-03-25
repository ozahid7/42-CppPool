
#include "ScavTrap.hpp"

int main(){
	ScavTrap a ("a");
	ScavTrap b ("b");

	std::cout<<"###a gethit = "<<a.gethitpoint()<<std::endl;
	std::cout<<"###a getenergy = "<<a.getenergypoint()<<std::endl;
	a.attack("b");
	std::cout<<"###a gethit = "<<a.gethitpoint()<<std::endl;
	std::cout<<"###a getenergy = "<<a.getenergypoint()<<std::endl;
	b.takeDamage(2);
	std::cout<<"###b gethit = "<<b.gethitpoint()<<std::endl;
	std::cout<<"###b getenergy = "<<b.getenergypoint()<<std::endl;
	a.beRepaired(1);
	std::cout<<"###a gethit = "<<a.gethitpoint()<<std::endl;
	std::cout<<"###a getenergy = "<<a.getenergypoint()<<std::endl;
}