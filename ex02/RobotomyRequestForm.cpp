#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm::AForm(name, 72, 45)
{
	_target = name;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	(void)other;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!is_signed())
		throw std::invalid_argument("is not signed");
	else if(executor.getgrade() > get_grade_exec())
		throw GradeTooLowException();
	else{
		std::srand((unsigned int)(std::time(nullptr)));
		int nb = std::rand();
		if (nb % 2 == 1){
			std::cout<<_target + "_Robot"<<" has been robotomized "<<std::endl;
		}else{
			std::cout<<" The robotomy failed "<<std::endl;
	}
	}
}
