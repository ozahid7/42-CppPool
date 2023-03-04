#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string get_next_line()
{
	std::string buffer;

	std::getline(std::cin, buffer);
	if (std::cin.fail())
		exit(1);
	return buffer;
}

void	PhoneBook::addtophonebook(){
	Contact contact;

	while (contact.getfname().empty()){
		std::cout << "Enter Your First Name : ";
		contact.setfname(get_next_line());
	}
	while (contact.getlname().empty()){
	std::cout << "Enter Your Last Name : ";
	contact.setlname(get_next_line());
	}
	while (contact.getnname().empty()){
	std::cout << "Enter Your Nick Name : ";
	contact.setnname(get_next_line());
	}
	while (contact.getphonenum().empty()){
	std::cout << "Enter Your Phone Number : ";
	contact.setphonenum(get_next_line());
	}
	this->index++;
	if (this->index == 8)
		this->index = 0;
}

Contact  PhoneBook::search(){
	return this->contacts[this->index];
}





