#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
public:
	Brain();
	~Brain();
	Brain(Brain const &other);

	Brain &operator=(Brain const &other);
	std::string getidea(int i);
	void		setidea(std::string idea, int i);
	
private:
	std::string _ideas[100];
};

#endif