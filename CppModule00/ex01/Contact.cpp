#include "Contact.hpp"

// void    quit(void){
//     exit(0);
// }

// void    search(void){
// 	Contact contact;
// }

// void    add(void){
// 	Contact contact;
// 	std::cout<< "Enter your FirstName : ";
// 	std::cin>>contact.firstname;
// 	std::cout<< "Enter your LastName : ";
// 	std::cin>>contact.lastname;
// 	std::cout<< "Enter your NickName : ";
// 	std::cin>>contact.nickname;
// 	std::cout<< "Enter your PhoneNumber : ";
// 	std::cin>>contact.phonenumber;
// }

void	Contact::setfname(std::string str){
		firstname = str;
}
void	Contact::setlname(std::string str){
	nickname = str;
}
void	Contact::setnname(std::string str){
	firstname = str;
}
void	Contact::setphonenum(std::string str){
	firstname = str;
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