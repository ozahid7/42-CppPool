#include "Span.hpp"

int main(){
	try{
		Span a(3);
		a.addNumber(10);
		a.addNumber(2);
		a.addNumber(6);
		for(unsigned long i = 0; i < a.get_vec().size(); i++){
			std::cout<<a.get_vec()[i]<<"    "<<std::endl;
		}
		std::cout<<"shortestSpan = "<<a.shortestSpan()<<std::endl;
		std::cout<<"longestspan = "<<a.longestSpan()<<std::endl;
	}catch(std::exception(&e))
	{
		std::cout<<e.what()<<std::endl;
	}
	try{
		Span b(10);
		b.addNumber(1);
		b.addNumber(2);
		b.addNumber(3);
		std::vector<int> vec(8, 8);
		b.addNumbers(vec.begin(), vec.end());
		for(unsigned long i = 0; i < b.get_vec().size(); i++){
			std::cout<<b.get_vec()[i]<<"    "<<std::endl;
		}
	}catch(std::exception(&e))
	{
		std::cout<<e.what()<<std::endl;
	}
}