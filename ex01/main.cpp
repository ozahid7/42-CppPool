#include "Bureaucrat.hpp"


int main(){
	try{
		Bureaucrat b1("b1", 5);
		Form f1("f1", 3, 150);

		f1.beSigned(b1);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}