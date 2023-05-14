#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
public:
	Cat();
	Cat(Cat const &other);
	~Cat();

	Cat &operator=(Cat const &other);

	std::string getType() const;
	void	makeSound() const;
	Brain	*getbrain();
private:
	std::string _type;
	Brain*		_brain;

};

#endif