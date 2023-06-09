#include "Intern.hpp"

Intern::Intern()
{
	forms[0] = new PresidentialPardonForm();
	forms[1] = new RobotomyRequestForm();
	forms[2] = new ShrubberyCreationForm();
	
}

Intern::~Intern()
{
	// std::cout<<"destructor called "<< std::endl;
	delete forms[0];
	delete forms[1];
	delete forms[2];

}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void) other;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	try {
		std::string names[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
		for (int i = 0; i < 3; i++){
			if (!target.compare(names[i])){
				return (forms[i]->get_me(name));
			}
		}
		throw std::invalid_argument("Invalid Form");
	}catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (NULL);
}
