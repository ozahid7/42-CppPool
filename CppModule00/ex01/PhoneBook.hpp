#ifndef MYAWESOMEPHONEBOOK_HPP
#define MYAWESOMEPHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"



class PhoneBook
{
private:
	Contact contacts[8];
public:
	void setcontact(Contact, int index);
	Contact  getcontacts();
};


#endif