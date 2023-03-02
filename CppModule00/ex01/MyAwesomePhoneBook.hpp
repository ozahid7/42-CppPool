#ifndef MYAWESOMEPHONEBOOK_HPP
#define MYAWESOMEPHONEBOOK_HPP

#include <iostream>

class Contact
{
private:
	char	*firstname;
	char	*lastname;
	char	*nickname;
	int		phonenumber;
	int		index;

};

class PhoneBook
{
private:
	Contact contacts[8];
};


#endif