#include "Zombie.hpp"

int main (){

	Zombie* zombie;

	zombie = zombieHorde(4, "zombie");
	for (int i = 0; i < 4; i++)
		zombie[i].announce();
	delete[] zombie;
}