#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern: public AForm{
public:
	Intern();
	~Intern();
	Intern(Intern const &other);


	Intern &operator=(Intern const &other);
	AForm 	*makeForm(std::string name, std::string targert);

private:
};

#endif