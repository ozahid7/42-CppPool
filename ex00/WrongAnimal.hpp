#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &other);
	~WrongAnimal();

	WrongAnimal &operator=(WrongAnimal const &other);

	std::string getType();
	void	makeSound();
	
protected:
	std::string type;

};

#endif