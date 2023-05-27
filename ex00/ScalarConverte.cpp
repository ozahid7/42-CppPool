#include "ScalarConverte.hpp"

char	ScalarConverte::c;
int		ScalarConverte::i;
double	ScalarConverte::d;
float	ScalarConverte::f;

ScalarConverte::ScalarConverte()
{
	d = 0.0;
	f = 0.0;
	i = 0;
	c = 48;
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
	d = other.d;
	c = other.c;
	i = other.i;
	f = other.f;
	return (*this);
}

void ScalarConverte::convert(std::string convert)
{
	is_pseudo(convert);
	if (is_char(convert))
		cast_char(convert);
	else if (is_it_digits(convert))
		cast_int(convert);
	else if (is_float(convert))
		cast_float(convert);
	else if(is_double(convert))
		cast_double(convert);
	else{
		std::cout<< " What Is This "<<std::endl;
	}
}

void ScalarConverte::show_results(int j, int i, char c, double d, float f, std::string str)
{
	int x;

	x = str.find('.');
	if (!str.compare("nan") || !str.compare("nanf") || !str.compare("inf") || !str.compare("-inf") || !str.compare("+inf") || !str.compare("inff") || !str.compare("-inff") || !str.compare("+inff"))
		std::cout<<"char : Impossible "<<std::endl;
	else if (c <= 32 || c > 126)
		std::cout<<"char : Non displayable "<<std::endl;
	else
		std::cout<<"char : "<<c<<std::endl;
	if (i >= INT_MAX || i <= INT_MIN)
		std::cout<<"int : Impossible "<<std::endl;
	else
		std::cout<<"int : "<<i<<std::endl;
	if (f > MAXFLOAT)
		std::cout<<"float : impossible "<<std::endl;
	else if (is_zero1(str.substr(0, str.length()), j) || x == -1)
		std::cout<<std::fixed<<std::setprecision(1)<<"float : "<<f<<"f"<<std::endl;
	else
		std::cout<<std::fixed<<std::setprecision(1)<<"float : "<<f<<"f"<<std::endl;
	if (is_zero1(str, j) || x == -1)
		std::cout<<std::fixed<<std::setprecision(1)<<"double : "<<d<<std::endl;
	else
		std::cout<<std::fixed<<std::setprecision(1)<<"double : "<<d<<std::endl;

}

bool ScalarConverte::is_zero1(std::string str, int x)
{
	int pos;
	size_t len = 0;

	pos = 0;
	pos = str.find('.');
	pos++;
	if (x == 1)
		len = str.length() - pos -1;
	else if (x == 2)
		len = str.length() - pos;
	str = str.substr(pos, len);
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] != '0'){
			return (false);
		}
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
	if (!str.compare("nan") || !str.compare("inf") || !str.compare("-inf") || !str.compare("+inf")){
		std::stringstream ss;
		ss << str;
		ss >> d;
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		c = static_cast<char>(d);
		show_results(0, i, c, d , f, str);
		exit (0);
	}
	else if (!str.compare("nanf") || !str.compare("inff") || !str.compare("-inff") || !str.compare("+inff")){
		if(str.length() == 5 || !str.compare("inff"))
			str = str.substr(0, str.length() - 1);
		f = std::atof(str.c_str());
		i = static_cast<int>(f);
		d = static_cast<float>(f);
		c = static_cast<char>(f);
		show_results(0, i, c, d , f, str);
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
	show_results(0, i, c, d, f, str);
}
void ScalarConverte::cast_float(std::string str)
{
	std::stringstream ss;
	str = str.substr(0, str.length() - 1);
	ss << str;
	ss >> f;
	if (ss.fail() == 1)
	{
		std::cout<<" What is this "<<std::endl;
		exit (1);
	}
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	c = static_cast<char>(f);
	show_results(1, i, c, d, f, str);
}
void ScalarConverte::cast_double(std::string str)
{
	std::stringstream ss;
	ss << str;
	ss >> d;
	if (ss.fail() == 1)
	{
		std::cout<<" What is this "<<std::endl;
		exit (1);
	}
	i = static_cast<int>(d);
	f = static_cast<float>(d);
	c = static_cast<char>(d);
	show_results(2, i, c, d, f, str);
}

void ScalarConverte::cast_int(std::string str)
{
	std::stringstream ss;
	ss << str;
	ss >> i;
	if (ss.fail() == 1)
	{
		std::cout<<" What is this "<<std::endl;
		exit (1);
	}
    d = static_cast<double>(i);
    f = static_cast<float>(i);
    c = static_cast<char>(i);
	show_results(0, i, c, d, f, str);
}
