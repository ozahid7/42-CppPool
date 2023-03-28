#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

class WrongCat{
public:
	WrongCat();
	WrongCat(WrongCat const &other);
	~WrongCat();

	WrongCat &operator=(WrongCat const &other);
	
	std::string getType();
	void	makeSound();
private:
	std::string _type;

};

#endif