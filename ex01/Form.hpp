#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form{
public:
	Form();
	~Form();
	Form(std::string name, int grade);
	Form(Form &other);

	Form &operator=(Form const &other);

	class GradeTooHighException: public std::exception{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException: public std::exception{
	public:
		const char *what() const throw();
	};
	const std::string	get_form_name();
	bool				is_signed();
	const int			get_form_grade();

private:
	const std::string	_form_name;
	bool				_signed;
	int					_form_grade;
};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif