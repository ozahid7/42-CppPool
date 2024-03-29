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
	int		size;
public:
	void	addtophonebook();
	void	setindex();
	void	display_contact();
	void	setcontact(Contact contact);
	void	search();
	
};


#endif