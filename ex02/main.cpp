#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *d = new Cat;
	Animal a;
	std::cout<<d->getType()<<std::endl;
	d->makeSound();

	delete d;
	return 0;
}