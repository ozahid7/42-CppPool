#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();

	const Animal* i = new Cat();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	WrongAnimal *a = new WrongCat;
	
	std::cout<<a->getType()<< " " <<std::endl;
	a->makeSound();
	

	delete meta;
	delete j;
	delete a;
	delete i;
return 0;
}