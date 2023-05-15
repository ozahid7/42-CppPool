#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout<<"Default constructor is called"<<std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
{
	std::cout<<"copy constructor is called"<<std::endl;
	*this = other;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout<<"Paramitrised constructor is called"<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
 	std::cout<<"Destructor is called"<<std::endl;

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout<<"equal operator overload is called"<<std::endl;
	this->_grade = other._grade;
	return (*this);
}

std::ostream &Bureaucrat::operator<<(std::ostream &stream, Bureaucrat const &other)
{
	stream << other.
	return stream;
}

const std::string Bureaucrat::getname()
{
	return _name;
}

int Bureaucrat::getgrade()
{
	return _grade;
}

void Bureaucrat::incrementgrade()
{
	if (_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementgrade()
{
	if(_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

