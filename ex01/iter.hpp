#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void print_msg(T *str){
	str++;
	std::cout<<str<<std::endl;
}

template<typename T>
void iter(T* tab, int len, void (*func)(T *)){
	for (int i = 0; i < len; i++){
		func(tab);
	}
}

// template<typename T>
// void iter1(T* tab, int len, void (*func)(T const &x)){
// 	for (int i = 0; i < len; i++){
// 		func(tab[i]);
// 	}
// }

#endif