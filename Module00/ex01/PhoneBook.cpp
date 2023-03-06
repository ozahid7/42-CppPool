#include "PhoneBook.hpp"
#include "Contact.hpp"

int	check_buffer(std::string buffer)
{
	size_t j = 0;
	size_t i;
	if (buffer.length() == 0)
		return 1;
	else{
		for (i = 0 ; i < buffer.length(); i++){
			if (buffer[i] == ' ' || buffer[i] == '\t')
				j++;
		}
		if (i == j)
			return 1;
	}
	return 0;
}

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

void	PhoneBook::setindex(){
	this->index = 0;
	this->size = 0;
}

void	PhoneBook::setcontact(Contact contact){
	this->contacts[this->index] = contact;
}

void	PhoneBook::addtophonebook(){
	Contact contact;
	std::string buffer;

	while (contact.getfname().empty()){
		std::cout << "Enter Your First Name : ";
		buffer = get_next_line();
		if (!check_buffer(buffer))
			contact.setfname(buffer);
	}
	while (contact.getlname().empty()){
	std::cout << "Enter Your Last Name : ";
		buffer = get_next_line();
		if (!check_buffer(buffer))
			contact.setlname(buffer);
	}
	while (contact.getnname().empty()){
		std::cout << "Enter Your Nick Name : ";
		buffer = get_next_line();
		if (!check_buffer(buffer))
			contact.setnname(buffer);
	}
	while (contact.getphonenum().empty()){
		std::cout << "Enter Your Phone Number : ";
		buffer = get_next_line();
		if (!check_buffer(buffer))
			contact.setphonenum(buffer);
	}
	while (contact.getdark().empty()){
		std::cout << "Enter Your Darkest secret : ";
		buffer = get_next_line();
		if (!check_buffer(buffer))
			contact.setdark(buffer);
	}
	this->setcontact(contact);
	if (size < 8) size++;
	if (this->index == 7)
		this->index = 0;
	else
		this->index++;
}

void	PhoneBook::display_contact(){
	std::string fname;
	std::string lname;
	std::string nname;

	std::cout<<std::endl;
	std::cout<<respect("Index")<<"|"<<respect("FirstName")<<"|"<<respect("LastName")<<"|"<<respect("NickName")<<"|"<<std::endl;
	std::cout<<std::string().insert(0, 43, '-')<<std::endl;
	for (int i = 0; i < this->size; i++)
	{
		fname = this->contacts[i].getfname();
		fname = respect(fname).substr(0, 10);
		lname = this->contacts[i].getlname();
		lname = respect(lname).substr(0, 10);
		nname = this->contacts[i].getnname();
		nname = respect(nname).substr(0, 10);
		std::cout<<"         "<<i<<"|"<<fname <<"|"<<lname<<"|"<<nname<<"|"<<std::endl;
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
		if (*end_ptr || index < 0 || index >= this->size)
			std::cout<<"Invalid Input"<<std::endl;
		else
			this->contacts[index].printcontact(index);
	}
}





