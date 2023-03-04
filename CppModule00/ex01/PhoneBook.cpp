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

void	PhoneBook::setcontact(Contact contact){
	this->contacts[this->index] = contact;
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
	this->setcontact(contact);
	this->index++;
	if (this->index == 7)
		this->index = 0;
}

void	PhoneBook::display_contact(){
	for (int i = 0; i < this->index; i++)
		std::cout<<i<<" | "<<this->contacts[i].getfname()<<" | "<<this->contacts[i].getlname()<<" | "<<this->contacts[i].getnname()<<std::endl;
}

void  PhoneBook::search(){
	std::string	buffer;
	char	*end_ptr = NULL;
	long int	index;
	display_contact();
	while (buffer.empty()){
		std::cout<<"Index... :$ ";
		buffer = get_next_line();
		index = std::strtol(buffer.c_str(), &end_ptr, 10);
		if (*end_ptr || index < 0 || index >= this->index)
			std::cout<<"Invalid Input"<<std::endl;
		else
			this->contacts[index].printcontact(index);
	}
}





