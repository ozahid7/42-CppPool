#include "Brain.hpp"

Brain::Brain(){
	std::cout<<"Brain Default Constructor Called"<<std::endl;
}

Brain::~Brain(){
	std::cout<<"Brain Destructor Called"<<std::endl;
}

Brain::Brain(Brain const &other){
	std::cout<<"Brain Copy Constructor Called"<<std::endl;
}

Brain &Brain::operator=(Brain const &other){
	std::cout<<"Brain Operator Overload Called"<<std::endl;
	*_ideas = *other._ideas;
	return *this;
}
