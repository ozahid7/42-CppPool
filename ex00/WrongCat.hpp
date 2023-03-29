#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
public:
	WrongCat();
	WrongCat(WrongCat const &other);
	~WrongCat();

	WrongCat &operator=(WrongCat const &other);
	
	std::string getType() const;
	void	makeSound() const;
private:
	std::string _type;

};

#endif