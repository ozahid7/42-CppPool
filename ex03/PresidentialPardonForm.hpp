#ifndef PRESIDENTIALPARDONFOM_HPP
#define PRESIDENTIALPARDONFOM_HPP


#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string name);
	PresidentialPardonForm(PresidentialPardonForm &other);


	PresidentialPardonForm &operator=(PresidentialPardonForm &other);

	void	execute (Bureaucrat const & executor)  const;

private:
	std::string _target;
};

#endif