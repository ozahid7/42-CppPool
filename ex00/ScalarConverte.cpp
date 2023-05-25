#include "ScalarConverte.hpp"

ScalarConverte::ScalarConverte()
{
}

ScalarConverte::~ScalarConverte()
{
}

ScalarConverte::ScalarConverte(ScalarConverte const &other)
{
	*this = other;
}

ScalarConverte &ScalarConverte::operator=(ScalarConverte const &other)
{
	// TODO: insert return statement here
	(void) other;
	return (*this);
}

void ScalarConverte::convert(std::string convert)
{
	ScalarConverte obj;
	if (obj.is_char(convert))
		obj.cast_char(convert);
	else if (obj.is_it_digits(convert))
		obj.cast_int(convert);
	else if (obj.is_float(convert))
		obj.cast_float(convert);
	else if(obj.is_double(convert))
		obj.cast_double(convert);
	else{
		std::cout<< " What Is This "<<std::endl;
	}
}

void ScalarConverte::show_results(int i, char c, double d, float f, std::string str)
{
	int x;

	x = str.find('.');
	if (c <= 32)
		std::cout<<"char : Non displayable "<<std::endl;
	else
		std::cout<<"char : "<<c<<std::endl;

	std::cout<<"int : "<<i<<std::endl;
	if (is_zero(str.substr(0, str.length())) || x == -1)
		std::cout<<"float : "<<f<<".0f"<<std::endl;
	else
		std::cout<<"float : "<<f<<"f"<<std::endl;
	if (is_zero(str) || x == -1)
		std::cout<<"double : "<<d<<".0"<<std::endl;
	else
		std::cout<<"double : "<<d<<std::endl;

}

bool ScalarConverte::is_zero(std::string str)
{
	int pos;

	pos = 0;
	pos = str.find('.');
	str = str.substr(pos + 1, str.length());
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != '0')
			return (false);
	}
	return (true);
}

bool ScalarConverte::is_char(std::string str)
{
	if(str.length() == 1 && isalpha(str[0]))
		return (true);
	return (false);
}

bool ScalarConverte::is_float(std::string str)
{
	if (str[str.length() - 1] == 'f' && is_double(str.substr(0, str.length() - 1)))
		return true;
	return false;
}

bool ScalarConverte::is_double(std::string str)
{
	int point;
	size_t i = 0;

	point = 0;
	if (str[i] == '-' || str[i] == '+')
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

bool ScalarConverte::is_it_digits(std::string str)
{
	size_t i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
    for(; i < str.length(); i++){
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

void ScalarConverte::is_pseudo(std::string str)
{
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

void ScalarConverte::cast_char(std::string str)
{
	std::stringstream ss;
	ss << str;
	ss >> c;
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	show_results(i, c, d, f, str);
}
void ScalarConverte::cast_float(std::string str)
{
	char *ptr;
	f = std::strtod(str.c_str(), &ptr);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	c = static_cast<char>(f);
	show_results(i, c, d, f, str);
}
void ScalarConverte::cast_double(std::string str)
{
	char *ptr;
	d = std::strtod(str.c_str(), &ptr);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
	c = static_cast<char>(d);
	show_results(i, c, d, f, str);
}

void ScalarConverte::cast_int(std::string str)
{
	std::stringstream ss;
	ss << str;
	ss >> i;
    d = static_cast<double>(i);
    f = static_cast<float>(i);
    c = static_cast<char>(i);
	show_results(i, c, d, f, str);
}
