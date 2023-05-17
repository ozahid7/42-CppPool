#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
{
	*this = other;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int sign_grade, int execgrade): AForm::AForm(name , sign_grade, execgrade)
{
	std::ofstream file(name + "_shrubbery");

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
				"                       *******\n";
	}
	else
		std::cout<<"File Error"<<std::endl;

	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	(void) other;
	return *this;
}
