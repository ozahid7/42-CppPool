#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
class Contact
{
private:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	dark;
public:
	void	setfname(std::string str);
	void	setdark(std::string str);
	void	setlname(std::string str);
	void	setnname(std::string str);
	void	setphonenum(std::string str);

	std::string getfname();
	std::string getlname();
	std::string getdark();
	std::string getnname();
	std::string getphonenum();
	void	printcontact(long int index);

};
#endif