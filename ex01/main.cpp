#include "Serializer.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>



int main (){
	Data *ptr = new Data;
	std::stringstream ss;
	Data *ptr2 = new Data;
	ptr->i = 9;
	uintptr_t u = 4;

	u = Serializer::serialize(ptr);
	std::cout<<" value of u after serialize " <<u<<std::endl; 
	ss << std::hex << u;
	std::cout<<" value of u after serialize  in hexadecimal "<<ss.str()<<std::endl; 
	std::cout<<"ptr value before deserialize "<<ptr<<std::endl;
	ptr = Serializer::deserialize(u);
	std::cout<<"ptr value after deserialize "<<ptr<<std::endl;
	std::cout<<ptr<<std::endl;
	std::cout<<"ptr2 before reintrpret cast "<<ptr2<<std::endl;
	ptr2 = reinterpret_cast<Data *>(ptr);
	std::cout<<"ptr2 after reintrpret cast "<<ptr2<<std::endl;
	std::cout<<ptr->i<<std::endl;


	//failed situations
	int *i;
	char *c = NULL;
	// i = c;
	i = reinterpret_cast<int *>(c);
	std::cout<<"i = " <<i<<std::endl;

}