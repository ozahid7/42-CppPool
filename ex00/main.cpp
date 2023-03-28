#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();

	Animal *a = new Dog;
	a->makeSound();
	//const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	//std::cout << i->getType() << " " << std::endl;
	//i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();
return 0;
}