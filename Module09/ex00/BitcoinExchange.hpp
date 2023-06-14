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
	void								fill_input(char *fil);
	int parse_key(std::string key, double value);
	void get_btc_value(std::string key, double value);
	int parse_value(std::string value);
	private:
	std::map<std::string, double> _data;
	std::map<std::string, double> _input;
};
int is_it_digits(std::string str);
bool is_leap(int year);
std::string trim_spaces(std::string str);

#endif