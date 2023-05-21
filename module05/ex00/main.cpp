#include "Bureaucrat.hpp"


int main(){
	try{
		// Bureaucrat b1("b1", -1);
		Bureaucrat b2("b2", 0);
		std::cout<<b2<<std::endl;
		Bureaucrat b3("b3", 2);
		b3.incrementgrade();
		b3.incrementgrade();
		b3.incrementgrade();
		std::cout<<b3<<std::endl;
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