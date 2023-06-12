#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
class BitcoinExchange{
	public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	
	BitcoinExchange &operator=(BitcoinExchange const &other);

	std::map<std::string, double>		get_data();
	void								fill_data();
	void								fill_input();
	private:
	std::map<std::string, double> _data;
	std::map<std::string, double> _input;
};
std::vector<std::string> 			ft_split(std::string str, char c);
void is_it_digits(std::vector<std::string> vec);
void parse_key(std::string key);
void parse_value(std::string value);
std::string trim_spaces(std::string str);

#endif