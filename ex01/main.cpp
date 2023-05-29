#include "Serializer.hpp"
#include <iostream>

int main (){
	Data *ptr = new Data;

	ptr->i = 9;
	uintptr_t u = 4;
	double h = 10.04;

	u = reinterpret_cast<uintptr_t>(&h);
	std::cout<<&h<<std::endl;
	std::cout<<u<<std::endl;
	// std::cout<<ptr<<std::endl;

	// std::cout<<ptr<<std::endl;
	// u = Serializer::serialize(ptr);
	// std::cout<<ptr<<std::endl;
	// ptr = Serializer::deserialize(u);
	// std::cout<<ptr<<std::endl;
	// std::cout<<u<<std::endl;
}