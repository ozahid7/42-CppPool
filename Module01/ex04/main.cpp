#include "Replace.hpp"
int	main (int ac, char **av){

	
	if (ac == 4){
		Read read(av[1], av[2], av[3]);
		read.readit();	
	}else{
		std::cerr<<"Invalid Arguments"<<std::endl;
	}
	return 0;
}