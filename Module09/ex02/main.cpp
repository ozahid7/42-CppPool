#include "PmergeMe.hpp"

void sort_vec(int ac, char **av){
	PmergeMe obj;
	ConVec vec;
	std::clock_t start = clock();
	obj.v_pair_me(ac, av);
	vec = obj.v_get_vec();
	if (vec.size() > 1){	
		vec = obj.v_sort_pairs();
		obj.v_separate_pair();
		obj.v_binary_insert();
	}
	obj.v_show("vector", start);
}

void sort_dec(int ac, char **av){
	PmergeMe obj;
	Condec vec;
	std::clock_t start = clock();
	obj.d_pair_me(ac, av);
	vec = obj.d_get_vec();
	if (vec.size() > 1){
		vec = obj.d_sort_pairs();
		obj.d_separate_pair();
		obj.d_binary_insert();
	}
	obj.d_show("deque", start);
}

int main(int ac, char **av){
	PmergeMe obj;
	try{
		sort_vec(ac, av);
		std::cout<<std::endl;
		sort_dec(ac, av);
	}catch(std::exception(&e)){
		std::cout<<e.what()<<std::endl;
	}
}