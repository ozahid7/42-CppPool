#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"



class PhoneBook
{
private:
	Contact contacts[8];
public:
	void addtophonebook();
	Contact  search();
};


#endif