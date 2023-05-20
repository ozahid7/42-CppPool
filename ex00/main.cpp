#include "Bureaucrat.hpp"


int main(){
	try{
		// Bureaucrat b1("b1", -1);
		Bureaucrat b2("b2", 2);
		b2.decrementgrade();
		b2.decrementgrade();
		std::cout<<b2<<std::endl;
		// b2.decrementgrade();
		// std::cout<<b1<<std::endl;
		// b1.incrementgrade();
		// b1.incrementgrade();
		// b1.incrementgrade();
		// b1.incrementgrade();
	}
	catch(std::exception &e){
		std::cout<<e.what();
	}
}