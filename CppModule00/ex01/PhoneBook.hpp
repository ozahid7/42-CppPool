#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include "Contact.hpp"

std::string get_next_line();

class PhoneBook
{
private:
	Contact contacts[8];
	int		index;
public:
	void	addtophonebook();
	void	setcontact(Contact contact);
	void	search();
};


#endif