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
		std::getline(file, line, '\n');
		while(!line.empty())
		{
			std::getline(file, line, '\n');
			const unsigned long pos = line.find(',');
			if (pos != std::string::npos){
				key = line.substr(0, pos);
				value = std::strtod(line.substr(pos + 1, line.size()).c_str(), NULL);
			}
			_data.insert(std::make_pair(key, value));		
		}	
	}
}
