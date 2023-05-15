#include "Bureaucrat.hpp"


int main(){
	try{
		Bureaucrat b1("b1", 4);
		b1.incrementgrade();
		std::cout<<b1.getname()<<"  "<<b1.getgrade()<<std::endl;
		b1.incrementgrade();
		b1.incrementgrade();
		b1.incrementgrade();
	}
	catch(std::exception &e){
		std::cout<<e.what();
	}
}