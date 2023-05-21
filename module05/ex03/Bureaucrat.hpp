#ifndef BERAUCRAT_HPP
# define BERAUCRAT_HPP


#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat{
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat &other);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &other);

	class				GradeTooHighException: public std::exception{
		public:
		const char *what() const throw ();
	};
	class				GradeTooLowException: public std::exception{
		public:
		const char *what() const throw();
	};
	const std::string	getname();
	int					getgrade() const;
	void				incrementgrade();
	void				decrementgrade();
	void				executeForm(AForm const & form);
	void				signForm(AForm &form);

private:
	std::string const	_name;
	int					_grade;
};

	std::ostream &operator<<(std::ostream &stream, Bureaucrat &other);

#endif