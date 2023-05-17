#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string name, int sign_grade, int exec_grade);
	RobotomyRequestForm(RobotomyRequestForm &other);

	RobotomyRequestForm &operator=(RobotomyRequestForm &other);

	static int	get_nb();

private:
	static int	_nb;
};

#endif