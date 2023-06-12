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

std::map<std::string, double> BitcoinExchange::get_data()
{
	return _data;
}

void BitcoinExchange::fill_data()
{
	std::fstream file("data.csv");
	std::string line;
	std::string key;
	double	value;
	if(file.is_open())
	{
		std::getline(file, line);
		while(std::getline(file, line) && !line.empty())
		{
			const unsigned long pos = line.find(',');
			if (pos != std::string::npos){
				key = line.substr(0, pos);
				value = std::strtod(line.substr(pos + 1, line.size()).c_str(), NULL);
			}
			_data.insert(std::make_pair(key, value));
		}	
	}else
		throw std::invalid_argument("Data file is not opened");
}

std::vector<std::string> ft_split(std::string str, char c)
{
	size_t pos;
	size_t start = 0;
	std::vector<std::string> vec;
	size_t	last_space = str.find_last_not_of(c);
	size_t	first_space = str.find_first_not_of(c);
	str = str.substr(first_space, last_space - first_space + 1);
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
	// std::cout<<vec[i]<<std::endl;
		for (size_t j = 0; j < vec[i].size(); j++){
			if (!std::isdigit(vec[i][j]))
				throw std::invalid_argument("It is not digit Parcing Error");
		}	
	}
}

void parse_key(std::string key){
	std::vector<std::string> vec;
	vec = ft_split(key, '-');
	if (vec.size() != 3)
		throw std::length_error("key Parsing Error");
	is_it_digits(vec);
}

void parse_value(std::string value){

	double nb;
	std::stringstream ss;
	ss << value;
	ss >> nb;
	std::cout<<nb<<std::endl;
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
			if (vec.size() > 2)
				throw std::length_error("Split by | Parsing Error");
			key = trim_spaces(vec[0]);
			parse_key(key);
			value = trim_spaces(vec[1]);
			parse_value(value);
			vec.clear();
		}
	}else
		throw std::invalid_argument("Input file is not opened");
}

