#include "PmergeMe.hpp"


int main(int ac, char **av){
	PmergeMe obj;
	try{
		obj.pair_me(ac, av);
		iterator it;
		it = obj.get_vec().begin();
		size_t size = 0;
		obj.set_vec(obj.sort_pairs(size));
		for (; it < obj.get_vec().end(); it++){
			std::cout<<it->first<<" "<<it->second<<std::endl;
		}
		std::cout<<obj.get_mr_lonly()<<std::endl;
	}catch(std::exception(&e)){
		std::cout<<e.what()<<std::endl;
	}
}