#include "RPN.hpp"

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

int	do_opreration(std::string args){
	std::stack<int> data;
	std::string elem;
	int tmp;
	int second;
	int first;
	int result;
	args = trim_spaces(args);
	for (size_t i = 0; i < args.length(); i++){
		if (args[i] == ' ')
			continue;
		if (std::isdigit(args[i])){
			elem = args[i];
			tmp = std::atoi(elem.c_str());
			data.push(tmp);
		}
		else if (data.size() >= 2){
			second = data.top();
			data.pop();
			first = data.top();
			data.pop();
			switch (args[i]){
				case '*':
					result = first * second;
					data.push(result);
					break;
				case '+':
					result = first + second;
					data.push(result);
					break;
				case '-':
					result = first - second;
					data.push(result);
					break;
				case '/':
					if (second  == 0){
						return (1);
					}
					result = first / second;
					data.push(result);
					break;
				default:
					return (1);
			}
		}
	}
	if (data.size() == 1)
		std::cout<<result<<std::endl;
	return (0);
} 