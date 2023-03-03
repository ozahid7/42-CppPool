#include "PhoneBook.hpp"
#include "Contact.hpp"

void    quit(void){
    exit(0);
}

void    search(void){

}



void	PhoneBook::setcontact(Contact contact, int index){
	contacts[index] = contact;
}
Contact  PhoneBook::getcontacts(){
	return this->contacts[0];
}





