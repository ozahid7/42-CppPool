#include "Zombie.hpp"

int main (){

	Zombie* zombie = NULL;
	int	N = 4;
	if (N > 0){
	zombie = zombieHorde(N, "zombie");
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete[] zombie;}
	return 0;
}