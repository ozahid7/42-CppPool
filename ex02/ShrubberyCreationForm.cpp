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
	std::ofstream file("target_shrubbery");

	if (file.is_open()){
		file <<         "			/&& &&  & && \n "
				     "   		&///&//|& ()|/ @ \n"
				    "   		&///(/&/&||/& /_/)_&/_& \n"
				    "  	 &_//_&&_// |& |&&/&__%_/_&& \n"
				  "  	 &_//_&&_// |& |&&/&__%_/_& && \n"
				"   	&&   && & &| &| /& & % ()& /&& \n "
				 "      ()&_---()&//&//|&&-&&--%---()~ \n "
				    "     	 		||| \n"
				             "    			||| \n"
				             "    			||| \n"
				            "     			||| \n"
				       " 			, -=-~  .-^-=- \n";
	}

	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	(void) other;
	return *this;
}
