#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	_target = "default_Robotomy";
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
	_target = other._target;
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

AForm *RobotomyRequestForm::get_me(std::string name) const
{
	RobotomyRequestForm *robot = new RobotomyRequestForm(name);
	return (robot);
}