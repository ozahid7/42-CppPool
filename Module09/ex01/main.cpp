#include "RPN.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cout<<" Invalid Arguments "<<std::endl;
		exit(0);
	}
	std::string args = av[1];
	if (do_opreration(args))
		std::cout << "Error" << std::endl;
}