#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{

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
	(void) other;
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
