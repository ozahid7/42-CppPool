#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *d = new Cat;

	d->makeSound();

	delete d;
	return 0;
}