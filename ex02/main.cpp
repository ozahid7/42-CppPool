#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	try{
		Bureaucrat b1("b1", 3);
		RobotomyRequestForm pres1("robot");
		b1.signForm(pres1);
		pres1.execute(b1);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}