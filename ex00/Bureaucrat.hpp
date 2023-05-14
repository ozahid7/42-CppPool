#ifndef BERAUCRAT_HPP
# define BERAUCRAT_HPP


#include <iostream>

class Bureaucrat{
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &other);
private:
	std::string const	name;
	int					grade;
	class				GradeTooHighException: std::exception{
		
	};
	class				GradeTooLowException: std::exception{
		
	};
	const std::string	getname();
	const int			getgrade();
	void				incrementgrade();
	void				decrementgrade();
};

#endif