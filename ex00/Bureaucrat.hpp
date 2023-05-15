#ifndef BERAUCRAT_HPP
# define BERAUCRAT_HPP


#include <iostream>

class Bureaucrat{
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat &other);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &other);
	std::ostream &operator<<(std::ostream &stream, Bureaucrat const &other);

	class				GradeTooHighException: public std::exception{
		public:
		const char *what() const throw (){
			return ("Grade is to high");
		}
	};
	class				GradeTooLowException: public std::exception{
		public:
		const char *what() const throw(){
			return ("Grade is too low");
		}
	};
	const std::string	getname();
	int					getgrade();
	void				incrementgrade();
	void				decrementgrade();

private:
	std::string const	_name;
	int					_grade;
};

#endif