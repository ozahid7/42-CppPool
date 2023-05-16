#ifndef SHRUBBERYGREATIONFORM_HPP
#define SHRUBBERYGREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	ShrubberyCreationForm(std::string name, int sign_grade, int execgrade);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);


private:
};

#endif