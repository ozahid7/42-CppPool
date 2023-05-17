#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
{
	*this = other;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm::AForm(name , 145, 137)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	(void) other;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if(!is_signed() || executor.getgrade() < get_grade_exec()){
		throw GradeTooLowException();
	}else{
		std::ofstream file( _target + "_shrubbery");
		if (file.is_open()){
			file << "                          *\n"
					"                        *****\n"
					"                      *********\n"
					"                    **************\n"
					"                 ********************\n"
					"              **************************\n"
					"               ************************\n "
					"                 *******************\n"
					"                    *************\n"
					"                         ***\n"
					"                         ***\n"
					"                         ***\n"
					"                         ***\n"
					"                       *******\n";}
		else
			throw std::invalid_argument("file error");
	}
}

std::string ShrubberyCreationForm::get_target()
{
	return _target;
}
