#ifndef PRESIDENTIALPARDONFOM_HPP
#define PRESIDENTIALPARDONFOM_HPP


#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string name, int sign_grade, int exec_grade);
	PresidentialPardonForm(PresidentialPardonForm &other);


	PresidentialPardonForm &operator=(PresidentialPardonForm &other);

private:
};

#endif