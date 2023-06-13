#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	(void)other;
	return (*this);
}

std::map<long long, double> BitcoinExchange::get_data()
{
	return _data;
}

void BitcoinExchange::fill_data()
{
	std::fstream file("data.csv");
	std::string line;
	std::string key_str;
	std::string key_tmp;
	std::vector<std::string> vec;
	std::stringstream ss;
	double	value;
	long long	key;
	if(file.is_open())
	{
		std::getline(file, line);
		while(std::getline(file, line) && !line.empty())
		{
			size_t pos = line.find(',');
			if (pos != std::string::npos){
				key_str = line.substr(0, pos);
				vec = ft_split(key_str, '-');
				ss << vec[0];
				ss << vec[1];
				ss << vec[2];
				ss >> key_tmp;
				ss.clear();
				key = std::strtol(key_tmp.c_str(), NULL,10);
				value = std::strtod(line.substr(pos + 1, line.size()).c_str(), NULL);
			}
			_data.insert(std::make_pair(key, value));
		}
	}else
	{
		file.close();
		throw std::invalid_argument("Data file is not opened");
	}
	file.close();
}

std::vector<std::string> ft_split(std::string str, char c)
{
	size_t pos;
	size_t start = 0;
	std::vector<std::string> vec;
	str = trim_spaces(str);
	pos = str.find(c);
	while (pos != std::string::npos){
		vec.push_back(str.substr(start, pos - start));
		pos++;
		start = pos;
		pos = str.find(c, start);
	}
	vec.push_back(str.substr(start, pos - start));
	return (vec);
}

std::string trim_spaces(std::string str){
	size_t	last_space = str.find_last_not_of(' ');
	size_t	first_space = str.find_first_not_of(' ');
	str = str.substr(first_space, last_space - first_space + 1);
	return (str);
}

void is_it_digits(std::vector<std::string> vec)
{
	for(size_t i = 0; i < vec.size(); i++){
		for (size_t j = 0; j < vec[i].size(); j++){
			if (!std::isdigit(vec[i][j]))
				std::cout<<"Error : It Is not Digit"<<std::endl;
		}	
	}
}

bool is_leap(int year) {
    if (year % 400 == 0)
        return true;
    else if ((year % 100 != 0) && (year % 4 == 0))
        return true;
    else
        return false;
}

void BitcoinExchange::get_btc_value(std::vector<std::string> vec, double value)
{
	std::stringstream ss;
	std::string	key_tmp;
	std::string	key_print;
	long long key;
	std::map<long long, double>::iterator it;
	ss << vec[0];
	ss << vec[1];
	ss << vec[2];
	ss >> key_tmp;
	key = std::strtol(key_tmp.c_str(), NULL, 10);
	it = _data.find(key);
	if (it != _data.end()){
		ss.clear();
		ss << it->first;
		ss >> key_print;
		key_print.insert(4, "-");
		key_print.insert(7, "-");
		std::cout<<key_print<< " => " << value << " = " << it->second<<std::endl;
	}else{
		ss.clear();
		key_print.clear();
		it = _data.lower_bound(key);
		it--;
		ss << it->first;
		ss >> key_print;
		key_print.insert(4, "-");
		key_print.insert(7, "-");
		std::cout<<key_print<< " => " << value << " = " << it->second<<std::endl;
		
	}
}

int BitcoinExchange::parse_key(std::string key, double value){
	std::vector<std::string> vec;
	int year;
	int month;
	int day;
	int limit = 31;
	std::stringstream ss;
	vec = ft_split(key, '-');
	if (vec.size() != 3){
		std::cout<<"Error : Invalid Date Format"<<std::endl;
		return 1;
	}
	is_it_digits(vec);
	ss << vec[0];
	ss >> year;
	if (ss.fail() || ss.peek() != -1){
		std::cout<<"Error : Year has some Invalid Charcters"<<std::endl;
		return 1;
	}
	if (year < 2009 || year > 2022){
		std::cout<<"Error : Year Out of Range"<<std::endl;
		return 1;
	}
	ss.clear();
	ss << vec[1];
	ss >> month;
	if (ss.fail() || ss.peek() != -1){
		std::cout<<"Error : Month has some Invalid Charcters"<<std::endl;
		return 1;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		limit = 30;
	else if (month == 2){
		if (is_leap(year))
			limit = 29;
		else
			limit = 28;
	}
	if (month < 0 || month > 12){
		std::cout<<"Error : Month Out of Range"<<std::endl;
		return 1;
	}
	ss.clear();
	ss << vec[2];
	ss >> day;
	if (ss.fail() || ss.peek() != -1){
		std::cout<<"Error : Day has some Invalid Charcters"<<std::endl;
		return 1;
	}
	if (day < 0 || day > limit){
		std::cout<<"Error : Day Out of Range"<<std::endl;
		return 1;
	}
	get_btc_value(vec, value);
	return (0);
}

int BitcoinExchange::parse_value(std::string value){

	double nb;
	std::stringstream ss;
	ss << value;
	ss >> nb;
	if (ss.fail() || ss.peek() != -1)
	{
		std::cout<<"Error : value has some Invalid charaters"<<std::endl;
		return (1);
	}
	if (nb < 0 || nb > 1000)
	{
		std::cout<<"Error : Value Out of range"<<std::endl;
		return (1);
	}
	return 0;
}

void BitcoinExchange::fill_input()
{
	std::fstream file("input.csv");
	std::string line;
	std::string key;
	std::vector<std::string> vec;
	std::string	value;
	if (file.is_open()){
		std::getline(file, line);
		while (std::getline(file, line) && !line.empty())
		{
			vec = ft_split(line, '|');
			if (vec.size() != 2){
				std::cout<<("Error : Invalid Elements")<<std::endl;
				continue;
			}
			value = trim_spaces(vec[1]);
			if (parse_value(value))
				continue;
			key = trim_spaces(vec[0]);
			if(parse_key(key, std::atof(value.c_str())))
				continue;
			vec.clear();
		}
	}else
		throw std::invalid_argument("Input file is not opened");
}


