#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	try{
		Bureaucrat b2("b2", 150);
		RobotomyRequestForm pres1("robot");
		b2.executeForm(pres1);
		Bureaucrat b1("b1", 2);
		PresidentialPardonForm p("pppp");
		b1.signForm(p);
		b1.executeForm(p);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}