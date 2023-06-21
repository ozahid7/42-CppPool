#include "PmergeMe.hpp"


int main(int ac, char **av){
	PmergeMe obj;
	try{
		ConVec vec;
		obj.pair_me(ac, av);
		iterator it;
		vec = obj.get_vec();
		it = vec.begin();
		// size_t size = 0;
		vec = obj.sort_pairs();
		for (it = vec.begin(); it < vec.end(); it++)
		{
			std::cout<<it->first<<" "<<it->second<<std::endl;
		}
		// obj.separate_pair();
		// obj.binary_insert();
		// for (size_t i = 0; i < obj.get_main().size(); i++){
		// 	std::cout<<obj.get_main()[i]<<std::endl;
		// }
		// std::cout<<obj.get_mr_lonly()<<std::endl;
	}catch(std::exception(&e)){
		std::cout<<e.what()<<std::endl;
	}
}