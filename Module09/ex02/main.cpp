#include "PmergeMe.hpp"


int main(int ac, char **av){
		PmergeMe obj;
	try{
		ConVec vec;
		std::clock_t start = clock();
		obj.pair_me(ac, av);
		iterator it;
		vec = obj.get_vec();
		if (vec.size() > 1)	
			vec = obj.sort_pairs();
		obj.separate_pair();
		obj.binary_insert();
		obj.show("vector", start);
	}catch(std::exception(&e)){
		std::cout<<e.what()<<std::endl;
	}
}