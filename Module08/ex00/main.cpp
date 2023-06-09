#include "easyfind.hpp"

int main (){
	std::vector<int> numbers;

	numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);	
	std::vector<int>::iterator it;
	try {
		it = easyfind(numbers, 7);
	}catch (std::exception(&e)){
		std::cout<<e.what()<<std::endl;
	}
	try {
		it = easyfind(numbers, 4);
		std::cout<<*it<<std::endl;
	}catch (std::exception(&e)){
		std::cout<<e.what()<<std::endl;
	}
	
}