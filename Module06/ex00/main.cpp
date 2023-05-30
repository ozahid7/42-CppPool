
#include "ScalarConverte.hpp"


int main(int ac, char **av){
    std::string str;
    if (ac == 1 || ac > 2)
        return (std::cout << " Invalid Arguments "<<std::endl, 1);
    str = av[1];
	ScalarConverte::convert(str);
}