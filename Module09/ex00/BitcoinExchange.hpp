#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
class BitcoinExchange{
	public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	
	BitcoinExchange &operator=(BitcoinExchange const &other);

	std::map<std::string, double>		get_data();
	void								fill_data();

	private:
	std::map<std::string, double> _data;
};

#endif