#ifndef SHRUBBERYGREATIONFORM_HPP
#define SHRUBBERYGREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	ShrubberyCreationForm(std::string name);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);

	void	execute (Bureaucrat const & executor) const;
	std::string get_target();
	

private:
	std::string			_target;
};

#endif