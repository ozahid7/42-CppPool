#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#include <iostream>

class WrongAnimal{
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &other);
	~WrongAnimal();

	WrongAnimal &operator=(WrongAnimal const &other);

	std::string getType() const;
	void	makeSound() const;
	
protected:
	std::string type;

};

#endif