#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string respect(std::string str)
{
	size_t width = 10;
	size_t spaces;

	if (str.length() > 10)
	{
		str.insert(9, 1, '.');
	}
	else if(str.length() < 10)
	{
		spaces = width - str.length();
		str.insert(0, spaces, ' ');
	}
	return str;
}


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
	std::string fname;
	std::string lname;
	std::string nname;

	std::cout<<std::endl;
	for (int i = 0; i < this->index; i++)
	{
		fname = this->contacts[i].getfname();
		fname = respect(fname).substr(0, 10);
		lname = this->contacts[i].getlname();
		lname = respect(lname).substr(0, 10);
		nname = this->contacts[i].getnname();
		nname = respect(nname).substr(0, 10);
		std::cout<<"         "<<i<<"|"<<fname <<"|"<<lname<<"|"<<nname<<std::endl;
	}
	std::cout<<std::endl;
}

void  PhoneBook::search(){
	std::string	buffer;
	char	*end_ptr = NULL;
	long int	index;
	display_contact();
	while (buffer.empty()){
		std::cout<<"Enter Index... :$ ";
		buffer = get_next_line();
		index = std::strtol(buffer.c_str(), &end_ptr, 10);
		if (*end_ptr || index < 0 || index >= this->index)
			std::cout<<"Invalid Input"<<std::endl;
		else
			this->contacts[index].printcontact(index);
	}
}





