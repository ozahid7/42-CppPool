#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

std::string get_next_line();

class PhoneBook
{
private:
	Contact contacts[8];
public:
	int	index;
	void addtophonebook();
	Contact  search();
};


#endif