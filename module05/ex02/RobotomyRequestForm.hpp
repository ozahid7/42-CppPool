#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(RobotomyRequestForm &other);

	RobotomyRequestForm &operator=(RobotomyRequestForm &other);

	void	execute (Bureaucrat const & executor)  const;

private:
	std::string _target;
};

#endif