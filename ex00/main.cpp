#include "ScalarConverte.hpp"
#include <sstream>

void print_char(char c){
	if (c <= 32)
		std::cout<<"char : Non displayable "<<std::endl;
	else
		std::cout<<"char : "<<c<<std::endl;
}


bool is_it_digits(std::string str)
{
	size_t i = 0;

	if (str[i] == '-')
		i++;
    for(; i < str.length(); i++){
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool is_double(std::string str){

	int point;
	size_t i = 0;

	point = 0;
	if (str[i] == '-')
		i++;
    for(; i < str.length(); i++){
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

void is_pseudo(std::string str){
	if (!str.compare("nan") || !str.compare("nanf")){
		str = "nan";
		std::cout<<"char : impossible"<<std::endl;
		std::cout<<"int : impossible "<<std::endl;
		std::cout<<"float : "<<str + "f"<<std::endl;
		std::cout<<"double : "<<str<<std::endl;
		exit (0);
	}
	else if (!str.compare("inff") || !str.compare("inf") || !str.compare("-inf") || !str.compare("+inf") || !str.compare("-inff") || !str.compare("+inff")){

		if(str.length() == 5 || !str.compare("inff"))
			str = str.substr(0, str.length() - 1);
		std::cout<<"char : impossible"<<std::endl;
		std::cout<<"int : impossible "<<std::endl;
		std::cout<<"float : " <<str + "f"<<std::endl;
		std::cout<<"double : "<<str<<std::endl;
		exit (0);
	}

}

bool is_float(std::string str){

	if (str[str.length() - 1] == 'f' && is_double(str.substr(0, str.length() - 1)))
		return true;
	return false;

}

bool is_char(std::string str){

	if(str.length() == 1 && isalpha(str[0]))
		return (true);
	return (false);
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
	is_pseudo(str);
    if (is_it_digits(str))
    {
		std::stringstream ss;
		 
		ss << str;
		ss >> i;
        d = static_cast<double>(i);
        f = static_cast<float>(i);
        c = static_cast<char>(i);
		print_char(c);
		std::cout<<"int : "<<i<<std::endl;
		std::cout<<"double : "<<d<<std::endl;
		std::cout<<"float : "<<f<<"f"<<std::endl;
    }

    else if (is_double(str)){
		std::stringstream ss;
		ss << str;
		ss >> d;
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		c = static_cast<char>(d);
		print_char(c);
		std::cout<<"int : "<<i<<std::endl;
		std::cout<<"double : "<<d<<std::endl;
		std::cout<<"float : "<<f<<"f"<<std::endl;
    }
    else if (is_float(str)){
		f = std::atof(str.c_str());
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		c = static_cast<char>(f);
		print_char(c);
		std::cout<<"int : "<<i<<std::endl;
		std::cout<<"double : "<<d<<std::endl;
		std::cout<<"float : "<<f<<"f"<<std::endl;
    }
	else if (is_char(str)){
		std::stringstream ss;
		ss << str;
		ss >> c;
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		print_char(c);
		std::cout<<"int : "<<i<<std::endl;
		std::cout<<"double : "<<d<<std::endl;
		std::cout<<"float : "<<f<<"f"<<std::endl;
	}

}