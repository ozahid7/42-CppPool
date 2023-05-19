#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	(void) name;
	(void) target;
	// std::string forms[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	// if (!forms[0].compare(name))
	return ();

}
