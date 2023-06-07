#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	_target = "default_Presidential";
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm::AForm(name, 25, 5)
{
	_target = name;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	_target = other._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!is_signed())
		throw std::invalid_argument("is not signed");
	else if(executor.getgrade() > get_grade_exec())
		throw GradeTooLowException();
	else
		std::cout<<_target + "_Presidential"<<" has been pardoned by Zaphod Beeblebrox "<<std::endl;
}

AForm *PresidentialPardonForm::get_me(std::string name) const
{
	PresidentialPardonForm *pres;

	pres = new PresidentialPardonForm(name);
	return (pres);
}