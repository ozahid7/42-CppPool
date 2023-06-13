#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

class Date{
protected:
	int year;
	int month;
	int day;

	int input;
	double input_val;
};

class BitcoinExchange: public Date{
	public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	
	BitcoinExchange &operator=(BitcoinExchange const &other);

	std::map<long long, double>		get_data();
	void								fill_data();
	void								fill_input();
	int parse_key(std::string key, double value);
	void get_btc_value(std::vector<std::string>, double value);
	int parse_value(std::string value);
	private:
	std::map<long long, double> _data;
	std::map<std::string, double> _input;
};
std::vector<std::string> 			ft_split(std::string str, char c);
void is_it_digits(std::vector<std::string> vec);
bool is_leap(int year);
std::string trim_spaces(std::string str);

#endif