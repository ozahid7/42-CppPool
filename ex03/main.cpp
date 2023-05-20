#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	try{
		AForm *form;
		Intern f;
		Bureaucrat b1("b1", 150);
		form = f.makeForm("press", "tt");
		if (form)
		{
			b1.signForm(*form);
			b1.signForm(*form);
			b1.executeForm(*form);
		}
		form = f.makeForm("shru", "ShrubberyCreationForm");
		if (form)
		{
		b1.signForm(*form);
		b1.executeForm(*form);
		}
		Bureaucrat b2("b2", 2);
		form = f.makeForm("robot", "RobotomyRequestForm");
		if (form)
		{
		b2.signForm(*form);
		b2.signForm(*form);
		b2.executeForm(*form);
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}