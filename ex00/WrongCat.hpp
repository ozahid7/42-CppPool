#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

class WrongCat{
public:
	WrongCat();
	WrongCat(WrongCat const &other);
	~WrongCat();

	WrongCat &operator=(WrongCat const &other);
	
protected:
	std::string type;

};

#endif