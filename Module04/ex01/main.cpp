#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* j = new Dog();
	// const Animal* c = new Cat();
	// delete j;
	// delete c;

	// int i;

	// Animal *animals[20];

	// for(i = 0; i < 20; i++){
	// 	if (i < 10){
	// 		animals[i] = new Cat;
	// 	}
	// 	if (i > 9){
	// 		animals[i] = new Dog;
	// 	}
	// }
	// for (i = 0; i < 20; i++){
	// 	delete animals[i];
	// }
	// Cat basic;
	// {
	// 	Cat tmp = basic;
	// }

	Cat a;
	(a.getbrain())->setidea("-------idea0-------", 0);
	Cat b(a);

	std::cout<<(b.getbrain())->getidea(0)<<std::endl;

	return 0;
}