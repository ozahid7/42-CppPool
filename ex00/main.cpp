#include "Zombie.hpp"

int main ()
{
	Zombie zombie("Foo");
	zombie.announce();
	Zombie* newzombie = newZombie("newzombie");
	newzombie->announce();
	randomChump("random");
	delete(newzombie);
}