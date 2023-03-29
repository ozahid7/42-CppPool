#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Cat cat;
	cat.getbrain().setidea("tfo", 0);
	std::cout<<"cat"<<cat.getbrain().getidea(0);
	Cat cat1(cat);
	std::cout<<"cat1"<<cat1.getbrain().getidea(0);
	cat.getbrain().setidea("tfo2", 0);
	std::cout<<"cat1"<<cat1.getbrain().getidea(0);


	// const Animal* j = new Dog();
	// const Animal* c = new Cat();
	// delete j;
	// delete c;

	// int i;

	// Brain b;
	// b.setidea("b", 0);
	// std::cout<<"b = "<<b.getidea(0)<<std::endl;
	// Brain a(b);
	// b.setidea("a", 0);
	// std::cout<<"b = "<<b.getidea(0)<<std::endl;
	// std::cout<<"a = "<<a.getidea(0)<<std::endl;

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

	return 0;
}