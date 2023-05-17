#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int sign_grade, int exec_grade): AForm::AForm(name, sign_grade, exec_grade)
{
	std::cout<<name<<" has been pardoned by Zaphod Beeblebrox "<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	(void) other;
	return (*this);
}
