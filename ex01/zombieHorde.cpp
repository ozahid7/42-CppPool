#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
	Zombie* zombie = new Zombie[N];
	for (int i = 0; i < N; i++){
		zombie[i].setname(name + std::to_string(i+1));
	}
	return (zombie);
};