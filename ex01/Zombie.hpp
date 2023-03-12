#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie{
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setname(std::string name);
	std::string getname();
	void announce();
};

Zombie* zombieHorde( int N, std::string name);

#endif