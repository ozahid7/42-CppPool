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
	while(1){
		if (std::isspace(str.front()))
			str.erase(0, 1);
		if (std::isspace(str.back()))
			str.erase(str.length() - 1, str.length());
		else if(!std::isspace(str.front()) && !std::isspace(str.back()))
			break;
	}
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
	std::cout<<it->first<< " => " << value << " = " << (double)(it->second * value)<<std::endl;
}

int BitcoinExchange::parse_key(std::string key){
	int year;
	int month;
	bool err = false;
	int day;
	std::string date;
	int limit = 31;
	std::stringstream ss;
	ss << key;
	std::getline(ss, date, '-');
	if(is_it_digits(date) || date.empty())
		err = true;
	year = std::atof(date.c_str());
	if (year < 2009 || year > 2022)
		err = true;
	date.clear();
	std::getline(ss, date, '-');
	if(is_it_digits(date) || date.empty())
		err = true;
	month = std::atof(date.c_str());
	date.clear();
	std::getline(ss, date, '-');
	if(is_it_digits(date) || date.empty())
		err = true;
	day = std::atof(date.c_str());
	if (month == 4 || month == 6 || month == 9 || month == 11)
		limit = 30;
	else if (month == 2){
		if (is_leap(year))
			limit = 29;
		else
			limit = 28;
	}
	if (month < 0 || month > 12)
		err = true;
	if (day < 0 || day > limit)
		err = true;
	if (err == true)
	{
		std::cout<<"Error : bad input => "<<key<<std::endl;
		return (1);
	}
	return (0);
}

int BitcoinExchange::parse_value(std::string value){

	double nb;
	std::stringstream ss;
	ss << value;
	ss >> nb;

	if (ss.fail() || ss.peek() != -1)
	{
		std::cout<<"Error : not valid Content"<<std::endl;
		return (1);
	}
	else if (nb < 0)
	{
		std::cout<<"Error : not positive number"<<std::endl;
		return (1);
	}
	else if (nb > 1000)
	{
		std::cout<<"Error : too large a number"<<std::endl;
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
	std::stringstream ss;
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
			key = trim_spaces(key);
			if(parse_key(key))
				continue;
			value = trim_spaces(value);
			if (parse_value(value))
				continue;
			get_btc_value(key, std::atof(value.c_str()));
		}
	}else
	{
		file.close();	
		throw std::invalid_argument("Input file is not opened");
	}
	file.close();
}


