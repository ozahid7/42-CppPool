#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("name"), _grade(150)
{
	// std::cout<<"Default constructor is called"<<std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
{
	// std::cout<<"copy constructor is called"<<std::endl;
	*this = other;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	// std::cout<<"Paramitrised constructor is called"<<std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
 	// std::cout<<"Destructor is called"<<std::endl;

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	// std::cout<<"equal operator overload is called"<<std::endl;
	this->_grade = other._grade;
	return (*this);
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

std::ostream &operator<<(std::ostream &stream, Bureaucrat &other)
{
	stream << other.getname()<< "  bureaucrat grade " << other.getgrade();
	return stream;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is to high");
}

