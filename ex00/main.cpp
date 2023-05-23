#include "ScalarConverte.hpp"
#include <sstream>


bool is_it_digits(std::string str)
{
    for(size_t i = 0; i < str.length(); i++){
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool is_double(std::string str){

	int point;

	point = 0;
    for(size_t i = 0; i < str.length(); i++){
		if (str[i] == '.'){
			i++;
			point++;
		}
        if (!isdigit(str[i]) || point > 1)
            return (false);
    }
	if (point == 0)
		return (false);
	return (true);
}

int main(int ac, char **av){

    std::string str;
	double	d;
	int		i;
	float	f;
	char	c;

    if (ac == 1 || ac > 2)
        return (std::cout << "Invalid Arguments "<<std::endl, 1);
    str = av[1];
    if (is_it_digits(str))
    {
		i = std::atoi(av[1]);
        d = static_cast<double>(i);
        f = static_cast<float>(i);
        c = static_cast<char>(i);
		std::cout<<d<<std::endl;
		std::cout<<f<<std::endl;
		std::cout<<c<<std::endl;
    }

    else if (is_double(str)){
		std::stringstream ss;
		ss << str;
		ss >> d;
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		c = static_cast<char>(d);
		std::cout<<d<<std::endl;
		std::cout<<f<<std::endl;
		std::cout<<c<<std::endl;
    }
}