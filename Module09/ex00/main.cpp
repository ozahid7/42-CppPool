#include "BitcoinExchange.hpp"

int main(){

	try {
	BitcoinExchange b;
	b.fill_data();
	// std::map<long long, double> map = b.get_data();
	// for (std::map<long long, double>::iterator it = map.begin(); it != map.end(); it++){
	// 	std::cout<<it->first;
	// 	std::cout<<it->second<<std::endl;
	// }
	b.fill_input();
	}catch(std::exception(&e)){
		std::cout<<e.what();
	}

	// std::string test = "hello world guys tfo 3likom wa7d tilwa la5ar";
	// std::vector<std::string> vec = ft_split(test, ' ');
	// for (unsigned long i = 0; i < vec.size(); i++)
	// 	std::cout<<vec[i]<<std::endl;
	
}