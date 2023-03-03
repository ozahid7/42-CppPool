#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{

	// char	buffer[200];
	
	// std::cout<<"Enter Command:";
	// std::cin>>buffer;
	// std::string command;
	// command = buffer;

	// if (!command.compare("EXIT") || !command.compare("exit"))
	// 	quit();
	// if (!command.compare("ADD") || !command.compare("add"))
	// 	add ();
	// if (!command.compare("SEARCH") || !command.compare("search"))
	// 	search();
	Contact contact;
	Contact c;
	PhoneBook phonebook;
	contact.setfname("oussama");
	std::cout<<contact.getfname();
	contact.setlname("zahid");
	std::cout<<contact.getlname();
	contact.setnname("ozahid");
	std::cout<<contact.getnname();
	contact.setphonenum("021456433");
	std::cout<<contact.getphonenum();

	phonebook.setcontact(contact, 0);
	c = phonebook.getcontacts();
	std::cout<<"_____"<<c.getfname();


}