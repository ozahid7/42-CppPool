#include "Serializer.hpp"
#include <iostream>

int main (){
	Data *ptr = new Data;
	Data *tfo;

	ptr->i = 9;
	uintptr_t u = 4;
	std::cout<<ptr<<std::endl;

	u = Serializer::serialize(ptr);
	std::cout<<u<<std::endl;
	tfo = Serializer::deserialize(u);
	std::cout<<tfo<<std::endl;
	std::cout<<tfo->i<<std::endl;
}