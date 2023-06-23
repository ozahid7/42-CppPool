#include "RPN.hpp"

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