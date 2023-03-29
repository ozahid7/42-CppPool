#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	int i;
	Animal *animals[20];

	for(i = 0; i < 20; i++){
		if (i < 10){
			animals[i] = new Cat;
		}
		if (i > 9){
			animals[i] = new Dog;
		}
	}
	for (i = 0; i < 20; i++){
		delete animals[i];
	}

	return 0;
}