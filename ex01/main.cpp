#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const WrongAnimal* w = new WrongCat;
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << w->getType() << " " << std::endl;
	w->makeSound();


	delete meta;
	delete j;
	delete i;
	delete w;
return 0;
}