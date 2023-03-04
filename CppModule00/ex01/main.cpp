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


#include <sstream>
#include <vector>
int main()
{
	Contact contact;
	Contact tmp;
	PhoneBook phonebook;
	std::string buffer;

	std::cout << "Enter Command : ";
	std::getline(std::cin, buffer);
	if (!buffer.compare("EXIT") || !buffer.compare("exit"))
		exit (0);
	if (!buffer.compare("ADD") || !buffer.compare("add"))
	{
		
	}

	if (!buffer.compare("SEARCH") || !buffer.compare("search"))
		phonebook.search();
}