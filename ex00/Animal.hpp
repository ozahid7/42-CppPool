#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
public:
	Animal();
	Animal(Animal const &other);
	virtual ~Animal();

	Animal &operator=(Animal const &other);
	
	virtual void makeSound() const;
	virtual std::string getType() const;
protected:
	std::string type;

};

#endif