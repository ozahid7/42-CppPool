#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string name, int sign_grade, int exec_grade): AForm::AForm(name, sign_grade, exec_grade)
{
	std::srand((unsigned int)(std::time(nullptr)));
	int nb = std::rand();
	if (nb % 2 == 1){
		std::cout<<name<<" has been robotomized "<<std::endl;
	}else{
		std::cout<<" The robotomy failed "<<std::endl;
	}
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
