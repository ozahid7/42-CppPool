
#include "FragTrap.hpp"

int main(){
	FragTrap t;
	FragTrap a ("a");
	FragTrap b ("b");


	std::cout<<"###a gethit = "<<a.gethit()<<std::endl;
	std::cout<<"###a getenergy = "<<a.getenerg()<<std::endl;
	a.attack("b");
	std::cout<<"###a gethit = "<<a.gethit()<<std::endl;
	std::cout<<"###a getenergy = "<<a.getenerg()<<std::endl;
	b.takeDamage(a.getattackdam());
	std::cout<<"###b gethit = "<<b.gethit()<<std::endl;
	std::cout<<"###b getenergy = "<<b.getenerg()<<std::endl;
	a.beRepaired(1);
	std::cout<<"###a gethit = "<<a.gethit()<<std::endl;
	std::cout<<"###a getenergy = "<<a.getenerg()<<std::endl;
	a.highFivesGuys();

}