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

	contact.setfname("oussama");
	std::cout<<contact.getfname();

}