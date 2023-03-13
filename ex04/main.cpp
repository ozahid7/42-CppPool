#include "sed.hpp"

int	main (int ac, char **av){

	
	if (ac == 4)
	{
		Read read(av[1]);
		printf("av[1] = %s\n", av[1]);
		read.setbuffer("");
		Change change(av[2], av[3]);
		
	}
}