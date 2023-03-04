#include "Contact.hpp"

void	Contact::setfname(std::string str){
		firstname = str;
}
void	Contact::setlname(std::string str){
	lastname = str;
}
void	Contact::setnname(std::string str){
	nickname = str;
}
void	Contact::setphonenum(std::string str){
	phonenumber = str;
}

std::string Contact::getfname(){
	return firstname;
}
std::string Contact::getlname(){
	return lastname;
}
std::string Contact::getnname(){
	return nickname;
}
std::string Contact::getphonenum(){
	return phonenumber;
}

void	Contact::printcontact(long int index){
	std::cout<<"Index     : "<<index<<std::endl;
	std::cout<<"FirstName : "<<firstname<<std::endl;
	std::cout<<"LastName  : "<<lastname<<std::endl;
	std::cout<<"NickName  : "<<nickname<<std::endl;
}
