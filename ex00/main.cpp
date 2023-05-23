#include "ScalarConverte.hpp"
#include <sstream>

void print_char(char c){
	if (c <= 32)
		std::cout<<" NON PRINTABLE CHARACTER "<<std::endl;
	else
		std::cout<<c<<std::endl;
}


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

bool is_char(std::string str){

	if(str.length() == 1 && isalpha(str[0]))
		return (true);
	return (false);
}

int is_valid(std::string str){
	
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
		std::stringstream ss;
		 
		ss << str;
		ss >> i;
        d = static_cast<double>(i);
        f = static_cast<float>(i);
        c = static_cast<char>(i);
		std::cout<<d<<std::endl;
		std::cout<<f<<std::endl;
		print_char(c);
    }

    else if (is_double(str)){
		std::stringstream ss;
		ss << str;
		ss >> d;
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		c = static_cast<char>(d);
		std::cout<<i<<std::endl;
		std::cout<<f<<std::endl;
		print_char(c);
    }
	else if (is_char(str)){
		std::stringstream ss;
		ss << str;
		ss >> c;
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		std::cout<<d<<std::endl;
		std::cout<<f<<std::endl;
		std::cout<<i<<std::endl;
	}
}