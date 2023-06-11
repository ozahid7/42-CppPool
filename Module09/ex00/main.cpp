#include "BitcoinExchange.hpp"

int main(){

	BitcoinExchange b;
	b.fill_data();
	std::map<std::string, double> map = b.get_data();
	for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); it++){
		std::cout<<it->first;
		std::cout<<it->second<<std::endl;
	}
}