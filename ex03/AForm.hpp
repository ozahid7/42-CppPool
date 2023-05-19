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
	std::string			get_form_name()const ;
	virtual void		execute (Bureaucrat const & executor)  const = 0;
	virtual AForm		*get_me() const = 0;
	bool				is_signed() const;
	void				set_is_signed(bool is);
	int					get_grade_sign() const;
	int					get_grade_exec() const;
	void				beSigned(Bureaucrat &bureau);

private:
	const std::string	_form_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_grade_exec;
};

std::ostream &operator<<(std::ostream &stream, AForm &form);

#endif