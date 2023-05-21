#include "Brain.hpp"

Brain::Brain(){
	std::cout<<"Brain Default Constructor Called"<<std::endl;
}

Brain::~Brain(){
	std::cout<<"Brain Destructor Called"<<std::endl;
}

Brain::Brain(Brain const &other){
	std::cout<<"Brain Copy Constructor Called"<<std::endl;
	*this = other;
}

Brain &Brain::operator=(Brain const &other){
	std::cout<<"Brain Operator Overload Called"<<std::endl;
	for (int i = 0; i < 100; i++){
		_ideas[i] = other._ideas[i];
	}
	(void)other;
	return *this;
}

std::string Brain::getidea(int i)
{
	return _ideas[i];
}

void Brain::setidea(std::string idea, int i)
{
	_ideas[i] = idea;
}
