#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	try{
		AForm *form;
		Intern f;
		Bureaucrat b1("b1", 3);
		form = f.makeForm("", "");
		b1.executeForm(*form);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}