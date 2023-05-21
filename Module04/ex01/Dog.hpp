#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
public:
	Dog();
	Dog(Dog const &other);
	~Dog();

	Dog &operator=(Dog const &other);

	std::string getType() const;
	void	makeSound() const;
private:
	std::string _type;
	Brain*		_brain;
};

#endif