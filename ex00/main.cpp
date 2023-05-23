#include "ScalarConverte.hpp"

bool is_it_digits(std::string str)
{

    for(size_t i = 0; i < str.length(); i++){
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

int main(int ac, char **av){

    std::string str;

    str = av[1];
    if (ac  == 1 )
        return (std::cout << "Invalid Arguments "<<std::endl, 1);
    if (is_it_digits(str))
    {
        
    }
    else if (str.find('.')){

    }
    else if ()
}