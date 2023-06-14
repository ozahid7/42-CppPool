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
	_data = other._data;
	return (*this);
}

std::map<std::string, double> BitcoinExchange::get_data()
{
	return _data;
}

void BitcoinExchange::fill_data()
{
	std::fstream file("data.csv");
	std::string line;
	std::vector<std::string> vec;
	std::stringstream ss;
	double	value;
	std::string	key;
	if(file.is_open())
	{
		std::getline(file, line);
		while(std::getline(file, line) && !line.empty())
		{
			size_t pos = line.find(',');
			if (pos != std::string::npos){
				key = line.substr(0, pos);
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

std::string trim_spaces(std::string str){
	size_t	last_space = str.find_last_not_of(' ');
	size_t	first_space = str.find_first_not_of(' ');
	size_t	last_tab = str.find_last_not_of('\t');
	size_t	first_tab = str.find_first_not_of('\t');
	size_t	last_v = str.find_last_not_of('\v');
	size_t	first_v = str.find_first_not_of('\v');
	size_t	last_r = str.find_last_not_of('\r');
	size_t	first_r = str.find_first_not_of('\r');
	str = str.substr(first_space, last_space - first_space + 1);
	str = str.substr(first_tab, last_tab - first_tab + 1);
	str = str.substr(first_v, last_v - first_v + 1);
	str = str.substr(first_r, last_r - first_r + 1);
	return (str);
}

int is_it_digits(std::string str)
{
	for (size_t j = 0; j < str.size(); j++){
		if (!std::isdigit(str[j]))
			return (1);
	}
	return (0);
}

bool is_leap(int year) {
    if (year % 400 == 0)
        return true;
    else if ((year % 100 != 0) && (year % 4 == 0))
        return true;
    else
        return false;
}

void BitcoinExchange::get_btc_value(std::string key, double value)
{
	std::map<std::string, double>::iterator it;
	it = _data.lower_bound(key);
	if(it != _data.begin() && it->first != key)
		it--;
	std::cout<<it->first<< " => " << value << " = " << it->second * value<<std::endl;
}

int BitcoinExchange::parse_key(std::string key, double value){
	int year;
	int month;
	int day;
	std::string date;
	int limit = 31;
	std::stringstream ss;
	ss << key;
	std::getline(ss, date, '-');
	if(is_it_digits(date)){
		std::cout<<"Error : Is Not Digit"<<std::endl;
		return (1);
	}
	year = std::atof(date.c_str());
	if (year < 2009 || year > 2022){
		std::cout<<"Error : Year Out of Range"<<std::endl;
		return 1;
	}
	date.clear();
	std::getline(ss, date, '-');
	if(is_it_digits(date)){
		std::cout<<"Error : Is Not Digit"<<std::endl;
		return (1);
	}
	month = std::atof(date.c_str());
	date.clear();
	std::getline(ss, date, '-');
	if(is_it_digits(date)){
		std::cout<<"Error : Is Not Digit"<<std::endl;
		return (1);
	}
	day = std::atof(date.c_str());
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
	if (day < 0 || day > limit){
		std::cout<<"Error : Day Out of Range"<<std::endl;
		return 1;
	}
	get_btc_value(key, value);
	return (0);
}

int BitcoinExchange::parse_value(std::string value){

	double nb;
	std::stringstream ss;
	ss << value;
	ss >> nb;
	if (ss.fail() || ss.peek() != -1 || nb < 0 || nb > 1000)
	{
		std::cout<<"Error : value has some Invalid Content"<<std::endl;
		return (1);
	}
	return 0;
}

void BitcoinExchange::fill_input(char *fil)
{
	std::fstream file(fil);
	std::string line;
	std::string key;
	std::string	value;
	std::stringstream ss("default");
	if (file.is_open()){
		while (std::getline(file, line))
		{
			ss.clear();
			if (!line.compare("date | value"))
				continue;
			if (line.empty()){
				std::cout<<"Error : Empty Line"<<std::endl;
				continue;
			}
			ss << line;
			std::getline(ss, line, '|');
			ss >> value;
			key = line;
			ss.clear();
			value = trim_spaces(value);
			if (parse_value(value))
				continue;
			key = trim_spaces(key);
			if(parse_key(key, std::atof(value.c_str())))
				continue;
		}
	}else
	{
		file.close();	
		throw std::invalid_argument("Input file is not opened");
	}
	file.close();
}


