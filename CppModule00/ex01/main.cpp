#include "Contact.hpp"
#include "PhoneBook.hpp"

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

std::string	print_interface()
{
	std::string buffer;

	std::cout<<"*************************************************************"<<std::endl;
	std::cout<<"*                   MY AWESOME PHONE BOOK                   *"<<std::endl;
	std::cout<<"*************************************************************"<<std::endl;
	std::cout<<"______________Choose One Of The Commands Bellow______________"<<std::endl;
	std::cout << std::endl;
	std::cout<<"          (Add)           (Search)           (Exit)          "<<std::endl;
	std::cout << std::endl;
	while (buffer.empty()){
		std::cout<<"PhoneBook... :$ ";
		buffer = get_next_line();
	}
	return buffer;
}


int main()
{
	Contact contact;
	Contact tmp;
	PhoneBook phonebook;
	std::string buffer;
	std::stringstream str;

	
	while (1){
	buffer = print_interface();
	if (!buffer.compare("EXIT") || !buffer.compare("exit"))
		exit (0);
	if (!buffer.compare("ADD") || !buffer.compare("add"))
		phonebook.addtophonebook();
	if (!buffer.compare("SEARCH") || !buffer.compare("search"))
		phonebook.search();
	}
}