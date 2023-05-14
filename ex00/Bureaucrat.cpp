#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
{

}

Bureaucrat::~Bureaucrat()
{
	 
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	
}

const std::string Bureaucrat::getname()
{
	return name;
}

const int Bureaucrat::getgrade()
{
	return grade;
}

void Bureaucrat::incrementgrade()
{
	if (grade > 1)
		grade--;
	else
		throw "grade is les than 1";
}

void Bureaucrat::decrementgrade()
{
	if(grade < 150)
		grade++;
	else
		throw ;
}
