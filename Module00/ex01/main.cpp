#include "Contact.hpp"
#include "PhoneBook.hpp"

void	print_head(){
	std::cout<<"*************************************************************"<<std::endl;
	std::cout<<"*                   MY AWESOME PHONE BOOK                   *"<<std::endl;
	std::cout<<"*************************************************************"<<std::endl;
	std::cout<<"______________Choose One Of The Commands Bellow______________"<<std::endl;
	std::cout << std::endl;
	std::cout<<"          (ADD)           (SEARCH)           (EXIT)          "<<std::endl;
	std::cout << std::endl;
}

std::string	print_interface()
{
	std::string buffer;
	while (buffer.empty()){
		std::cout<<"PhoneBook... :$ ";
		buffer = get_next_line();
	}
	return buffer;
}


int main()
{	
	PhoneBook phonebook;
	std::string buffer;

	phonebook.setindex();
	print_head();
	while (1){
	buffer = print_interface();
	if (!buffer.compare("EXIT"))
		exit (0);
	else if (!buffer.compare("ADD"))
		phonebook.addtophonebook();
	else if (!buffer.compare("SEARCH"))
		phonebook.search();
	else
		std::cout<<"Invalid Input Choose one of this commands: (ADD), (SEARCH), (EXIT)"<<std::endl;
	}
	return 0;
}