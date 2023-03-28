#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
public:
	Animal();
	Animal(Animal const &other);
	~Animal();

	Animal &operator=(Animal const &other);
	
	void makeSound();
protected:
	std::string type;

};

#endif