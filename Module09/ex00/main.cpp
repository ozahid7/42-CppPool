#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	
	if (ac != 2)
	{
		std::cout<<"Invalid Arguments"<<std::endl;
		exit(0);
	}
	try {
	BitcoinExchange b;
		b.fill_data();
		b.fill_input(av[1]);
	}catch(std::exception(&e)){
		std::cout<<e.what();
	}
}