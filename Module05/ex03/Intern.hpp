#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
public:
	Intern();
	~Intern();
	Intern(Intern const &other);


	Intern &operator=(Intern const &other);
	AForm 	*makeForm(std::string name, std::string targert);

private:
	AForm *forms[3];
};

#endif