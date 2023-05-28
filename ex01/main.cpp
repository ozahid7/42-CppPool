#include "Serializer.hpp"
#include <iostream>

int main (){
	Data *ptr = new Data;
	ptr->i = 9;
	uintptr_t u = 4;
	std::cout<<ptr<<std::endl;

	Serializer::serialize(ptr);
	ptr = Serializer::deserialize(u);
	std::cout<<ptr<<std::endl;
}