#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm{
public:
	AForm();
	~AForm();
	AForm(std::string name, int grade, int exec);
	AForm(AForm &other);

	AForm &operator=(AForm const &other);

	class GradeTooHighException: public std::exception{
	public:
		const char *what() const throw(){
			return ("Grade to High");
		}
	};
	class GradeTooLowException: public std::exception{
	public:
		const char *what() const throw(){
			return ("Grade to Low");
		}
	};
	const std::string	get_form_name();
	bool				is_signed();
	void				set_is_signed(bool is);
	int					get_grade_sign();
	int					get_execute_it();
	void				beSigned(Bureaucrat &bureau);

private:
	const std::string	_form_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_execute_it;
};

std::ostream &operator<<(std::ostream &stream, AForm &form);

#endif